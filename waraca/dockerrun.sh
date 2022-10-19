# Taking default values
WORK_DIR=`pwd`
CONTAINER_WORK_DIR="/home/"
CONTAINER_NAME="warthog-ssl-container"
DOCKER_IMAGE="warthog-ssl"

# Running docker
docker run  -it \
            --rm \
            --name=$CONTAINER_NAME \
            --net=host \
            --privileged \
            --workdir="${CONTAINER_WORK_DIR}" \
            --volume="/dev:/dev" \
            --volume="${WORK_DIR}/WRSimActuator:${CONTAINER_WORK_DIR}/WRSimActuator" \
            -v $HOME/.Xauthority:/root/.Xauthority \
            $DOCKER_IMAGE
