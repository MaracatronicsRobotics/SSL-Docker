# Avoid errors with video
xhost +local:docker

# Building docker
docker build . -f Dockerfile -t warthog-ssl
