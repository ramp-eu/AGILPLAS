# README.md for DockerHub

## Introduction

This section assumes you have Docker installed. If not, check the [installation guide](/docs/installationguide.md).

This ROSE-AP classifies as firmware which has been developed with a physical M-DUINO. In order to dockerize this experience, a simulator image has been developed. The simulation consists of two main tools:

- **arduino-cli**: a command line interface which implements all of the Arduino IDE. It lets us compile and upload our code. Check its documentation [here](https://arduino.github.io/arduino-cli/latest/).

- **simavr**: an AVR simulator that uses avr-gcc. In order to simplify things, we use it to replicate the M-DUINO's underlying Arduino board and run our firmware. Check its repository [here](https://arduino.github.io/arduino-cli/latest/).

## Built image

You can find an already built image [here](https://hub.docker.com/r/jaclavijo/agilplas). You can pull it with the following command:

```console
docker pull jaclavijo/agilplas:latest
```

This image has arduino-cli and simavr already installed and a clone of this repository.

Check out the [Step by Step tutorial](/docs/stepbystep.md) which uses it.

## Build your own image

The [Dockerfile](Dockerfile) associated with the previous image can be used to build your own image.

```console
docker build -t <component> .
```

This is advised if you want to edit the default environment variables of the repo:
```dockerfile
ENV ARDUINO_MAC=0x90,0xA2,0xDA,0x10,0x00,0x99 \
  ARDUINO_IP=0,0,0,0 \
  ORION_IP=0,0,0,0 \
  ORION_PORT=1026 \
  ENTITY_TYPE=MDuino \
  ENTITY_ID=MDuino_1 \
  FIWARE_SERVICE=openiot \
  FIWARE_SERVICE_PATH=/ \
  POLLING_TIME=10000
```
