///////////////////////////////////////////////////////////////////
// LIBRARIES
///////////////////////////////////////////////////////////////////
#include "Ethernet.h"
#include "Input/Input.hpp"
#include "Input/Input.cpp"
///////////////////////////////////////////////////////////////////
// ETHERNET
///////////////////////////////////////////////////////////////////
// Configure your mac and local IP for the Ethernet library
// https://www.arduino.cc/en/Reference/EthernetBegin
byte mac[] = {${ARDUINO_MAC}};
IPAddress myIP (${ARDUINO_IP});
// IPAddress myDNS (8, 8, 8, 8);
// IPAddress myGATEWAY (128, 64, 10, 1);
// IPAddress mySUBNET (255, 255, 255, 0);
EthernetClient ethClient;
///////////////////////////////////////////////////////////////////
// GLOBAL CONFIGURABLE VARIABLES
///////////////////////////////////////////////////////////////////
// When selecting the correct M-Duino model, Arduino IDE maps inputs with the IX_X syntax.
// Each digital input must have an alias. This alias determines the OCB entity attribute name.

const Input* inputs[] = {
    new Input(I0_0, "Input_0"),
    new Input(I0_1, "Input_1"),
    new Input(I0_2, "Input_2"),
    new Input(I0_3, "Input_3"),
    new Input(I0_4, "Input_4"),
    new Input(I0_5, "Input_5")
};

// Configure your OCB instance IP
const IPAddress orionIP (${ORION_IP});
const int orionPort = ${ORION_PORT};

const String entityType = ${ENTITY_TYPE};
const String entityId = ${ENTITY_ID};
const String fiwareService = ${FIWARE_SERVICE};
const String fiwareServicePath = ${FIWARE_SERVICE_PATH};

const int POLLING_TIME = ${POLLING_TIME};

///////////////////////////////////////////////////////////////////
// SETUP
///////////////////////////////////////////////////////////////////
unsigned long readMillis = 0;
const int INPUTS_SIZE = sizeof(inputs) / sizeof(inputs[0]);
int readInputs[INPUTS_SIZE] = {};
const String orionIPString = String(orionIP[0]) + "." + orionIP[1] + "." + orionIP[2] + "." + orionIP[3] + ":" + orionPort;

void setup() {
    Serial.begin(9600); // Start serial data transmission with the data rate in baud

    Serial.println("----- Input Configuration:");
    for (int i = 0; i < INPUTS_SIZE; i++) {
        // Set the digital pins as inputs
        pinMode(inputs[i]->getReference(), INPUT);
        inputs[i]->serialPrint();
    }

    Ethernet.begin(mac, myIP);
    // Ethernet.begin(mac, myIP, myDNS, myGATEWAY, mySUBNET);


    // Future interrupt-capable IOs extension, Reference: http://gammon.com.au/interrupts
    // attachInterrupt (digitalPinToInterrupt(BUTTON), switchPressed, CHANGE);  // attach interrupt handler

    Serial.println("Local IP:" + String(Ethernet.localIP()));
}
///////////////////////////////////////////////////////////////////
// LOOP
///////////////////////////////////////////////////////////////////
void loop() {
    readData();

    sendData();

    // Delay time is calculated taking into account that sendData() takes time.
    // If it takes longer than the polling time itself, don't delay at all.
    int delayTime = POLLING_TIME - (millis() - readMillis);
    delay(delayTime > 0 ? delayTime : 0);
}
