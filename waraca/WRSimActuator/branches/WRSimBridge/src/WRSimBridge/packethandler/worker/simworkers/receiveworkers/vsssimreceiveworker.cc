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

#include <WRSimBridge/packethandler/worker/simworkers/receiveworkers/vsssimreceiveworker.hh>
#include <WRSimBridge/utils/color/color.hh>
#include <iostream>

// The CM means centimeter
#define FIELD_HALF_LENGHT_CM 85
#define FIELD_HALF_WIDTH_CM 65
#define BALL_NUMBER 0
#define TEAM_SIZE 3

// Constructor
VSSSimReceiveWorker::VSSSimReceiveWorker(zmq::socket_t *socketReceiveState) {
    // Sets the vision socket
    _socketReceiveState = socketReceiveState;
}

// In this method there is no need to control the speed of the main loop because it will only executes when
// a new packet arrives, because zmq waits for the nest request from client on the method "receiveState"
void VSSSimReceiveWorker::startWorking() {

    // Set all field dimensions on sensor
    setFieldDimentions();

    // Creates an protobuf object to use to get the vision data sent from the sim
    vss_state::Global_State globalState;

    // Add a ball on sensor
    _sensorInterface.addBall(0);

    // Add two teams on sensor
    _sensorInterface.addTeam(Colors::YELLOW, "WR1");
    _sensorInterface.addTeam(Colors::BLUE, "WR2");

    // Add two VSS Teams on sensor
    for(int i = 0; i < TEAM_SIZE; i++) {
        _sensorInterface.addPlayer(Colors::YELLOW, i);
        _sensorInterface.addPlayer(Colors::BLUE, i);
    }

    // Objects to store the ball data
    Position ballPosition;
    Velocity ballVelocity;

    // Objects to store the robot data
    Position robotPosition;
    Velocity robotVelocity;
    AngularSpeed robotAngularSpeed;
    Angle robotOrientation;

    // Main loop
    while(isRunning()) {

        if(isConnected()) {

            // Refresh data
            receiveState(globalState);

            // ??? Their viewer does this I do not know why
            globalState.id();

            // Get the information about the ball and store on ballPosition and ballVelocity
            getBallPositionAndVelocity(ballPosition, ballVelocity, globalState);

            // Set the info obtained info about the ball on the sensor
            _sensorInterface.setBallPosition(BALL_NUMBER, ballPosition);
            _sensorInterface.setBallVelocity(BALL_NUMBER, ballVelocity);

            // Loop through the robots
            for(int id = 0; id < TEAM_SIZE; id++) {

                // Get info about the Position, Orientation, Velocity and AngularSpeed of a yellow robot and store on the passed objects
                getRobotPositionAndOrientation(id, Colors::YELLOW, robotPosition, robotOrientation, globalState);
                getRobotVelocityAndAngularSpeed(id, Colors::YELLOW, robotVelocity, robotAngularSpeed, globalState);

                // Set the obtained info of the robot on the sensor
                _sensorInterface.updatePlayerStatus(id, Colors::YELLOW, robotPosition, robotOrientation, robotVelocity, robotAngularSpeed);

                // Get info about the Position, Orientation, Velocity and AngularSpeed of a blue robot and store on the passed objects
                getRobotPositionAndOrientation(id, Colors::BLUE, robotPosition, robotOrientation, globalState);
                getRobotVelocityAndAngularSpeed(id, Colors::BLUE, robotVelocity, robotAngularSpeed, globalState);

                // Set the obtained info of the robot on the sensor
                _sensorInterface.updatePlayerStatus(id, Colors::BLUE, robotPosition, robotOrientation, robotVelocity, robotAngularSpeed);
            }
        }
    }

    emit finishedWorking();
}

// Checks the connection with the simulator and between the sensor and the server
bool VSSSimReceiveWorker::isConnected() {
    return (_socketReceiveState->connected() && _sensorInterface.isSensorConnected());
}

void VSSSimReceiveWorker::getBallPositionAndVelocity(Position &ballPosition, Velocity &ballVelocity, const vss_state::Global_State &globalState) {
    float ballX;
    float ballY;

    float ballVelX;
    float ballVelY;

    // Get the ball position and adequate it to our center of coordinates. The simulator (0,0) DOES NOT stay on the field center
    ballX = globalState.balls(BALL_NUMBER).pose().x() - FIELD_HALF_LENGHT_CM;
    ballY = globalState.balls(BALL_NUMBER).pose().y() - FIELD_HALF_WIDTH_CM;

    // Transform from centimeters to meters
    ballX = ballX/100;

    // Transform from centimeters to meters
    // The sim mirrors the Y axis, thats why we have to use "/-100"
    ballY = ballY/-100;
    // Set the "ballPosition"
    ballPosition.setPosition(ballX, ballY, 0.0);

    // Get ball velocity
    ballVelX = globalState.balls(BALL_NUMBER).v_pose().x();
    ballVelY = globalState.balls(BALL_NUMBER).v_pose().y();

    // Convert the velocity from centimeters to meters
    ballVelX = ballVelX/100;

    // Convert the velocity from centimeters to meters
    // The sim mirrors the Y axis, thats why we have to use "/-100"
    ballVelY = ballVelY/-100;

    // Set the "ballVelocity"
    ballVelocity.setVelocity(ballVelX, ballVelY);
}

void VSSSimReceiveWorker::getRobotPositionAndOrientation(int robotNumber, int robotTeam, Position &robotPosition, Angle &robotOrientation, const vss_state::Global_State &globalState) {
    float robotPosX;
    float robotPosY;
    float robotOri;

    // Get the robot coordinates and orientation and adequate them to our field center (just the position in this case)
    if(robotTeam == Colors::YELLOW) {
        robotPosX = globalState.robots_yellow(robotNumber).pose().x() - FIELD_HALF_LENGHT_CM;
        robotPosY = globalState.robots_yellow(robotNumber).pose().y() - FIELD_HALF_WIDTH_CM;
        robotOri = globalState.robots_yellow(robotNumber).pose().yaw();
    } else {
        robotPosX = globalState.robots_blue(robotNumber).pose().x() - FIELD_HALF_LENGHT_CM;
        robotPosY = globalState.robots_blue(robotNumber).pose().y() - FIELD_HALF_WIDTH_CM;
        robotOri = globalState.robots_blue(robotNumber).pose().yaw();
    }

    // Transform from centimeters to meters
    robotPosX = robotPosX/100;

    // Transform from centimeters to meters
    // The sim mirrors the Y axis, thats why we have to use "/-100"
    robotPosY = robotPosY/-100;

    // Their simulator has a simetric reference to the orientation, so we have to invert it
    robotOri = -robotOri;

    // Sets "robotPosition"
    robotPosition.setPosition(robotPosX, robotPosY, 0.0);

    // Sets "robotOrientation"
    robotOrientation.setValue(robotOri);
}

void VSSSimReceiveWorker::getRobotVelocityAndAngularSpeed(int robotNumber, int robotTeam, Velocity &robotVelocity, AngularSpeed &robotAngularSpeed, const vss_state::Global_State &globalState) {

    float robotVelX;
    float robotVelY;
    float robotAngSpeed;

    // Get robot velocity and angular speed information
    if(robotTeam == Colors::YELLOW) {
        robotVelX = globalState.robots_yellow(robotNumber).v_pose().x();
        robotVelY = globalState.robots_yellow(robotNumber).v_pose().y();
        robotAngSpeed = globalState.robots_yellow(robotNumber).v_pose().yaw();
    } else {
        robotVelX = globalState.robots_blue(robotNumber).v_pose().x();
        robotVelY = globalState.robots_blue(robotNumber).v_pose().y();
        robotAngSpeed = globalState.robots_blue(robotNumber).v_pose().yaw();
    }

    // Transform from centimeters to meters
    robotVelX = robotVelX/100;

    // Transform from centimeters to meters
    // The sim mirrors the Y axis, thats why we have to use "/-100"
    robotVelY = robotVelY/-100;

    // Sets the objects "robotVelocity" and "robotAngularSpeed"
    robotVelocity.setVelocity(robotVelX, robotVelY);
    robotAngularSpeed.setValue(robotAngSpeed);
}

void VSSSimReceiveWorker::setFieldDimentions() {
    _sensorInterface.setFieldBottomLeftCorner(_field.fieldBottomLeftCorner());
    _sensorInterface.setFieldBottomRightCorner(_field.fieldBottomRightCorner());
    _sensorInterface.setFieldCenter(_field.fieldCenter());
    _sensorInterface.setFieldTopLeftCorner(_field.fieldTopLeftCorner());
    _sensorInterface.setFieldTopRightCorner(_field.fieldTopRightCorner());
    _sensorInterface.setGoalPosts(_field.fieldLeftGoalLeftPost(), _field.fieldLeftGoalRightPost(),
                                  _field.fieldRightGoalLeftPost(), _field.fieldRightGoalRightPost());
    _sensorInterface.setFieldPenaltiesMark(_field.fieldLeftPenaltyMark(), _field.fieldRightPenaltyMark());
    _sensorInterface.setFieldCenterRadius(_field.centerRadius());
    _sensorInterface.setGoalArea(_field.defenseLength(), _field.defenseWidth(), 0.0); // Rounded Radius on VSS is equal to 0 indeed
    _sensorInterface.setGoalDepth(_field.goalDepth());
}

void VSSSimReceiveWorker::receiveState(vss_state::Global_State &globalState) {
    zmq::message_t request;
    _socketReceiveState ->recv(&request, 0); //  Wait for next request from client
    std::string msg_str(static_cast<char*>(request.data()), request.size());
    globalState.ParseFromString(msg_str);
}
