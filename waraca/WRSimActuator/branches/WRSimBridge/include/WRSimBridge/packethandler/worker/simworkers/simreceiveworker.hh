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

#ifndef SIMRECEIVEWORKER_HH
#define SIMRECEIVEWORKER_HH

#include <WRSimBridge/packethandler/worker/worker.hh>
#include <WRSimBridge/packethandler/worker/simworkers/sensorinterface.hh>

class SimReceiveWorker : public Worker {
    Q_OBJECT
public:

    // Constructor
    SimReceiveWorker();

    // Connection to Server methods
    void connectToServer(const QString& serverAddress, const quint16 serverPort);
    void disconnectFromServer();

    // Check connection with Sim and with the sensor
    virtual bool isConnected() = 0;

protected:

    SensorInterface _sensorInterface;

};

#endif // SIMRECEIVEWORKER_HH
