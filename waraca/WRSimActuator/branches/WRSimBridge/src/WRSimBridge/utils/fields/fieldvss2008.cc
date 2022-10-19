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

#include <WRSimBridge/utils/fields/fieldvss2008.hh>

using namespace Fields;

QString VSS2008::name() const {
    return "VSS 2008";
}

float VSS2008::length() const {
    return 1.50;
}

float VSS2008::width() const {
    return 1.30;
}

float VSS2008::goalWidth() const {
    return 0.40;
}

float VSS2008::goalDepth() const {
    return 0.10;
}

float VSS2008::centerRadius() const {
    return 0.20;
}

float VSS2008::defenseRadius() const {
    return 0.15;
}

float VSS2008::defenseStretch() const {
    return 0.40;
}

GEARSystem::Position VSS2008::fieldBottomLeftCorner() const {
    return GEARSystem::Position(true, -0.75, -0.65, 0.0);
}

GEARSystem::Position VSS2008::fieldBottomRightCorner() const {
    return GEARSystem::Position(true, 0.75, -0.65, 0.0);
}

GEARSystem::Position VSS2008::fieldCenter() const {
    return GEARSystem::Position(true, 0.0, 0.0, 0.0);
}

GEARSystem::Position VSS2008::fieldTopLeftCorner() const {
    return GEARSystem::Position(true, 0.75, -0.65, 0.0);
}

GEARSystem::Position VSS2008::fieldTopRightCorner() const {
    return GEARSystem::Position(true, 0.75, 0.65, 0.0);
}

GEARSystem::Position VSS2008::fieldLeftGoalLeftPost() const {
    return GEARSystem::Position(true, -0.75, -0.20, 0.0);
}

GEARSystem::Position VSS2008::fieldLeftGoalRightPost() const {
    return GEARSystem::Position(true, -0.75, 0.20, 0.0);
}

GEARSystem::Position VSS2008::fieldRightGoalLeftPost() const {
    return GEARSystem::Position(true, 0.75, 0.20, 0.0);
}

GEARSystem::Position VSS2008::fieldRightGoalRightPost() const {
    return GEARSystem::Position(true, 0.75, -0.20, 0.0);
}

GEARSystem::Position VSS2008::fieldLeftPenaltyMark() const {
    return GEARSystem::Position(true, -0.375, 0.0, 0.0);
}

GEARSystem::Position VSS2008::fieldRightPenaltyMark() const {
    return GEARSystem::Position(true, 0.375, 0.0, 0.0);
}
