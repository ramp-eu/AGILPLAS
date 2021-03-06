# Installation & Administration Guide

-   [Installation](#installation)
    -   [Docker](#docker)
    -   [Arduino IDE](#arduino-ide)
    -   [Orion Context Broker](#orion-context-broker)
-   [Configuration](#configuration)
-   [Usage](#usage)


## Installation

#### Docker

In case you don't have an M-DUINO PLC to work with we have developed a dockerized simulation.
If you don't have Docker you can install it [here](https://docs.docker.com/get-docker/).

#### Arduino IDE

**This can only be used if you have an M-DUINO. If not, check the [Step by Step](stepbystep.md) for a dockerized simulation.**

It's the main tool to write and upload code to the M-DUINO board.
Download [here](https://www.arduino.cc/en/software).

#### Orion Context Broker

It is encouraged to use the official [Orion docker container at dockerhub](https://hub.docker.com/r/fiware/orion/). Other alternatives can be found [here](https://fiware-orion.readthedocs.io/en/master/admin/install/index.html#installing-orion).




## Configuration

#### Arduino IDE for M-DUINO

**[Arduino IDE board installation guide](https://www.industrialshields.com/first-steps-with-the-industrial-arduino-based-plc-s-and-the-panel-pc-s-raspberry-pi-based#boards)**.

For easier code development, Arduino IDE offers a boards manager where we can install our specific M-DUINO model and the PLC inputs will be automatically mapped to more readable references like `I0_0` for the digital input I0.0 of our physical board.

## Usage

#### Arduino IDE for M-DUINO

This link contains a simple guide to use the mapped M-DUINO pins alongside a basic TCP Client. Although we will go into further detail about the Arduino code in the [User & Programmers Manual](usermanual.md).
