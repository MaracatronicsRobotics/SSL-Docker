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

#include <WRSimBridge/packethandler/worker/simworkers/sendworkers/vsssimsendworker.hh>
#include <WRSimBridge/utils/color/color.hh>
#include <3rdparty/proto/VSSSim/command.pb.h>
#include <iostream>

#pragma GCC diagnostic ignored "-Wunused-parameter"

#define DISTANCE_BETWEEN_WHEELS_CM 10.5

// Constructor
VSSSimSendWorker::VSSSimSendWorker(const QString &name, zmq::socket_t *socketCommandBlue, zmq::socket_t *socketCommandYellow) : SimSendWorker(name) {
    // Sets initial values to 0
    for(int i=0; i<VSS_MAXTEAMNUMBER; i++) {
        for(int j=0; j<VSS_MAXPLAYERNUMBER; j++) {
            _vy[i][j]            = 0.0;
            _vtheta[i][j]        = 0.0;

            _isPlayerUpdated[i][j] = false;
        }
    }

    _socketCommandBlue = socketCommandBlue;
    _socketCommandYellow = socketCommandYellow;

    _robotSpeed.leftWheel = 0;
    _robotSpeed.rightWheel = 0;
}


void VSSSimSendWorker::startWorking() {
    while(isRunning())	{

        // Loop
        startTimer();
        if(isConnected()) {

            for(int i = 0; i < VSS_MAXTEAMNUMBER; i++) {

                int teamNum = i;

                vss_command::Global_Commands packet;
                packet.set_situation(0);
                packet.set_name((i == Colors::YELLOW)? "Warthog Yellow" : "Warthog Blue");
                packet.set_is_team_yellow(i == Colors::YELLOW);

                // Check witch players were updated and send the packet to them
                for(int j = 0; j < VSS_MAXPLAYERNUMBER; j++) {

                    int playerNum = j;

                    // If was updated, send player packet
                    _playersInfo.lock();
                    if(_isPlayerUpdated[teamNum][playerNum]) {

                        vss_command::Robot_Command* command = packet.add_robot_commands();
                        command->set_id(playerNum);

                        calculateWheelSpeed(_vy[teamNum][playerNum], _vtheta[teamNum][playerNum]);

                        command->set_left_vel(_robotSpeed.leftWheel);
                        command->set_right_vel(_robotSpeed.rightWheel);

                        //Reset old updated players to outdated
                        markPlayersAsOutdated(teamNum, playerNum);
                    }
                    _playersInfo.unlock();
                }

                std::string sendString;

                // Serializes the info on the protobuf packet to a string
                packet.SerializeToString(&sendString);

                zmq::message_t request(sendString.size());

                // Copy the string into an zmq request object
                memcpy((void *) request.data(), sendString.c_str(), sendString.size());

                // Send the command based on the team (in this vsssim you have one command socket for each team)
                if(teamNum == Colors::YELLOW) {
                    _socketCommandYellow->send(request);
                } else {
                    _socketCommandBlue->send(request);
                }
            }
        }
        stopTimer();

        // Thread loop time control
        controlTime();
    }

    emit finishedWorking();
}

/**
 * @brief VSSSimSendWorker::calculateWheelSpeed
 * @param vy
 * @param vtheta
 * @brief This Simulator does not obey the International System of measurments. So the
 * rightWheel and the LeftWheel speed is in cm/s and with two positive and equal values for both
 * the robot will go foward, and with simetric values it will spin
 */
void VSSSimSendWorker::calculateWheelSpeed(float vy, float vtheta) {
    // All the units will be in centimeters because the VSS Sim works with this distance unit

    // Changing meters per second to centimeters per second
    vy = vy*100;

    // Wheel velocity to make the robot run at the desired angular speed (vtheta)
    // Simplified count that calculates the wheel speed in cm/s only for the vtheta, because the vy is added below
    float wheelVel = vtheta*DISTANCE_BETWEEN_WHEELS_CM/2;

    // Sums up with the linear velocity
    _robotSpeed.rightWheel = wheelVel + vy;

    // Here we multiply by -1 because for the robot to spin one wheel velocity has to be the oposit from the other
    _robotSpeed.leftWheel = (-1*wheelVel) + vy;
}


bool VSSSimSendWorker::isConnected() {
    return (_socketCommandYellow->connected() && _socketCommandBlue->connected() && Actuator::isConnected());
}

void VSSSimSendWorker::setSpeed(quint8 teamNum, quint8 playerNum, float x, float y, float theta) {
    // Ther "x" float is not used because the VSS robot can not run to his sides

    // Save values
    _playersInfo.lock();
    _vy[teamNum][playerNum]     = y;
    _vtheta[teamNum][playerNum] = theta;

    markPlayersAsUpdated(teamNum, playerNum);
    _playersInfo.unlock();
}

void VSSSimSendWorker::kick(quint8 teamNum, quint8 playerNum, float power) {
    return;
}

void VSSSimSendWorker::chipKick(quint8 teamNum, quint8 playerNum, float power) {
    return;
}

void VSSSimSendWorker::kickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
    return;
}

void VSSSimSendWorker::chipKickOnTouch(quint8 teamNum, quint8 playerNum, bool enable, float power) {
    return;
}

void VSSSimSendWorker::holdBall(quint8 teamNum, quint8 playerNum, bool enable) {
    return;
}

void VSSSimSendWorker::markPlayersAsUpdated(quint8 teamNum, quint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = true;
}

void VSSSimSendWorker::markPlayersAsOutdated(quint8 teamNum, quint8 playerNum) {
    _isPlayerUpdated[teamNum][playerNum] = false;
}
