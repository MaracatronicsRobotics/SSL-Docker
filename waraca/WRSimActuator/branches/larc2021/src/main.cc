/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of WRSimActuator project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

#include <QApplication>
#include <iostream>
#include <WRSimActuator/exithandler.hh>
#include <WRSimActuator/packethandler.hh>

#define DEFAULT_SERVER_ADDRESS "localhost"
#define DEFAULT_GRSIM_ADDRESS "localhost"
#define DEFAULT_SERVER_PORT 0
#define DEFAULT_GRSIM_PORT 20011
#define DEFAULT_NET_INTERFACE "eth0"

void printUsage(void) {
    std::cout << ">> Usage: ./grSimActuator [net-interface] [serverAddress] [serverPort] [grSimAddress] [grSimPort]\n";
    std::cout << ">> net-interface: Network Interface; default="<< DEFAULT_NET_INTERFACE << std::endl;
    std::cout << ">> serverAddress: GEARSystem server ip; default="<< DEFAULT_SERVER_ADDRESS << std::endl;
    std::cout << ">> serverPort: GEARSystem server port; default="<< DEFAULT_SERVER_PORT << std::endl;
    std::cout << ">> grSimAddress: grSim command listen ip; default="<< DEFAULT_GRSIM_ADDRESS << std::endl;
    std::cout << ">> grSimPort: grSim command listen port; default="<< DEFAULT_GRSIM_PORT << std::endl;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("grSimActuator");

    /*########### EXIT HANDLER (CTRL+C) ##############*/
    ExitHandler::setup(&app);

    /*########### ARGUMENT PARSING ##############*/
    // Default parameters
    QString networkInterface = DEFAULT_NET_INTERFACE;
    QString serverAddress = DEFAULT_SERVER_ADDRESS;
    quint16 serverPort = DEFAULT_SERVER_PORT;
    QString grSimAddress = DEFAULT_GRSIM_ADDRESS;
    quint16 grSimPort = DEFAULT_GRSIM_PORT;

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
            networkInterface = QString(argv[1]);
        }

        if(argc >= 3)
            serverAddress = QString(argv[2]);

        if(argc >= 4)
            serverPort = QString(argv[3]).toUShort();

        if(argc >= 5)
            grSimAddress = QString(argv[4]);

        if(argc >= 6)
            grSimPort = QString(argv[5]).toUShort();
    } else {
        std::cout << "Using default parameters.\n";
    }

    std::cout << "-> Network interface: " << networkInterface.toStdString() << std::endl;
    std::cout << "-> Server address: " << serverAddress.toStdString() << std::endl;
    std::cout << "-> Server port: " << serverPort << std::endl;
    std::cout << "-> grSim address: " << grSimAddress.toStdString() << std::endl;
    std::cout << "-> grSim port: " << grSimPort << std::endl;

    /*########### SYSTEM SETUP ############*/
    PacketHandler ph("WRSimActuator");
    ph.connect(networkInterface, serverAddress, serverPort, grSimAddress, grSimPort);
    ph.setLoopFrequency(60);
    ph.start();

    // Wait for exit
    int retn = app.exec();

    // Finalization
    ph.stopRunning();
    ph.wait();

    return retn;
}
