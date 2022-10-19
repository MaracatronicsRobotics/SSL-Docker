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

#ifndef VSSSIMPACKETHANDLER_HH
#define VSSSIMPACKETHANDLER_HH

#include <WRSimBridge/packethandler/packethandler.hh>
#include <zmq.hpp>

class VSSSimPacketHandler : public PacketHandler {
public:

    // Constructor
    VSSSimPacketHandler(const QString &name);

    // Destructor
    ~VSSSimPacketHandler();

    // Communications methods related to the simulator (vss)
    bool connectToSim(const QString& simulatorAddress, quint16 SimulatorPort);
    bool connectToSim();
    void disconnect();

    // Implementation of the starting and configuration of the VSSSim workers
    bool startWorkers(const QString& serverAddress, const quint16 serverPort);

private:

    // Context and socket to connect to the simulator to send commands to the VSSSim yellow team
    zmq::context_t *_contextCommandYellow;
    zmq::socket_t *_socketCommandYellow;

    // Context and socket to connect to the simulator to send commands to the VSSSim blue team
    zmq::context_t *_contextCommandBlue;
    zmq::socket_t *_socketCommandBlue;

    // Context and socket to connect to the simulator to receive vision data
    zmq::context_t *_contextReceiveState;
    zmq::socket_t *_socketReceiveState;

};

#endif // VSSSIMPACKETHANDLER_HH
