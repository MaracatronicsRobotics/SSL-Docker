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

#include <WRSimBridge/packethandler/worker/worker.hh>
#include <QThread>
#include <iostream>

Worker::Worker() {
    // Set default values
    _running = true;
    _loopTime = 1000;
}

// Sets the loopTime variable in ms
void Worker::setLoopFrequency(int hz) {
    if(hz!=0)
        _loopTime = 1000/hz;
}

// Checks if the thread is running or outside someone had stopped it
bool Worker::isRunning() {
    bool result;
    _mutexRunning.lock();
    result = _running;
    _mutexRunning.unlock();
    return result;
}

// Make the thread stop running
void Worker::stopRunning() {
    _mutexRunning.lock();
    _running = false;
    _mutexRunning.unlock();
}

// Start the timer
void Worker::startTimer() {
    _timer.start();
}
// Stops the timer
void Worker::stopTimer() {
    _timer.stop();
}

// Thread loop time control
void Worker::controlTime() {
    if(isRunning()) {
        long rest = _loopTime - _timer.timemsec();
        if(rest >= 0) {
            QThread::msleep(rest);
        } else {
            std::cout << "[TIMER OVEREXTENDED] " << " PacketHandler for " <<  -rest  << " ms.\n";
        }
    }
}

