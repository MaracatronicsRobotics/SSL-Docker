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

#ifndef GRSIMPACKETHANDLER_HH
#define GRSIMPACKETHANDLER_HH

#include <WRSimBridge/packethandler/packethandler.hh>
#include <QtNetwork>

#define SSL_MAXPLAYERNUMBER 12
#define SSL_MAXTEAMNUMBER 2

class GrSimPacketHandler : public PacketHandler {
Q_OBJECT
public:
    GrSimPacketHandler(const QString &name);

    // Network control
    bool connectToSim(const QString& simulatorAddress, quint16 SimulatorPort);
    bool connectToSim();
	void disconnect();

    bool startWorkers(const QString &serverAddress, const quint16 serverPort);

private:

    // grSim socket
    QUdpSocket _socketCommand;
    QUdpSocket _socketReceiveVision;

};

#endif // GRSIMPACKETHANDLER_HH
