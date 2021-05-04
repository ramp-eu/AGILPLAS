///////////////////////////////////////////////////////////////////
// LIBRARIES
///////////////////////////////////////////////////////////////////
#include "Ethernet.h"

///////////////////////////////////////////////////////////////////
// ETHERNET
///////////////////////////////////////////////////////////////////
byte mac[] = {0x90, 0xA2, 0xDA, 0x10, 0x00, 0x99};
IPAddress myIP (192, 168, 110, 223);
// IPAddress myDNS (8, 8, 8, 8);
// IPAddress myGATEWAY (128, 64, 10, 1);
// IPAddress mySUBNET (255, 255, 255, 0);
EthernetClient ethClient;
///////////////////////////////////////////////////////////////////
// GLOBAL CONFIGURABLE VARIABLES
///////////////////////////////////////////////////////////////////
// When selecting the correct M-Duino model, Arduino IDE maps inputs with the IX_X syntax.
// Each digital input must have an alias. This alias determines the OCB entity attribute name.
const int digitalInputs[] = { I0_0, I0_1, I0_2, I0_3, I0_4, I0_5, I0_6, I0_7, I0_8, I0_9, I0_10, I0_11 };
const String alias[] = { "Input_0", "Input_1", "Input_2", "Input_3", "Input_4", "Input_5", "Input_6", "Input_7", "Input_8", "Input_9", "Input_10", "Input_11" };

const IPAddress orionIP (3, 127, 252, 24);
const int orionPort = 1026;

const String entityType = "MDuino";
const String entityId = "MDuino_1";
const String fiwareService = "openiot";
const String fiwareServicePath = "/";

const int POLLING_TIME = 10000;

///////////////////////////////////////////////////////////////////
// SETUP
///////////////////////////////////////////////////////////////////
unsigned long readMillis = 0;
const int DIGITAL_INPUTS_SIZE = sizeof(digitalInputs) / sizeof(digitalInputs[0]);
int readInputs[DIGITAL_INPUTS_SIZE] = {};
const String orionIPString = String(orionIP[0]) + "." + orionIP[1] + "." + orionIP[2] + "." + orionIP[3] + ":" + orionPort;

void setup() {
    // Set the digital pins as inputs
    for (int i = 0; i < DIGITAL_INPUTS_SIZE; i++) {
        pinMode(digitalInputs[i], INPUT);
    }

    Ethernet.begin(mac, myIP);
    // Ethernet.begin(mac, myIP, myDNS, myGATEWAY, mySUBNET);

    Serial.begin(9600); // Start serial data transmission with the data rate in baud

    // If the inputs array differs in size with the alias array
    if (DIGITAL_INPUTS_SIZE != sizeof(alias) / sizeof(alias[0])) {
        Serial.println("ERROR: Each digital input must have a designated alias");
        Serial.flush();
        exit(-1);
    }

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
