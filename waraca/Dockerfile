FROM ubuntu:20.04

RUN apt-get update
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata

# dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    nano \
    cmake \
    git \
    qt5-default \
    sudo \
    wget \
    omniorb \
    omniidl \
    omniorb-nameserver \
    libomniorb4-dev \
    libprotobuf-dev \
    protobuf-compiler \
    freeglut3-dev \
    libgl1-mesa-dev \
    libglm-dev \
    libglew1.5-dev \
    && apt-get clean

# Moving to workdir
WORKDIR /home

# GEARSystem
RUN cd /home && \
    git clone https://github.com/MaracatronicsRobotics/GEARSystem.git && \
    cd GEARSystem/trunk && \
    sh build/corba_skeletons.sh && \
    qmake install_path=/usr/lib && \
    make -j4 && \
    sudo sh install.sh
