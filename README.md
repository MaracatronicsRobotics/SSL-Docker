# SSL-Docker

This repository contains all instructions and scripts to build Maracatronics' SSL Docker image and deploy them to WR Docker Registry System or Dockerhub.

## Deploying to Dockerhub

```shell
# To build the image

sh dockerbuildRobocup.sh [GIT-TOKEN]

# To deploy

sh deployDockerhubMRC.sh

```

## Deploying to WR's Registry

```shell
# To build the image

sh dockerbuildRobocup.sh [GIT-TOKEN]

# To deploy

sh deployRegistryWR.sh

```