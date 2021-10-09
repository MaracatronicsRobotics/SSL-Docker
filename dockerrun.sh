
# Taking default values
WORK_DIR=`pwd`
CONTAINER_WORK_DIR="/home/"
CONTAINER_NAME="maracatronics-ssl-container"
DOCKER_IMAGE="maracatronics-ssl"

# Running docker
docker run  -it \
            --rm \
            --name=$CONTAINER_NAME \
            --net=host \
            --privileged \
            --workdir="${CONTAINER_WORK_DIR}" \
            --volume="${WORK_DIR}/scripts/run.sh:${CONTAINER_WORK_DIR}/run.sh" \
            --volume="${WORK_DIR}/scripts/maracatronics.sh:${CONTAINER_WORK_DIR}/runMaraca.sh" \
            --volume="/dev:/dev" \
            -v $HOME/.Xauthority:/root/.Xauthority \
            $DOCKER_IMAGE
