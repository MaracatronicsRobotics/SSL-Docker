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

#ifndef VSSSIMRECEIVEWORKER_HH
#define VSSSIMRECEIVEWORKER_HH

#include <WRSimBridge/packethandler/worker/simworkers/simreceiveworker.hh>
#include <WRSimBridge/utils/fields/fieldvss2008.hh>
#include <WRSimBridge/utils/timer/wrtimer.hh>
#include <zmq.hpp>
#include <3rdparty/proto/VSSSim/state.pb.h>

class VSSSimReceiveWorker : public SimReceiveWorker {
    Q_OBJECT
public:
    // Constructor
    VSSSimReceiveWorker(zmq::socket_t *socketReceiveState);

    // Checks the connection with the simulator and between the sensor and the server
    bool isConnected();

    // funtion(slot) responsible to receive the vision data from the simulator and put it on the sensor
    void startWorking();

private:

    // Socket that is connect to the simulator vision port for the visual data
    zmq::socket_t *_socketReceiveState;

    // Hardcoded information about the VSS IEEE 2008 field to be inserted on the sensor (the sim does not send this infos)
    Fields::VSS2008 _field;

    // Method to send all the VSS IEEE 2008 field dimentions and locations to the sensor
    void setFieldDimentions();

    // zmq method to receive the vision (state) data from the sim
    void receiveState(vss_state::Global_State &global_state);

    // Set information about the robots on the sensor from the sim
    void getRobotPositionAndOrientation(int robotNumber, int robotTeam, Position &robotPosition, Angle &robotOrientation, const vss_state::Global_State &globalState);
    void getRobotVelocityAndAngularSpeed(int robotNumber, int robotTeam, Velocity &robotVelocity, AngularSpeed &robotAngularSpeed, const vss_state::Global_State &globalState);

    // Get information about the ball on the sensor from the sim
    void getBallPositionAndVelocity(Position &ballPosition, Velocity &ballVelocity, const vss_state::Global_State &globalState);

};

#endif // VSSSIMRECEIVEWORKER_HH
