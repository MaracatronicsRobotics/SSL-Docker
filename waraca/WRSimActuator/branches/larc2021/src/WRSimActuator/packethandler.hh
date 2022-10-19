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

#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

#include <QThread>
#include <QUdpSocket>
#include <GEARSystem/gearsystem.hh>

#define MAXPLAYERNUMBER 12
#define MAXTEAMNUMBER 2

class PacketHandler : public QThread, public Actuator {
	Q_OBJECT
public:
	PacketHandler(const QString &name);

    // Network control
    bool connect(const QString& networkInterface, const QString& serverAddress, const uint16 serverPort, const QString& grSimAddress, uint16 grSimPort);
	void disconnect();
	bool isConnected() const;

    // Thread control
    void setLoopFrequency(int hz);
    bool isRunning();
    void stopRunning();
private:
    // Thread implementation
    void run();

    // Actuator implementation
    void setSpeed(uint8 teamNum, uint8 playerNum, float x, float y, float theta);
    void kick(uint8 teamNum, uint8 playerNum, float power);
    void chipKick(uint8 teamNum, uint8 playerNum, float power);
    void kickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void chipKickOnTouch(uint8 teamNum, uint8 playerNum, bool enable, float power);
    void holdBall(uint8 teamNum, uint8 playerNum, bool enable);

    // grSim socket
	QUdpSocket _socket;
    QHostAddress _addrHost;

    // Players state matrix
	float _vx[MAXTEAMNUMBER][MAXPLAYERNUMBER];
	float _vy[MAXTEAMNUMBER][MAXPLAYERNUMBER];
	float _vtheta[MAXTEAMNUMBER][MAXPLAYERNUMBER];
	float _kickSpeed[MAXTEAMNUMBER][MAXPLAYERNUMBER];
	float _chipKickSpeed[MAXTEAMNUMBER][MAXPLAYERNUMBER];
	bool  _dribbler[MAXTEAMNUMBER][MAXPLAYERNUMBER];
    bool _isPlayerUpdated[MAXTEAMNUMBER][MAXPLAYERNUMBER];

    // Thread internal info
    QMutex _mutexRunning;
    bool _running;
    float _loopTime;

    // Actuator/thread synchronization mutex
    QMutex _playersInfo;

    // Internal
    void markPlayersAsUpdated(uint8 teamNum, uint8 playerNum);
    void markPlayersAsOutdated(uint8 teamNum, uint8 playerNum);
};

#endif // PACKETHANDLER_H
