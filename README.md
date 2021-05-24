## Requirements for the Mid-Term Review: [here](docs/README.md)
<hr />

# AGILPLAS ROSE-AP

[![License: MIT](https://img.shields.io/github/license/ramp-eu/TTE.project1.svg)](https://opensource.org/licenses/MIT)
[![Docker badge](https://img.shields.io/docker/pulls/ramp-eu/TTE.project1.svg)](https://hub.docker.com/r/<org>/<repo>/)
<br/>
[![Documentation Status](https://readthedocs.org/projects/tte-project1/badge/?version=latest)](https://tte-project1.readthedocs.io/en/latest/?badge=latest)
[![Build badge](https://img.shields.io/travis/ramp-eu/TTE.project1.svg)](https://travis-ci.org/ramp-eu/TTE.project1/)
[![Coverage Status](https://coveralls.io/repos/github/ramp-eu/TTE.project1/badge.svg?branch=master)](https://coveralls.io/github/ramp-eu/TTE.project1?branch=master)
[![Codacy grade](https://img.shields.io/codacy/grade/99310c5c4332439197633912a99d2e3c)](https://app.codacy.com/manual/jason-fox/TTE.project1)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/4885/badge)](https://bestpractices.coreinfrastructure.org/projects/4885)

```text

The Badges above demonstrate testing, code coverage
and commitment to coding standards (since the code is linted on commit).

The links need to be amended to point to the correct repo.

Sign up for:

- CI Test system - e.g. Travis
- A Documentation website - e.g. ReadTheDocs
- Static Code Analysis tool - e.g. Codacy
- CII Best Practices https://bestpractices.coreinfrastructure.org

Only CII Best Practices (and its badge) is mandatory. Any equivalent public automated tools for the other three may be used.

Note that the CII Best Practices questionaire will request evidence of tooling used.

```

This ROSE-AP is a bridge that connects M-DUINO PLCs with NGSI Context Brokers.

This project is part of [DIH^2](http://www.dih-squared.eu/). For more information check the RAMP Catalogue entry for the
[components](https://github.com/xxx).

| :books: [Documentation](https://tte-project1.readthedocs.io/en/latest/) | :whale: [Docker Hub](https://hub.docker.com/r/link-to-docker) |
| --------------------------------------------- | ------------------------------------------------------------- |


## Contents

-   [Background](#background)
-   [Install](#install)
-   [Usage](#usage)
-   [API](#api)
-   [Testing](#testing)
-   [License](#license)

## Background

An M-DUINO PLC is a robust piece of hardware designed to work in industrial environments. It can read and write data through digital, relay and analog pins; and has an underlying programmable Arduino board. The repository contains the necessary firmware to program and control the device’s behaviour. This firmware is Arduino (C++) code.

A general schematic of the architecture can be seen below:

<p align="center">
    <img src="img/architecture.png" title="Architecture" alt="Architecture" width="80%">
</p>

- **Digital/analog inputs:** the M-DUINO resides in the electrical panel where it's linked to the desired digital or analog inputs. Each input goes into one of the pins. These pins will then be managed with the firmware.

- **Arduino IDE:** open-source Arduino Software where the firmware is developed, configured and uploaded onto the board. USB-B is the standard for both firmware uploading and serial communication with the board.

- **Orion Context Broker (OCB):** the data collected by the M-DUINO is forwarded towards an OCB which holds this information as an entity. This is achieved via the NGSIv2 REST API. OCB then acts as a central hub where other applications can manipalute its context information.

## Install

```text
How to install the component

Information about how to install the <Name of component> can be found at the corresponding section of the
[Installation & Administration Guide](docs/installationguide.md).

A `Dockerfile` is also available for your use - further information can be found [here](docker/README.md)

```

## Usage

```text
How to use the component

Information about how to use the <Name of component> can be found in the [User & Programmers Manual](docs/usermanual.md).

The following features are listed as [deprecated](docs/deprecated.md).
```

## API

```text
Definition of the API interface:

Information about the API of  the <Name of component> can be found in the [API documentation](docs/api.md).

```

## Testing

```text
How to test the component

For performing a basic end-to-end test, you have to follow the step below. A detailed description about how to run tests can be found [here].

> npm test

```

## License

[MIT](LICENSE) © <TTE>
