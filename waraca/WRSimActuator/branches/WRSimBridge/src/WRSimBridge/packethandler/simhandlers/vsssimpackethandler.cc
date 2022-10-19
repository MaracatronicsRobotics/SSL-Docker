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

#include <WRSimBridge/packethandler/simhandlers/vsssimpackethandler.hh>
#include <WRSimBridge/packethandler/worker/simworkers/sendworkers/vsssimsendworker.hh>
#include <WRSimBridge/packethandler/worker/simworkers/receiveworkers/vsssimreceiveworker.hh>
#include <iostream>

#pragma GCC diagnostic ignored "-Wunused-parameter"

VSSSimPacketHandler::VSSSimPacketHandler(const QString &name) {

    // Instantiation of contexts and sockets
    _contextCommandYellow = new zmq::context_t(1);
    _socketCommandYellow = new zmq::socket_t(*_contextCommandYellow, ZMQ_PAIR);

    _contextCommandBlue = new zmq::context_t(1);
    _socketCommandBlue = new zmq::socket_t(*_contextCommandBlue, ZMQ_PAIR);

    _contextReceiveState = new zmq::context_t(1);
    _socketReceiveState = new zmq::socket_t(*_contextReceiveState, ZMQ_SUB);

    // Instantiation of send and receive workers
    _sendWorker = new VSSSimSendWorker(name, _socketCommandBlue, _socketCommandYellow);
    _receiveWorker = new VSSSimReceiveWorker(_socketReceiveState);

}

VSSSimPacketHandler::~VSSSimPacketHandler() {
    delete _contextCommandBlue;
    delete _socketCommandBlue;
    delete _contextCommandYellow;
    delete _socketCommandYellow;
    delete _contextReceiveState;
    delete _socketReceiveState;
}

// Connect to the sim
bool VSSSimPacketHandler::connectToSim() {

    std::cout << "Connecting Client State Receiver: " << "tcp://localhost:5555" << "\n\n";

    // Tries to establish a TCP connection to the vision simulator socket
    try {
    _socketReceiveState->connect("tcp://localhost:5555");
    _socketReceiveState->setsockopt(ZMQ_SUBSCRIBE, "", 0);
    } catch (zmq::error_t error) {
        std::cout << "[WARNING] Error while trying to connect to simulator state socket: error num = " << error.num() << "\n\n";
        return false;
    }

    std::cout << "Connecting Client Sender Team 1: " << "tcp://localhost:5556" << "(yellow team)" << "\n\n";

    // Tries to establish a TCP connection to the commands yellow socket
    try {
        _socketCommandYellow->connect("tcp://localhost:5556");
    } catch (zmq::error_t error) {
        std::cout << "[WARNING] Error while trying to connect to yellow command socket: error num = " << error.num() << "\n\n";
        return false;
    }

    std::cout << "Connecting Client Sender Team 1: " << "tcp://localhost:5557" << "(blue team)" << "\n\n";

    // Tries to establish a TCP connection to the commands blue socket
    try {
        _socketCommandBlue->connect("tcp://localhost:5557");
    } catch (zmq::error_t error) {
        std::cout << "[WARNING] Error while trying to connect to blue command socket: error num = " << error.num() << "\n\n";
        return false;
    }        

    return true;
}


// connect to the sim
bool VSSSimPacketHandler::connectToSim(const QString& simulatorAddress, quint16 SimulatorPort) {
    return connectToSim();
}

// Disconnects the zmq sockets from the simulator and disconnect the actuator and sensor
void VSSSimPacketHandler::disconnect() {    
//    _socketReceiveState->disconnect("tcp://localhost:5555");
    _socketCommandYellow->disconnect("tcp://localhost:5556");
    _socketCommandBlue->disconnect("tcp://localhost:5557");    

    _sendWorker->disconnectFromServer();
//    _receiveWorker->disconnectFromServer();
}

// Configures and start the workers
bool VSSSimPacketHandler::startWorkers(const QString& serverAddress, const quint16 serverPort) {

    // Connect the actuator to the server
    _sendWorker->connectToServer(serverAddress, serverPort);

    // Set the send frequency to 60 Hz
    _sendWorker->setLoopFrequency(60);

    // Associate the send thread to the send worker
    _sendWorker->moveToThread(&_sendWorkerThread);

    // Connect the signals
    QObject::connect(&_sendWorkerThread, SIGNAL(started()), _sendWorker, SLOT(startWorking()));
    QObject::connect(_sendWorker, SIGNAL(finishedWorking()), &_sendWorkerThread, SLOT(quit()));
    QObject::connect(_sendWorker, SIGNAL(finishedWorking()), _sendWorker, SLOT(deleteLater()));
    QObject::connect(&_sendWorkerThread, SIGNAL(finished()), &_sendWorkerThread, SLOT(deleteLater()));

    // Start the send thread
    _sendWorkerThread.start();

    // Connect the sensor to the server
    _receiveWorker->connectToServer(serverAddress, serverPort);

    // Set the receive frequency to 60 Hz
    _receiveWorker->setLoopFrequency(60);

    // Associate the receive thread to the receive worker
    _receiveWorker->moveToThread(&_receiveWorkerThread);

    // Connect the signals
    QObject::connect(&_receiveWorkerThread, SIGNAL(started()), _receiveWorker, SLOT(startWorking()));
    QObject::connect(_receiveWorker, SIGNAL(finishedWorking()), &_receiveWorkerThread, SLOT(quit()));
    QObject::connect(_receiveWorker, SIGNAL(finishedWorking()), _receiveWorker, SLOT(deleteLater()));
    QObject::connect(&_receiveWorkerThread, SIGNAL(finished()), &_receiveWorkerThread, SLOT(deleteLater()));

    // Start the receive thread
    _receiveWorkerThread.start();

    return true;
}



