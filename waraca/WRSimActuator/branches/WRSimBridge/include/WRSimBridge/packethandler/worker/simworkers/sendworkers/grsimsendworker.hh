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

#ifndef GRSIMSENDWORKER_HH
#define GRSIMSENDWORKER_HH

#include <WRSimBridge/packethandler/worker/simworkers/simsendworker.hh>
#include <QtNetwork>

#define SSL_MAXPLAYERNUMBER 12
#define SSL_MAXTEAMNUMBER 2

class GrSimSendWorker : public SimSendWorker {
    Q_OBJECT
public:

    // Constructor
    GrSimSendWorker(const QString &name, QUdpSocket *socket);

    // Checks the connection with the sim and between the actuator and the server
    bool isConnected();

    // funtion(slot) responsible to send the commands from the controller to the simulator
    void startWorking();

private:

    // Socket that represent and holds the connection with the
    QUdpSocket *_socket;

    // Actuator implementation
    void setSpeed(uint8 teamNum, uint8 playerNum, float x, float y, float theta);
    void kick(uint8 teamNum, uint8 playerNum, float power);
    void chipKick(uint8 teamNum, uint8 playerNum, float power);
    void kickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void chipKickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void holdBall(uint8 teamNum, uint8 playerNum, bool enable);

    // Players state matrix
    float _vx[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    float _vy[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    float _vtheta[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    float _kickSpeed[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    float _chipKickSpeed[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    bool  _dribbler[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];
    bool _isPlayerUpdated[SSL_MAXTEAMNUMBER][SSL_MAXPLAYERNUMBER];

    // Functions to optimize the packet send (only send when the player had been previously updated)
    void markPlayersAsOutdated(quint8 teamNum, quint8 playerNum);
    void markPlayersAsUpdated(quint8 teamNum, quint8 playerNum);    

};

#endif // GRSIMSENDWORKER_HH
