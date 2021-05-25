///////////////////////////////////////////////////////////////////
// Loop through the digital inputs storing their value.
// Open to add analogic reads in the future
///////////////////////////////////////////////////////////////////
void readData() {
    Serial.println("----- Reading digital inputs");

    for (int i = 0; i < INPUTS_SIZE; i++) {
        readInputs[i] = digitalRead(inputs[i]->getReference());
    }

    readMillis = millis();

    Serial.println("----- Digital inputs read");
}
