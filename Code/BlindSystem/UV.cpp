#include "Arduino.h"
#include "UV.h"

UV::UV(char pinUV) {
    this->pinUV = pinUV;
}

bool UV::inSunlight() {
    int valUV = value();

    if(valUV > 500)
        return true;
    else
        return false;
}

int UV::value() {
    Serial.print("UV = ");
    int valUV = analogRead(pinUV);
    Serial.println(valUV);
    return valUV;
}
