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

#ifndef WORKER_HH
#define WORKER_HH

#include <QObject>
#include <QMutex>
#include <WRSimBridge/utils/timer/wrtimer.hh>

class Worker : public QObject {
    Q_OBJECT
public:
    Worker();

    // Thread control
    void setLoopFrequency(int hz);
    bool isRunning();
    void stopRunning();
    void controlTime();

    // Time Control
    void startTimer();
    void stopTimer();

    // Connection to Server methods
    virtual void connectToServer(const QString &serverAddress, const quint16 serverPort) = 0;
    virtual void disconnectFromServer() = 0;

    // Check connection with Sim and with the sensor
    virtual bool isConnected() = 0;

public slots:
    // Main slot function of the worker that the associated thread will run
    virtual void startWorking() = 0;

signals:
    // Control signal emited when the thread is stopped
    void finishedWorking();

protected:

    // Thread internal info
    QMutex _mutexRunning;
    bool _running;
    float _loopTime;
    WRTimer _timer;

};


#endif // WORKER_HH
