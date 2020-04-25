#include "Arduino.h"
#include "UV.h"

UV::UV(char pinUV) {
    this->pinUV = pinUV;
}

char UV::inSunlight() {
    int valUV = value();

    if(valUV > 5)
        return 1;
    else
        return 0;
}

int UV::value() {
    Serial.print("UV = ");
    int valUV = analogRead(pinUV);
    Serial.println(valUV);
    return valUV;
}
