#
# Warthog Robotics
# University of Sao Paulo (USP) at Sao Carlos
# http://www.warthog.sc.usp.br/
# This file is part of WRSimBridge project.
#
# Copyright (C) 2017 Warthog Robotics
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

# Application info
TEMPLATE = app
DESTDIR = bin
TARGET = WRSimBridge
VERSION = 1.0
CONFIG -= c++11

# Qt config
CONFIG += console
CONFIG -= app_bundle
QT += core network widgets

# Optimization flags
QMAKE_CXXFLAGS  -= -O -O1
QMAKE_CXXFLAGS  += -O2 -ansi

# GEARSystem info
LIBS += -lomniORB4 \
    -lomnithread \
    -lzmq \
    -lGEARSystem \
    -lprotobuf

# Temporary dirs
OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc
UI_DIR = tmp/moc
RCC_DIR = tmp/rc

# Source files
INCLUDEPATH *= include

SOURCES += \    
    src/main.cc \
    src/WRSimBridge/exithandler.cc \
    src/WRSimBridge/utils/timer/wrtimer.cc \
    src/WRSimBridge/utils/color/color.cc \
    src/3rdparty/proto/grSim/grSim_Replacement.pb.cc \
    src/3rdparty/proto/grSim/grSim_Packet.pb.cc \
    src/3rdparty/proto/grSim/grSim_Commands.pb.cc \
    src/3rdparty/proto/VSSSim/command.pb.cc \
    src/3rdparty/proto/VSSSim/debug.pb.cc \
    src/3rdparty/proto/VSSSim/state.pb.cc \
    src/WRSimBridge/packethandler/simhandlers/grsimpackethandler.cc \
    src/WRSimBridge/packethandler/packethandler.cc \
    src/WRSimBridge/packethandler/simhandlers/vsssimpackethandler.cc \
    src/WRSimBridge/packethandler/worker/simworkers/sendworkers/grsimsendworker.cc \
    src/WRSimBridge/packethandler/worker/simworkers/receiveworkers/grsimreceiveworker.cc \
    src/WRSimBridge/packethandler/worker/simworkers/sendworkers/vsssimsendworker.cc \
    src/WRSimBridge/packethandler/worker/simworkers/receiveworkers/vsssimreceiveworker.cc \
    src/WRSimBridge/packethandler/worker/simworkers/simsendworker.cc \
    src/WRSimBridge/packethandler/worker/simworkers/simreceiveworker.cc \
    src/WRSimBridge/utils/fields/fields.cc \
    src/WRSimBridge/utils/fields/fieldvss2008.cc \
    src/WRSimBridge/packethandler/worker/simworkers/sensorinterface.cc \
    src/WRSimBridge/packethandler/worker/worker.cc

# Header files
HEADERS  += \
    include/WRSimBridge/packethandler/simhandlers/grsimpackethandler.hh \
    include/WRSimBridge/packethandler/simhandlers/vsssimpackethandler.hh \
    include/WRSimBridge/packethandler/worker/simworkers/receiveworkers/grsimreceiveworker.hh \
    include/WRSimBridge/packethandler/worker/simworkers/receiveworkers/vsssimreceiveworker.hh \
    include/WRSimBridge/packethandler/worker/simworkers/sendworkers/grsimsendworker.hh \
    include/WRSimBridge/packethandler/worker/simworkers/sendworkers/vsssimsendworker.hh \
    include/WRSimBridge/packethandler/worker/simworkers/sensorinterface.hh \
    include/WRSimBridge/packethandler/worker/simworkers/simreceiveworker.hh \
    include/WRSimBridge/packethandler/worker/simworkers/simsendworker.hh \
    include/WRSimBridge/packethandler/worker/worker.hh \
    include/WRSimBridge/packethandler/packethandler.hh \
    include/WRSimBridge/utils/color/color.hh \
    include/WRSimBridge/utils/fields/fields.hh \
    include/WRSimBridge/utils/fields/fieldvss2008.hh \
    include/WRSimBridge/utils/timer/wrtimer.hh \
    include/WRSimBridge/exithandler.hh \
    include/3rdparty/proto/grSim/grSim_Commands.pb.h \
    include/3rdparty/proto/grSim/grSim_Packet.pb.h \
    include/3rdparty/proto/grSim/grSim_Replacement.pb.h \
    include/3rdparty/proto/VSSSim/command.pb.h \
    include/3rdparty/proto/VSSSim/debug.pb.h \
    include/3rdparty/proto/VSSSim/state.pb.h

# Other files
DISTFILES += \
    pre-build.sh \
    protobuf.sh \
    LICENSE
