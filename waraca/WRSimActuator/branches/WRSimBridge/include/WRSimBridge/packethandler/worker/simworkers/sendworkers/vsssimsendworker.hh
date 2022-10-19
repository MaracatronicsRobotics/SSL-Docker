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

#ifndef VSSSIMSENDWORKER_HH
#define VSSSIMSENDWORKER_HH

#include <WRSimBridge/packethandler/worker/simworkers/simsendworker.hh>
#include <zmq.hpp>

#define VSS_MAXPLAYERNUMBER 3
#define VSS_MAXTEAMNUMBER 2

class VSSSimSendWorker : public SimSendWorker {
    Q_OBJECT
public:
    // Constructor
    VSSSimSendWorker(const QString &name, zmq::socket_t *socketCommandBlue, zmq::socket_t *socketCommandYellow);

    // Checks the connection with the sim and between the actuator and the server
    bool isConnected();

    // funtion(slot) responsible to send the commands from the controller to the simulator
    void startWorking();

private:

    // Sockets used to send the commands related to the blue and yellow team
    zmq::socket_t *_socketCommandBlue;
    zmq::socket_t *_socketCommandYellow;

    // Actuator implementation
    void setSpeed(uint8 teamNum, uint8 playerNum, float x, float y, float theta);
    void kick(uint8 teamNum, uint8 playerNum, float power);
    void chipKick(uint8 teamNum, uint8 playerNum, float power);
    void kickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void chipKickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void holdBall(uint8 teamNum, uint8 playerNum, bool enable);

    // Players state matrix
    float _vy[VSS_MAXTEAMNUMBER][VSS_MAXPLAYERNUMBER];
    float _vtheta[VSS_MAXTEAMNUMBER][VSS_MAXPLAYERNUMBER];
    bool _isPlayerUpdated[VSS_MAXTEAMNUMBER][VSS_MAXPLAYERNUMBER];

    // Functions to optimize the packet send (only send when the player had been previously updated)
    void markPlayersAsOutdated(quint8 teamNum, quint8 playerNum);
    void markPlayersAsUpdated(quint8 teamNum, quint8 playerNum);

    // Converts the speed sent by the controller to the vsssim standard (cm/s on the left and on the right wheels)
    void calculateWheelSpeed(float vy, float vtheta);

    // Represent the speed that will be sent to one vss robot on the vsssim
    typedef struct wheelSpeed {
        float leftWheel;
        float rightWheel;
    }WheelSpeed;

    // Stores the speed that will be sent to one vss robot on the vsssim
    WheelSpeed _robotSpeed;

};

#endif // VSSSIMSENDWORKER_HH
