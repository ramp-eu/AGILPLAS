# Step by Step tutorial

-   [Introduction](#introduction)
-   [Dependencies](#dependencies)
-   [Simulation](#simulation)

## Introduction

This guide will cover, step-by-step, a demo for this ROSE-AP.

As commented throughout this documentation, this repository is mainly composed of firmware for an M-DUINO PLC. All of the development has been done with the physical device connected to the computer via USB-B as can be seen in the [architecture](architecture.md).

However, if one doesn't have access to the physical hardware, this guide offers a simulation.

## Dependencies

- **arduino-cli**: a command line interface which implements all of the Arduino IDE. It lets us compile and upload our code. Check its documentation [here](https://arduino.github.io/arduino-cli/latest/).

- **simavr**: an AVR simulator that uses avr-gcc. In order to simplify things, we use it to replicate the M-DUINO's underlying Arduino board and run our firmware. Check its repository [here](https://github.com/buserror/simavr).

## Simulation

1. First we need to pull the Docker image hosted in Docker Hub. Further documentation on the image and a guide to build your own can be found [here](/docker/README.md). This image has all of the necessary dependencies installed.

```console
docker pull jaclavijo/agilplas
```


2. Now we run the container and execute an interactive shell inside it.

```console
docker run -it --name demo jaclavijo/agilplas
```

Inside the container's demo directory we find two directories:
- `AGILPLAS`  which contains the repository code.
- `simavr`  which contains the Arduino core simulator.

3. Compile the firmware using arduino-cli with the `-e` flag which will export the binaries compiled (needed for the next step).

```console
arduino-cli compile -e -b industrialshields:avr:mduino AGILPLAS/src/main/main.ino
```

4. Run the simulation using simavr and the compiled .ELF file:

```console
simavr/simavr/run_avr -m atmega2560 -f 16000000 AGILPLAS/src/main/build/industrialshields.avr.mduino/main.ino.elf
```

Output:

Initial configuration:
```console
Loaded 16126 .text at address 0x0
Loaded 744 .data
----- Input Configuration:..
Input-> reference: 2, alias: Input_0..
Input-> reference: 3, alias: Input_1..
Input-> reference: 54, alias: Input_2..
Input-> reference: 55, alias: Input_3..
Input-> reference: 56, alias: Input_4..
Input-> reference: 57, alias: Input_5..
Local IP:0..
```
The digital inputs are then read:
```
----- Reading digital inputs..
----- Digital inputs read..
```
And finally the read inputs are sent towards an OCB:
```
----- Sending Data to OCB..
POST /v2/op/update HTTP/1.1..
{..
  "actionType": "append",..
  "entities": [..
    {..
      "type": "MDuino",..
      "id": "MDuino_1",..
      "Input_0": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_1": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_2": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_3": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_4": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_5": {..
        "value": 0,..
        "type": "Integer"..
      }..
    }..
  ]..
}..
ERROR: Connection to OCB @ 0.0.0.0:1026 failed..

```

As we can see, the connection fails. This is due to not being able to simulate the Ethernet Arduino library with the AVR. This one of the possible improvements of the simulation.

5. For the moment we only read 0s from the digital inputs, but we can simulate random reads apllying [this patch](src\0001-io-generate-random-values-when-reading-IOs.patch) to the simavr implementation.

```console
cd simavr
```
```console
git apply /demo/AGILPLAS/src/0001-random-values.patch
```
```console
make
```

6. Now we can repeat the simulation and see random input values.

```console
simavr/simavr/run_avr -m atmega2560 -f 16000000 AGILPLAS/src/main/build/industrialshields.avr.mduino/main.ino.elf
```

Output:

```
----- Sending Data to OCB..
POST /v2/op/update HTTP/1.1..
{..
  "actionType": "append",..
  "entities": [..
    {..
      "type": "MDuino",..
      "id": "MDuino_1",..
      "Input_0": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_1": {..
        "value": 1,..
        "type": "Integer"..
      },..
      "Input_2": {..
        "value": 1,..
        "type": "Integer"..
      },..
      "Input_3": {..
        "value": 0,..
        "type": "Integer"..
      },..
      "Input_4": {..
        "value": 1,..
        "type": "Integer"..
      },..
      "Input_5": {..
        "value": 0,..
        "type": "Integer"..
      }..
    }..
  ]..
}..
ERROR: Connection to OCB @ 0.0.0.0:1026 failed..

```
