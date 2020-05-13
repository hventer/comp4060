#include "Arduino.h"
#include "Blinds.h"

Blinds::Blinds(int pinUp, int pinStop, int pinDown) {
    this->pinUp = pinUp;
    this->pinDown = pinDown;
    this->pinStop = pinStop;
    blindsState = 0;
}

void Blinds::init() {
    //set downPin as output
    pinMode(pinDown, OUTPUT);
    digitalWrite(pinDown, LOW);

    //set upPin as output
    pinMode(pinUp, OUTPUT);
    digitalWrite(pinUp, LOW);

    //set stopPin as output
    pinMode(pinStop, OUTPUT);
    digitalWrite(pinStop, LOW);
}

void Blinds::lower() {
    Serial.println("Blinds are lowering");
    if(blindsState != 1) {
        digitalWrite(pinDown, HIGH);
        blindsState = 1;
        delay(200);
    }
    digitalWrite(pinDown, LOW);
}

void Blinds::raise() {
    //raise the blinds
    Serial.println("Blinds are raising");
    if(blindsState != -1) {
        digitalWrite(pinUp, HIGH);
        blindsState = -1;
        delay(200);
    }
    digitalWrite(pinUp, LOW);
}

void Blinds::stop() {
    //stop the blinds
    Serial.println("Blinds are stopped");
    if(blindsState != 0) {
        delay(2000);
        digitalWrite(pinStop, HIGH);
        blindsState = 0;
        delay(200);
    }
    digitalWrite(pinStop, LOW);
}