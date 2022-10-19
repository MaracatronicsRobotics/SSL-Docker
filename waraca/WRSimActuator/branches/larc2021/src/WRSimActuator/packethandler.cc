/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of WRSimActuator project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

#include "packethandler.hh"
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QNetworkDatagram>
#include <iostream>
#include <3rdparty/protobuf/ssl_simulation_robot_control.pb.h>
#include <WRSimActuator/utils/wrtimer.hh>
#include <WRSimActuator/utils/color.hh>

PacketHandler::PacketHandler(const QString& name) : Actuator(name) {
    // Sets initial values to 0 or -1
    for(int i=0; i<MAXTEAMNUMBER; i++) {
        for(int j=0; j<MAXPLAYERNUMBER; j++) {
            _vx[i][j]            = 0.0;
            _vy[i][j]            = 0.0;
            _vtheta[i][j]        = 0.0;
            _kickSpeed[i][j]     = 0.0;
            _chipKickSpeed[i][j] = 0.0;
            _dribbler[i][j]      = false;

            _isPlayerUpdated[i][j] = false;
        }
    }

    // set running and enabled by default
    _running = true;
    _loopTime = 1000;
}

void PacketHandler::run() {
    // Controls the packet loop time
    WRTimer t;
    while(isRunning())	{

        // Loop
        t.start();
        if(isConnected()) {

            // Check witch players were updated and send the packet to them
            for(int i=0; i<MAXTEAMNUMBER; i++) {
                for(int j=0; j<MAXPLAYERNUMBER; j++) {

                    // If was updated, send player packet
                    _playersInfo.lock();
                    if(_isPlayerUpdated[i][j]){
                        int teamNum = i;
                        int playerNum = j;

                        RobotControl robotControl;
                        RobotCommand *robotCommand = robotControl.add_robot_commands();
                        robotCommand->set_id(playerNum);

                        RobotMoveCommand *moveCommand = robotCommand->mutable_move_command();
                        MoveLocalVelocity *moveVelocity = moveCommand->mutable_local_velocity();
                        moveVelocity->set_left(_vx[teamNum][playerNum]);
                        moveVelocity->set_forward(_vy[teamNum][playerNum]);
                        moveVelocity->set_angular(_vtheta[teamNum][playerNum]);

                        float kickSpeed = _kickSpeed[teamNum][playerNum];
                        float chipKickSpeed = _chipKickSpeed[teamNum][playerNum];

                        robotCommand->set_kick_speed(sqrt(kickSpeed * kickSpeed + chipKickSpeed * chipKickSpeed));
                        robotCommand->set_kick_angle(tan(chipKickSpeed/kickSpeed));
                        robotCommand->set_dribbler_speed(_dribbler[teamNum][playerNum]);

                        // Sends the packet
                        QByteArray array;
                        array.resize(robotControl.ByteSizeLong());
                        robotControl.SerializeToArray(array.data(), array.size());

                        if(_socket.writeDatagram(array) == -1)
                            std::cout << "[WRSimActuator] Failed to write to socket: " << _socket.errorString().toStdString() << std::endl;

                        //Reset old updated players to outdated
                        markPlayersAsOutdated(teamNum, playerNum);
                    }
                    _playersInfo.unlock();

                }
            }

        }
        t.stop();

        // Thread loop time control
        if(isRunning()) {
            long rest = _loopTime - t.timemsec();
            if(rest >= 0)
                msleep(rest);
            else
                std::cout << "[TIMER OVEREXTENDED] " << " PacketHandler for " <<  -rest  << " ms.\n";
        }
    }

}

void PacketHandler::setLoopFrequency(int hz) {
    if(hz!=0)
        _loopTime = 1000/hz;
}

bool PacketHandler::isRunning() {
    bool result;
    _mutexRunning.lock();
    result = _running;
    _mutexRunning.unlock();
    return result;
}

void PacketHandler::stopRunning() {
    _mutexRunning.lock();
    _running = false;
    _mutexRunning.unlock();
}

bool PacketHandler::connect(const QString& networkInterface, const QString& serverAddress, const uint16 serverPort, const QString& grSimAddress, const uint16 grSimPort) {
    // Connects to WRBackbone
    if(!Actuator::connect(serverAddress, serverPort)) {
        std::cerr << ">> [WRSimActuator] Failed to connect to WRBackbone server!" << std::endl;
        return false;
    }

    // Connects to grSim command listener
    if(_socket.isOpen())
        _socket.close();

    const QNetworkInterface iface = QNetworkInterface::interfaceFromName(networkInterface);
    const QNetworkAddressEntry addrEntry = iface.addressEntries().constFirst();
    _addrHost = addrEntry.broadcast();

    _socket.connectToHost(grSimAddress, grSimPort, QIODevice::WriteOnly, QAbstractSocket::IPv4Protocol);

    return true;
}

void PacketHandler::disconnect() {
    // Disconnect from WRBackbone
    Actuator::disconnect();

    // Close grSim socket
    if(_socket.isOpen())
        _socket.close();
}

bool PacketHandler::isConnected() const {
    return (_socket.isOpen() && Actuator::isConnected());
}

void PacketHandler::markPlayersAsUpdated(quint8 teamNum, quint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = true;
}

void PacketHandler::markPlayersAsOutdated(uint8 teamNum, uint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = false;
}

void PacketHandler::setSpeed(quint8 teamNum, quint8 playerNum, float x, float y, float theta) {
    // Save values
    _playersInfo.lock();
    _vx[teamNum][playerNum]     = -x;
    _vy[teamNum][playerNum]     = y;
    _vtheta[teamNum][playerNum] = theta;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void PacketHandler::kick(quint8 teamNum, quint8 playerNum, float power) {
    // Save values
    _playersInfo.lock();
    _kickSpeed[teamNum][playerNum]     = power;
    _chipKickSpeed[teamNum][playerNum] = 0.0;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void PacketHandler::chipKick(quint8 teamNum, quint8 playerNum, float power) {
    // Save values
    _playersInfo.lock();
    _kickSpeed[teamNum][playerNum]     = power*cos(0.785398);
    _chipKickSpeed[teamNum][playerNum] = power*sin(0.785398);

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void PacketHandler::kickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
    // Save values
    _playersInfo.lock();
    if(enable)
        _kickSpeed[teamNum][playerNum] = power;
    else
        _kickSpeed[teamNum][playerNum] = 0.0;
    _chipKickSpeed[teamNum][playerNum] = 0.0;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void PacketHandler::chipKickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
    // Save values
    _playersInfo.lock();
    if (enable) {
        _kickSpeed[teamNum][playerNum]     = power*cos(0.785398);
        _chipKickSpeed[teamNum][playerNum] = power*sin(0.785398);
    } else {
        _kickSpeed[teamNum][playerNum]     = 0.0;
        _chipKickSpeed[teamNum][playerNum] = 0.0;
    }

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void PacketHandler::holdBall(quint8 teamNum, quint8 playerNum, bool enable) {
    // Save values
    _playersInfo.lock();
    _dribbler[teamNum][playerNum] = enable;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}
