# Avoid errors with video

# Building docker
docker build . -f Dockerfile -t maracatronics-ssl --build-arg GIT_TOKEN=$1
