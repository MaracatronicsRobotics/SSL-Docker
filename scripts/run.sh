scriptWD=`pwd`

var=$5

sudo rm -rf /var/lib/omniorb/*
sudo service omniorb4-nameserver restart

sleep 1

if [ $5 ];
then

cd /home/Suassuna-SSL-Cangaco/bin
./Armorial-Suassuna --teamColor $2 --teamSide $3 --networkInterface $4 --warthog

else

cd /home/WRBackbone/trunk/build/bin
./WRBackbone &> /dev/null &

sleep 1
cd /home/Armorial-Carrero/bin
./Armorial-Carrero 224.5.23.2 $1 $4 &> /dev/null &

sleep 1

cd /home/Armorial-Actuator/bin
./Armorial-SimActuator &> /dev/null &

sleep 1

cd /home/Suassuna-SSL-Cangaco/bin
./Armorial-Suassuna --teamColor $2 --teamSide $3

fi
