# API

-   [Introduction](#introduction)
-   [OCB Curl commands](#ocb-curl-commands)

## Introduction

This is a very simple API since this ROSE-AP is a firmware component. This means that it doesn't have an API per se. However, the component assumes a connection with an Orion Context Broker so we will include curl commands.

## OCB Curl commands

Check the MDuino device type in OCB:
```console
curl --location --request GET 'http://${ORION_IP}:1026/v2/entities?type=MDuino' \
--header 'fiware-service: openiot' \
--header 'fiware-servicepath: /'
```
Output:
```json
[
    {
        "id": "MDuino_1",
        "type": "MDuino",
        "Input_0": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        },
        "Input_1": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        },
        "Input_2": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        },
        "Input_3": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        },
        "Input_4": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        },
        "Input_5": {
            "type": "Integer",
            "value": 0,
            "metadata": {}
        }
    }
]
```
