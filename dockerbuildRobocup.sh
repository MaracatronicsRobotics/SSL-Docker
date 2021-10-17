# Avoid errors with video

# Building docker
docker build . -f DockerfileRobocup -t maracatronics-ssl-robocupinfra:larc2021 --build-arg GIT_TOKEN=$1
