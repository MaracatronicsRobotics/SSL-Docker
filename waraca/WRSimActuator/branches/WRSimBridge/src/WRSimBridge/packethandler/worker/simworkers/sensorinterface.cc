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

#include <WRSimBridge/packethandler/worker/simworkers/sensorinterface.hh>
#include <iostream>

SensorInterface::SensorInterface() {

}

// Connect the sensor to the GEARSystem server
void SensorInterface::connectToServer(const QString &serverAddress, const quint16 serverPort) {
    int tries = 1;
    while(_sensor.connect(serverAddress, serverPort) == false) {
        std::cout << ">> [WARNING] Failed to connect to WRBackbone server! Try number " << tries << "\n\n";
        tries++;
    }
}

// Disconnect the sensor to the GEARSystem server
void SensorInterface::disconnectFromServer() {
    _sensor.disconnect();
}

// Checks the connection of the sensor with the server
bool SensorInterface::isSensorConnected() {
    return _sensor.isConnected();
}


void SensorInterface::addBall(quint8 ballNumber) {
    _sensor.addBall(ballNumber);
}

void SensorInterface::setBallPosition(quint8 ballNumber, const Position &ballPosition) {
    _sensor.setBallPosition(ballNumber, ballPosition);
}

void SensorInterface::setBallVelocity(quint8 ballNumber, const Velocity &ballVelocity) {
    _sensor.setBallVelocity(ballNumber, ballVelocity);
}

void SensorInterface::addPlayer(quint8 teamNumber, quint8 playerNumber) {
    _sensor.addPlayer(teamNumber, playerNumber);
}

void SensorInterface::updatePlayerStatus(quint8 playerNumber, quint8 teamNumber,
                                          const Position &playerPosition, const Angle &playerOrientation,
                                          const Velocity &playerVelocity, const AngularSpeed &playerAngularSpeed) {
    _sensor.setPlayerPosition(teamNumber, playerNumber, playerPosition);
    _sensor.setPlayerOrientation(teamNumber, playerNumber, playerOrientation);
    _sensor.setPlayerAngularSpeed(teamNumber, playerNumber, playerAngularSpeed);
    _sensor.setPlayerVelocity(teamNumber, playerNumber, playerVelocity);
}

void SensorInterface::addTeam(quint8 teamNumber, const QString &teamName) {
    _sensor.addTeam(teamNumber, teamName);
}

void SensorInterface::setFieldBottomLeftCorner(const Position &fieldBottomLeftCorner) {
    _sensor.setFieldBottomLeftCorner(fieldBottomLeftCorner);
}

void SensorInterface::setFieldBottomRightCorner(const Position &fieldBottomRightCorner) {
    _sensor.setFieldBottomRightCorner(fieldBottomRightCorner);
}

void SensorInterface::setFieldCenter(const Position &fieldCenter) {
    _sensor.setFieldCenter(fieldCenter);
}

void SensorInterface::setFieldTopLeftCorner(const Position &fieldTopLeftCorner) {
    _sensor.setFieldTopLeftCorner(fieldTopLeftCorner);
}

void SensorInterface::setFieldTopRightCorner(const Position &fieldTopRightCorner) {
    _sensor.setFieldTopRightCorner(fieldTopRightCorner);
}

void SensorInterface::setGoalPosts(const Position &fieldLeftGoalLeftPost, const Position &fieldLeftGoalRightPost, const Position &fieldRightGoalLeftPost, const Position &fieldRightGoalRightPost) {
    _sensor.setLeftGoalPosts(fieldLeftGoalLeftPost, fieldLeftGoalRightPost);
    _sensor.setRightGoalPosts(fieldRightGoalLeftPost, fieldRightGoalRightPost);
}

void SensorInterface::setFieldPenaltiesMark(const Position &fieldLeftPenaltyMark, const Position &fieldRightPenaltyMark) {
    _sensor.setLeftPenaltyMark(fieldLeftPenaltyMark);
    _sensor.setRightPenaltyMark(fieldRightPenaltyMark);
}

void SensorInterface::setFieldCenterRadius(const float fieldCenterRadius) {
    _sensor.setFieldCenterRadius(fieldCenterRadius);
}

void SensorInterface::setGoalArea(const float areaLenght, const float areaWidth, const float areaRoundedRadius) {
    _sensor.setGoalArea(areaLenght, areaWidth, areaRoundedRadius);
}

void SensorInterface::setGoalDepth(const float goalDepth) {
    _sensor.setGoalDepth(goalDepth);
}
