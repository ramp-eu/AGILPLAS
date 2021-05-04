///////////////////////////////////////////////////////////////////
// Loop through the digital inputs storing its value.
// Open to add analogic reads in the future
///////////////////////////////////////////////////////////////////
void readData() {
    Serial.println("----- Reading digital inputs");

    for (int i = 0; i < DIGITAL_INPUTS_SIZE; i++) {
        readInputs[i] = digitalRead(digitalInputs[i]);
    }

    readMillis = millis();

    Serial.println("----- Digital inputs read");
}
