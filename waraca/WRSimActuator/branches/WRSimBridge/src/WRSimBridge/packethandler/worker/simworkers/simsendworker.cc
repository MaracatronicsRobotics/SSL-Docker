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

#include <WRSimBridge/packethandler/worker/simworkers/simsendworker.hh>
#include <iostream>

// Constructor
SimSendWorker::SimSendWorker(const QString &name) : Actuator(name) {

}

// Connects the Actuator to the server
void SimSendWorker::connectToServer(const QString &serverAddress, const quint16 serverPort) {
    // Connects to WRBackbone
    int tries = 1;
    while(GEARSystem::Actuator::connect(serverAddress, serverPort) == false) {
        std::cout << "[WARNING] Failed to connect to WRBackbone server! Try number " << tries << std::endl << std::endl;
        QThread::msleep(100);
        tries++;
    }
}

// Disconnects the Actuator to the server
void SimSendWorker::disconnectFromServer() {
    Actuator::disconnect();
}
