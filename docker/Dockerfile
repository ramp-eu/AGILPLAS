FROM ubuntu

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
