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

#include <WRSimBridge/utils/fields/fields.hh>
#include <GEARSystem/Types/position.hh>

namespace Fields {

class VSS2008 : public Field {
public:
    QString name() const;

    // Sizes related to the very small size IEEE (2008) field
    float length() const;
    float width() const;
    float goalWidth() const;
    float goalDepth() const;
    float centerRadius() const;
    float defenseRadius() const;
    float defenseStretch() const;

    // Positions of the very small size IEEE (2008) field
    // Only use when the simulator does not pass the field dimensions
    GEARSystem::Position fieldBottomLeftCorner() const;
    GEARSystem::Position fieldBottomRightCorner() const;
    GEARSystem::Position fieldCenter() const;
    GEARSystem::Position fieldTopLeftCorner() const;
    GEARSystem::Position fieldTopRightCorner() const;
    GEARSystem::Position fieldLeftGoalLeftPost() const;
    GEARSystem::Position fieldLeftGoalRightPost() const;
    GEARSystem::Position fieldRightGoalLeftPost() const;
    GEARSystem::Position fieldRightGoalRightPost() const;
    GEARSystem::Position fieldLeftPenaltyMark() const;
    GEARSystem::Position fieldRightPenaltyMark() const;
};

}
