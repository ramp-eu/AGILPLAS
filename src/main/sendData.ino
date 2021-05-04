///////////////////////////////////////////////////////////////////
// Send the previously read data towards OCB /v2/op/update enpoint
// with "append" mode which will create the entity if it doesn't
// exist and update its attributes otherwise.
///////////////////////////////////////////////////////////////////
void sendData() {
    Serial.println("----- Sending Data to OCB");

    String data = "{\r\n  \"actionType\": \"append\",\r\n  \"entities\": [\r\n    {\r\n      \"type\": \"" +
                  entityType + "\",\r\n      \"id\": \"" + entityId + "\",";
    // Loop through the read inputs and append them as entity attributes
    for (int i = 0; i < sizeof(readInputs) / sizeof(readInputs[0]); i ++) {
        data += "\r\n      \"" + alias[i] + "\": {\r\n" +
                "        \"value\": " + readInputs[i] + ",\r\n" +
                "        \"type\": \"Integer\"\r\n" +
                "      },";
    }
    data.remove(data.lastIndexOf(','));
    data += "\r\n    }\r\n  ]\r\n}";

    Serial.println("POST /v2/op/update HTTP/1.1");
    Serial.println(data);

    if (ethClient.connect(orionIP, orionPort)) {
        ethClient.println("POST /v2/op/update HTTP/1.1");
        ethClient.println("Content-Type: application/json");
        ethClient.println("fiware-service: " + fiwareService);
        ethClient.println("fiware-servicepath: " + fiwareServicePath);
        ethClient.println("Host: " + orionIPString);
        ethClient.println("Content-Length: " + String(data.length()));
        ethClient.println();
        ethClient.println(data);
        ethClient.flush();

        delay(100);  // Wait for response

        if (ethClient.available()) {
            Serial.println();
            Serial.println("Server response");
            while (ethClient.available()) {
                Serial.write(ethClient.read());
            }
        }
        ethClient.stop();
        Serial.println("----- Data succesfully sent to OCB");
    } else {
        Serial.println("ERROR: Connection to OCB @ " + orionIPString + " failed");
    }
    Serial.flush();
}
