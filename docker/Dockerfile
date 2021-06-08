FROM ubuntu

ENV ARDUINO_MAC=0x90,0xA2,0xDA,0x10,0x00,0x99 \
  ARDUINO_IP=0,0,0,0 \
  ORION_IP=0,0,0,0 \
  ORION_PORT=1026 \
  ENTITY_TYPE=MDuino \
  ENTITY_ID=MDuino_1 \
  FIWARE_SERVICE=openiot \
  FIWARE_SERVICE_PATH=/ \
  POLLING_TIME=10000

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
  git \
  curl \
  build-essential \
  libelf-dev \
  avr-libc \
  gcc-avr \
  freeglut3-dev \
  libncurses5-dev \
  pkg-config \
  gettext-base

RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

RUN arduino-cli core install industrialshields:avr --additional-urls http://apps.industrialshields.com/main/arduino/boards/package_industrialshields_index.json

WORKDIR /demo

RUN git clone https://github.com/ramp-eu/AGILPLAS.git

RUN envsubst < AGILPLAS/src/main/main.ino > AGILPLAS/src/main/main.ino

RUN git clone https://github.com/buserror/simavr.git && \
  cd simavr && make && cd ..
