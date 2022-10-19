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

#include <WRSimBridge/packethandler/simhandlers/grsimpackethandler.hh>
#include <WRSimBridge/packethandler/worker/simworkers/sendworkers/grsimsendworker.hh>
#include <WRSimBridge/packethandler/worker/simworkers/receiveworkers/grsimreceiveworker.hh>
#include <iostream>

#define DEFAULT_GRSIM_ADDRESS "localhost"
#define DEFAULT_GRSIM_PORT 20011

GrSimPacketHandler::GrSimPacketHandler(const QString& name){

    _sendWorker = new GrSimSendWorker(name, &_socketCommand);
//    _receiveWorker = new GrSimReceiveWorker(_socketReceiveVision);
}

bool GrSimPacketHandler::connectToSim() {

    std::cout << "[WARNING] Using default grSim address and port because connect was called with two parameters only\n";

    return connectToSim(DEFAULT_GRSIM_ADDRESS, DEFAULT_GRSIM_PORT);
}

bool GrSimPacketHandler::connectToSim(const QString &simulatorAddress, quint16 SimulatorPort) {
    // Connects to grSim command listener
    if(_socketCommand.isOpen()) {
        _socketCommand.close();
    }
    _socketCommand.connectToHost(simulatorAddress, SimulatorPort, QIODevice::WriteOnly, QAbstractSocket::IPv4Protocol);

    return true;
}

void GrSimPacketHandler::disconnect() {
    // Close grSim socket
    if(_socketCommand.isOpen())
        _socketCommand.close();

    _sendWorker->disconnectFromServer();
    /// Desconectar do receiver também
}

bool GrSimPacketHandler::startWorkers(const QString& serverAddress, const quint16 serverPort) {

    _sendWorker->connectToServer(serverAddress, serverPort);
    _sendWorker->setLoopFrequency(60);
    _sendWorker->moveToThread(&_sendWorkerThread);
    QObject::connect(&_sendWorkerThread, SIGNAL(started()), _sendWorker, SLOT(startWorking()));
    QObject::connect(_sendWorker, SIGNAL(finishedWorking()), &_sendWorkerThread, SLOT(quit()));
    QObject::connect(_sendWorker, SIGNAL(finishedWorking()), _sendWorker, SLOT(deleteLater()));
    QObject::connect(&_sendWorkerThread, SIGNAL(finished()), &_sendWorkerThread, SLOT(deleteLater()));
    _sendWorkerThread.start();

    return true;
}
