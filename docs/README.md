# AGILPLAS ROSE-AP

[![License: Apache](https://img.shields.io/github/license/ramp-eu/AGILPLAS.svg)](https://www.apache.org/licenses/LICENSE-2.0.html#redistribution)
[![Documentation Status](https://readthedocs.org/projects/agilplas/badge/?version=latest)](https://agilplas.readthedocs.io/en/latest)
[![CI](https://github.com/ramp-eu/AGILPLAS/actions/workflows/docker.yml/badge.svg)](https://github.com/ramp-eu/AGILPLAS/actions/workflows/docker.yml)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/4885/badge)](https://bestpractices.coreinfrastructure.org/projects/4885)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9bb23f0af38e4a269f35bd910e7fbcec)](https://app.codacy.com/gh/ramp-eu/AGILPLAS?utm_source=github.com&utm_medium=referral&utm_content=ramp-eu/AGILPLAS&utm_campaign=Badge_Grade_Settings)


This ROSE-AP is a bridge that connects M-DUINO PLCs with NGSI Context Brokers.

This project is part of [DIH^2](http://www.dih-squared.eu/). For more information check the RAMP Catalogue entry for the
[components](https://github.com/ramp-eu).

| :books: [Documentation](https://agilplas.readthedocs.io/en/latest) | :whale: [Docker Hub](https://hub.docker.com/r/jaclavijo/agilplas) | :tv: [Step by Step](https://www.youtube.com/watch?v=xCzPRogITBY) |
| --------------------------------------------- | ------------------------------------------------------------- | ------------------------------------------------------------- |


## Contents

-   [Background](#background)
-   [Install](#install)
-   [Usage](#usage)
-   [Getting started](#getting-started)
-   [API](#api)
-   [License](#license)

## Background

#### Use Case Description

AGILPLAS aims to improve the production system of a plastic manufacturer, XIMA, thanks to the use of an IIoT (Industrial Internet of Things) platform based on the use of FIWARE and implemented by Bosonit S.L.

The main problem to be solved is clogging or adhesion of material to the mould in plastic injection processes​, which leads to manual maintenance tasks, affecting productivity​.

#### Proposed Solution

- Real time monitoring of the performance on different scenarios​.
- Set an understanding on conditions that make this problem arise.
- Predictive maintenance system that could anticipate stops in product lines​.

The hardware to be monitored consists of an inyector machine and a robotic arm.

This repository contains the solution to read digital signals directly from the robotic arm.

An M-DUINO PLC is a robust piece of hardware designed to work in industrial environments. It can read and write data through digital, relay and analog pins; and has an underlying programmable Arduino board. The repository contains the necessary firmware to program and control the device’s behaviour. This firmware is Arduino (C++) code.

As a result of the development of this use case, this is a more generic implementation of a FIWARE compatible firmware to persist any signal in an electrical panel towards an OCB.

## Install

Information about how to install the AGILPLAS ROSE-AP can be found at the corresponding section of the [Installation & Administration Guide](installationguide.md).

## Getting started

If you don't have access to a physical M-DUINO PLC, it is recommended to start with the [Step by Step tutorial](stepbystep.md).

Upon completion of the tutorial or if you have the hardware available, an in depth code description can be found in the [User & Programmers Manual](usermanual.md).

## API

A simple API guide can be found [here](api.md).

## License

[Apache 2.0](/LICENSE) © 2021 Bosonit S.L.
