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


#include <QtNetwork>
#include <QApplication>
#include <iostream>
#include <WRSimBridge/exithandler.hh>
#include <WRSimBridge/packethandler/simhandlers/grsimpackethandler.hh>
#include <WRSimBridge/packethandler/simhandlers/vsssimpackethandler.hh>

#define DEFAULT_SIM "grsim"
#define DEFAULT_SERVER_ADDRESS "localhost"
#define DEFAULT_SIM_ADDRESS "localhost"
#define DEFAULT_SERVER_PORT 0
#define DEFAULT_SIM_PORT 20011

void printUsage(void) {
    std::cout << ">> Usage: ./WRSimBridge [simulator] [serverAddress] [serverPort] [simAddress] [simPort]\n";
    std::cout << ">> simulator to make the bridge; default="<< DEFAULT_SIM << std::endl;
	std::cout << ">> serverAddress: GEARSystem server ip; default="<< DEFAULT_SERVER_ADDRESS << std::endl;
	std::cout << ">> serverPort: GEARSystem server port; default="<< DEFAULT_SERVER_PORT << std::endl;
    std::cout << ">> SimAddress: grSim command listen ip; default="<< DEFAULT_SIM_ADDRESS << std::endl;
    std::cout << ">> SimPort: grSim command listen port; default="<< DEFAULT_SIM_PORT << std::endl;
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
    app.setApplicationName("WRSimBridge");

	/*########### EXIT HANDLER (CTRL+C) ##############*/
	ExitHandler::setup(&app);

	/*########### ARGUMENT PARSING ##############*/
	// Default parameters
    QString simulator = DEFAULT_SIM;
	QString serverAddress = DEFAULT_SERVER_ADDRESS;
	quint16 serverPort = DEFAULT_SERVER_PORT;
    QString simAddress = DEFAULT_SIM_ADDRESS;
    quint16 simPort = DEFAULT_SIM_PORT;

	// Check arguments
	if(argc >= 2) {
		// Help
		if((strcmp(argv[1], "help")==0) ||
		   (strcmp(argv[1], "-help")==0) ||
		   (strcmp(argv[1], "--help")==0) ||
		   (strcmp(argv[1], "-h")==0)) {
			printUsage();
			return EXIT_SUCCESS;
        } else {
            simulator = QString(argv[1]);
        }

        if(argc >= 3) {
            serverAddress = QString(argv[2]);
        }

        if(argc >= 4) {
            serverPort = QString(argv[3]).toUShort();
        }

        if(argc >= 5) {
            simAddress = QString(argv[4]);
        }

        if(argc >= 6) {
            simPort = QString(argv[5]).toUShort();
        }

    } else {
        std::cout << "Using default parameters.\n";
    }

    std::cout << "-> Simulator choosen: " << simulator.toStdString() << std::endl;
    std::cout << "-> Server address: " << serverAddress.toStdString() << std::endl;
    std::cout << "-> Server port: " << serverPort << std::endl;
    std::cout << "-> Sim address: " << simAddress.toStdString() << std::endl;
    std::cout << "-> Sim port: " << simPort << std::endl << std::endl;

    PacketHandler *ph = NULL;

    if(simulator == "grsim") {
        ph = new GrSimPacketHandler("WRSimBridge");
        ph->connectToSim(simAddress, simPort);
    } else {        
        ph = new VSSSimPacketHandler("WRSimBridge");
        ph->connectToSim();
    }

    ph->startWorkers(serverAddress, serverPort);

    // Wait for exit
    int retn = app.exec();

    ph->stopWorkers();

    return retn;
}
