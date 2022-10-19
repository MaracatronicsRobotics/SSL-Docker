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

#ifndef PACKETHANDLER_HH
#define PACKETHANDLER_HH

#include <QObject>
#include <WRSimBridge/packethandler/worker/simworkers/simsendworker.hh>
#include <WRSimBridge/packethandler/worker/simworkers/simreceiveworker.hh>

class PacketHandler : public QObject {
    Q_OBJECT
public:

    // Constructor
    PacketHandler();
    // Destructor
    ~PacketHandler();

    // Communications methods related to the simulator
    virtual bool connectToSim(const QString& simulatorAddress, quint16 SimulatorPort) = 0;
    virtual bool connectToSim() = 0;
    virtual void disconnect() = 0;        

    // Start the receive and send worker threads
    virtual bool startWorkers(const QString& serverAddress, const quint16 serverPort) = 0;

    // Finish the worker's loop
    void stopWorkers();

protected:

    // Send worker and it's thread
    QThread _sendWorkerThread;
    SimSendWorker *_sendWorker;

    // Receive worker and it's thread
    QThread _receiveWorkerThread;
    SimReceiveWorker *_receiveWorker;

};

#endif // PACKETHANDLER_HH
