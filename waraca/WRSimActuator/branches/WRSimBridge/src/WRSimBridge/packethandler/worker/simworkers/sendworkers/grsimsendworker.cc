/**
* Warthog Robotics
* University of Sao Paulo (USP) at Sao Carlos
* http://www.warthog.sc.usp.br/
* This file is part of the WRSimBridge project
*
* Copyright (C) 2017 Warthog Robotics
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
**/

#include <WRSimBridge/packethandler/worker/simworkers/sendworkers/grsimsendworker.hh>
#include <WRSimBridge/utils/color/color.hh>
#include <3rdparty/proto/grSim/grSim_Replacement.pb.h>
#include <3rdparty/proto/grSim/grSim_Commands.pb.h>
#include <3rdparty/proto/grSim/grSim_Packet.pb.h>
#include <iostream>

GrSimSendWorker::GrSimSendWorker(const QString &name, QUdpSocket *socket) : SimSendWorker(name) {
    // Sets initial values to 0
    for(int i=0; i<SSL_MAXTEAMNUMBER; i++) {
        for(int j=0; j<SSL_MAXPLAYERNUMBER; j++) {
            _vx[i][j]            = 0.0;
            _vy[i][j]            = 0.0;
            _vtheta[i][j]        = 0.0;
            _kickSpeed[i][j]     = 0.0;
            _chipKickSpeed[i][j] = 0.0;
            _dribbler[i][j]      = false;

            _isPlayerUpdated[i][j] = false;
        }
    }

    _socket = socket;
}

void GrSimSendWorker::startWorking() {
    // Controls the packet loop time
    while(isRunning())	{

        // Loop
        startTimer();
        if(isConnected()) {

            // Check witch players were updated and send the packet to them
            for(int i=0; i<SSL_MAXTEAMNUMBER; i++) {
                for(int j=0; j<SSL_MAXPLAYERNUMBER; j++) {

                    // If was updated, send player packet
                    _playersInfo.lock();
                    if(_isPlayerUpdated[i][j]){
                        int teamNum = i;
                        int playerNum = j;

                        // Sets team and player number to the packet
                        grSim_Packet packet;
                        packet.mutable_commands()->set_isteamyellow(teamNum==Colors::YELLOW);
                        packet.mutable_commands()->set_timestamp(0.0);
                        grSim_Robot_Command* command = packet.mutable_commands()->add_robot_commands();
                        command->set_id(playerNum);

                        // Fills packet with current values
                        command->set_wheelsspeed(false);
                        command->set_kickspeedx(_kickSpeed[teamNum][playerNum]);
                        command->set_kickspeedz(_chipKickSpeed[teamNum][playerNum]);
                        command->set_velnormal(_vx[teamNum][playerNum]);
                        command->set_veltangent(_vy[teamNum][playerNum]);
                        command->set_velangular(_vtheta[teamNum][playerNum]);

                        // Enters new values to the packet
                        command->set_spinner(_dribbler[teamNum][playerNum]);

                        // Sends the packet
                        std::string sendString;
                        packet.SerializeToString(&sendString);
                        if(_socket->write(sendString.c_str(), sendString.length()) == -1) {
                            std::cout << "[WRSimBridge] Failed to write to socket: " << _socket->errorString().toStdString() << std::endl;
                        }

                        //Reset old updated players to outdated
                        markPlayersAsOutdated(teamNum, playerNum);
                    }
                    _playersInfo.unlock();

                }
            }

        }
        stopTimer();

        // Thread loop time control
        controlTime();
    }

    emit finishedWorking();
}

// Checks the connection with the sim and between the actuator and the server
bool GrSimSendWorker::isConnected() {
    return (_socket->isOpen() && Actuator::isConnected());
}

void GrSimSendWorker::setSpeed(quint8 teamNum, quint8 playerNum, float x, float y, float theta) {
    // Save values
    _playersInfo.lock();
    _vx[teamNum][playerNum]     = -x;
    _vy[teamNum][playerNum]     = y;
    _vtheta[teamNum][playerNum] = theta;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void GrSimSendWorker::kick(quint8 teamNum, quint8 playerNum, float power) {
    // Save values
    _playersInfo.lock();
    _kickSpeed[teamNum][playerNum]     = power;
    _chipKickSpeed[teamNum][playerNum] = 0.0;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void GrSimSendWorker::chipKick(quint8 teamNum, quint8 playerNum, float power) {
    // Save values
    _playersInfo.lock();
    _kickSpeed[teamNum][playerNum]     = power*cos(0.785398);
    _chipKickSpeed[teamNum][playerNum] = power*sin(0.785398);

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void GrSimSendWorker::kickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
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

void GrSimSendWorker::chipKickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
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

void GrSimSendWorker::holdBall(quint8 teamNum, quint8 playerNum, bool enable) {
    // Save values
    _playersInfo.lock();
    _dribbler[teamNum][playerNum] = enable;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void GrSimSendWorker::markPlayersAsUpdated(quint8 teamNum, quint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = true;
}

void GrSimSendWorker::markPlayersAsOutdated(uint8 teamNum, uint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = false;
}
