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

#ifndef SIMSENDWORKER_HH
#define SIMSENDWORKER_HH

#include <WRSimBridge/packethandler/worker/worker.hh>
#include <GEARSystem/actuator.hh>

class SimSendWorker : public Worker, public Actuator {
    Q_OBJECT
public:
    // Constructor
    SimSendWorker(const QString &name);

    // Connection to Server methods
    void connectToServer(const QString &serverAddress, const quint16 serverPort);
    void disconnectFromServer();

    // Check connection with Sim and with the sensor
    virtual bool isConnected() = 0;

protected:
    // Actuator/thread synchronization mutex
    QMutex _playersInfo;

private:

    // Actuator implementation
    void virtual setSpeed(uint8 teamNum, uint8 playerNum, float x, float y, float theta) = 0;
    void virtual kick(uint8 teamNum, uint8 playerNum, float power) = 0;
    void virtual chipKick(uint8 teamNum, uint8 playerNum, float power) = 0;
    void virtual kickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power) = 0;
    void virtual chipKickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power) = 0;
    void virtual holdBall(uint8 teamNum, uint8 playerNum, bool enable) = 0;

    // Functions to optimize the packet send (only send when the player had been previously updated)
    virtual void markPlayersAsOutdated(quint8 teamNum, quint8 playerNum) = 0;
    virtual void markPlayersAsUpdated(quint8 teamNum, quint8 playerNum) = 0;

};

#endif // SIMSENDWORKER_HH
