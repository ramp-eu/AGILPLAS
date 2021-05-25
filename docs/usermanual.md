# User & Programmers Manual

-   [Startup](#startup)
-   [Libraries](#libraries)
-   [Variable Configuration](#variable-configuration)
-   [Example](#example)

## Startup

1. Download the code in this repository's `src` folder.

2. Start Arduino IDE and select `File > Open... > main.ino` file. This will open the whole main sketch and both `readData.ino` and `sendData.ino`.

3. Click Tools and make sure the following are selected:
```
Board: "M-Duino family" > Industrial Shields Boards > M-Duino family
Model: "M-Duino 21+"
```
If the boards aren't installed refer to [Arduino IDE board installation guide](https://www.industrialshields.com/first-steps-with-the-industrial-arduino-based-plc-s-and-the-panel-pc-s-raspberry-pi-based#boards).

4. This code is written in Arduino (C++ with some additional features). There are two mandatory functions:
    - [`setup()`](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) is called when a sketch starts.

    - [`loop()`](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) does precisely what its name suggests, and loops consecutively.

    - Check the [language reference](https://www.arduino.cc/reference/en/) for the complete documentation.

5. On top of this functions, this implementation contains:
    - [`Input`](/src/main/Input) class with `reference` and `alias` member variables.

    - [`readData()`](/src/main/readData.ino) function that loops through the digital inputs storing their value.

    - [`sendData()`](/src/main/sendData.ino) function that builds a request with the previously read data. Then sends it towards OCB.
    > /v2/op/update endpoint is used with "append" mode. This will create the entity if it doesn't exist and update its attributes otherwise.

6. Use `Sketch > Verify/Compile` or Ctrl+R to check your code for errors compiling it.

7. Use `Sketch > Upload` or Ctrl+U to compile your code and upload it to the configured board (via USB-B).

8. Use `Tools > Serial Monitor` or Ctrl+Shift+M to open the Serial monitor. This is our main debugging tool.

## Libraries

The only library used is [Ethernet.h](https://www.arduino.cc/en/Reference/Ethernet) to connect to the Internet and be able to use HTTP POST.

## Variable Configuration

- **Ethernet variables**:
```
byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0x00, 0x99};
IPAddress myIP (0, 0, 0, 0);
// IPAddress myDNS (8, 8, 8, 8);
// IPAddress myGATEWAY (128, 64, 10, 1);
// IPAddress mySUBNET (255, 255, 255, 0);
```
These variables are used by the Ethernet.h library to establish an Internet connection. They are used by the `Ethernet.begin(...);` method. [Further information](https://www.arduino.cc/en/Reference/EthernetBegin).

- **Input array**:
```
const Input* inputs[] = {
    new Input(I0_0, "Input_0"),
    new Input(I0_1, "Input_1"),
    ...
};
```
This array contains Input objects which are pairs of (input reference, alias).  
The alias will be used to name this input as an OCB entity attribute. Check the [example](#example).

- **Orion Context Broker variables**:
```
const IPAddress orionIP (0, 0, 0, 0);
const int orionPort = 1026;  
```
```
const String entityType = "MDuino";
const String entityId = "MDuino_1";
const String fiwareService = "openiot";
const String fiwareServicePath = "/";
```
Here we can set the OCB instance IP and port where the data will be POSTed to.  
Alongside we can set both the OCB entity type and id which will represent the device. The fiwareService and fiwareServicePath headers can also be modified at will.  
Check the [example](#example).

- **Polling time**:
```
const int POLLING_TIME = 10000;
```
Milliseconds that will elapse between the input readings.
> **Note**: the fact that sendData() takes time is taken into account. If it takes longer than the polling time itself, then readData() is called right after.

## Example

Consider the following configuration:
```
byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0x00, 0x99};
IPAddress myIP (192, 168, 110, 223);
const Input* inputs[] = {
    new Input(I0_0, "Input_0"),
    new Input(I0_1, "Input_1")
};

const IPAddress orionIP (10, 11, 0, 55);
const int orionPort = 1026;

const String entityType = "MDuino";
const String entityId = "MDuino_1";
const String fiwareService = "openiot";
const String fiwareServicePath = "/";

const int POLLING_TIME = 10000;
```
1. It will set the M-Duino mac and IP as stated.

2. It will poll the inputs referenced by (`I0_0`, `I0_1`) every 10 seconds and then perform the following POST:
```
POST /v2/op/update HTTP/1.1
Content-Type: application/json
fiware-service: openiot
fiware-servicepath: /
Host: 10.11.0.55:1026
Content-Length: 272
{
    "actionType": "append",
    "entities": [
      {
        "type": "MDuino",
        "id": "MDuino_1",
        "Input_0": {
          "value": 0,
          "type": "Integer"
        },
        "Input_1": {
          "value": 0,
          "type": "Integer"
        }
      }
    ]
}
```

3. Now we can check in OCB:
```console
curl --location --request GET 'http://10.11.0.55:1026/v2/entities?type=MDuino'
        --header 'fiware-service: openiot'
        --header 'fiware-servicepath: /'
```
    **Response**:
    ```
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
            }
        }
    ]
    ```
