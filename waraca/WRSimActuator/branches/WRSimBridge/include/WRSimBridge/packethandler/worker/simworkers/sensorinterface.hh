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

#ifndef SENSORINTERFACE_HH
#define SENSORINTERFACE_HH

#include <GEARSystem/sensor.hh>

class SensorInterface
{
public:
    SensorInterface();

    // Connection to Server methods
    void connectToServer(const QString& serverAddress, const quint16 serverPort);
    void disconnectFromServer();

    //  Methods to add all the info the Sensor need to send to the server
    void addBall(quint8 ballNumber);
    void setBallPosition(quint8 ballNumber, const Position &ballPosition);
    void setBallVelocity(quint8 ballNumber, const Velocity &ballVelocity);

    void addPlayer(quint8 teamNumber, quint8 playerNumber);
    void updatePlayerStatus(quint8 playerNumber, quint8 teamNumber,
                                              const Position &playerPosition, const Angle &playerOrientation,
                                              const Velocity &playerVelocity, const AngularSpeed &playerAngularSpeed) ;
    void addTeam(quint8 teamNumber, const QString &teamName);

    void setFieldBottomLeftCorner(const Position &fieldBottomLeftCorner);
    void setFieldBottomRightCorner(const Position &fieldBottomRightCorner);
    void setFieldCenter(const Position &fieldCenter);
    void setFieldTopLeftCorner(const Position &fieldTopLeftCorner);
    void setFieldTopRightCorner(const Position &fieldTopRightCorner);
    void setGoalPosts(const Position &fieldLeftGoalLeftPost, const Position &fieldLeftGoalRightPost, const Position &fieldRightGoalLeftPost, const Position &fieldRightGoalRightPost);
    void setFieldPenaltiesMark(const Position &fieldLeftPenaltyMark, const Position &fieldRightPenaltyMark);
    void setFieldCenterRadius(const float fieldCenterRadius);
    void setGoalArea(const float areaLenght, const float areaWidth, const float areaRoundedRadius);
    void setGoalDepth(const float goalDepth);

    // Checks if the sensor is connected to the server
    bool isSensorConnected();

private:
    // GEARSystem sensor object
    Sensor _sensor;
};

#endif // SENSORINTERFACE_HH
