FROM robocupssl/ubuntu-vnc:latest



ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=America/Sao_Paulo
USER root

RUN set -ex \
    && apt-get update \
    && apt-get upgrade -y



# dependencies
RUN set -ex \
    && apt-get install -y \
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
    
# Taking GIT_TOKEN arg
ARG GIT_TOKEN

# Moving to workdir
WORKDIR /app
RUN chown default:default /app
USER default

RUN cd /app && \
    git clone https://github.com/MaracatronicsRobotics/SSL-Docker.git


# GEARSystem
RUN cd /app && \
    git clone https://github.com/MaracatronicsRobotics/GEARSystem.git && \
    cd GEARSystem/trunk && \
    sh build/corba_skeletons.sh && \    
    qmake install_path=/usr/lib && \
    make -j4

USER root
RUN cd /app/GEARSystem/trunk && sh install.sh  
USER default    


# WRBackbone
RUN cd /app && \
    git clone https://github.com/MaracatronicsRobotics/WRBackbone.git && \
    cd WRBackbone/trunk && \
    mkdir build && cd build && \
    qmake .. && \
    make -j4
    
# Armorial-Actuator
RUN cd /app && \
    git clone https://$GIT_TOKEN:x-oauth-basic@github.com/MaracatronicsRobotics/Armorial-Actuator.git && \
    cd Armorial-Actuator && \
    mkdir build && cd build && \
    qmake .. && \
    make -j4

# Armorial-Carrero
RUN cd /app && \
    git clone https://$GIT_TOKEN:x-oauth-basic@github.com/MaracatronicsRobotics/Armorial-Carrero.git && \
    cd Armorial-Carrero && \
    mkdir build && cd build && \
    qmake .. && \
    make -j4
    
# Suassuna
RUN cd /app && \
    git clone https://$GIT_TOKEN:x-oauth-basic@github.com/MaracatronicsRobotics/Suassuna-SSL-Cangaco.git && \
    cd Suassuna-SSL-Cangaco && \
    mkdir build && cd build && \
    qmake .. && \
    make -j4

ENTRYPOINT /bin/bash -c 'mkdir -p /app/log/omniORB/ && /usr/bin/omniNames -start -always -logdir /app/log/omniORB/ -errlog /app/log/omniORB/error.log & /app/WRBackbone/trunk/build/bin/WRBackbone & /docker/startup.sh'


