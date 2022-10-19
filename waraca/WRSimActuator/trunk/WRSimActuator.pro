#
# Warthog Robotics
# University of Sao Paulo (USP) at Sao Carlos
# http://www.warthog.sc.usp.br/
#
# This file is part of WRSimActuator project.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# Application info
TEMPLATE = app
DESTDIR = bin
TARGET = WRSimActuator
VERSION = 1.0.2
CONFIG += c++14

# Qt config
CONFIG += console
CONFIG -= app_bundle
QT += core network

# Optimization flags
QMAKE_CXXFLAGS  -= -O -O1
QMAKE_CXXFLAGS  += -O2

# GEARSystem info
LIBS += -lomniORB4 \
    -lomnithread \
    -lGEARSystem \
    -lprotobuf

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Source files
INCLUDEPATH *= . src

SOURCES += \
    src/3rdparty/protobuf/grSim_Commands.pb.cc \
    src/3rdparty/protobuf/grSim_Packet.pb.cc \
    src/3rdparty/protobuf/grSim_Replacement.pb.cc \
    src/WRSimActuator/utils/wrtimer.cc \
    src/WRSimActuator/exithandler.cc \
    src/WRSimActuator/packethandler.cc \
    src/main.cc \
    src/WRSimActuator/utils/color.cc

# Header files
HEADERS  += \
    src/3rdparty/protobuf/grSim_Commands.pb.h \
    src/3rdparty/protobuf/grSim_Packet.pb.h \
    src/3rdparty/protobuf/grSim_Replacement.pb.h \
    src/WRSimActuator/utils/wrtimer.hh \
    src/WRSimActuator/exithandler.hh \
    src/WRSimActuator/packethandler.hh \
    src/WRSimActuator/utils/color.hh

# Other files
DISTFILES += \
    pre-build.sh \
    protobuf.sh \
    LICENSE
