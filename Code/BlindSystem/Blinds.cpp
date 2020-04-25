#include "Arduino.h"
#include "Blinds.h"

Blinds::Blinds(char pinUp, char pinDown, char pinStop) {
    this->pinUp = pinUp;
    this->pinDown = pinDown;
    this->pinStop = pinStop;
    this->blindsState = 0;
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
        this->blindsState = 1;
    }
    digitalWrite(pinDown, LOW);
}

void Blinds::raise() {
    //raise the blinds
    Serial.println("Blinds are raising");
    if(blindsState != -1) {
        digitalWrite(pinUp, HIGH);
        this->blindsState = -1;
    }
    digitalWrite(pinUp, LOW);
}

void Blinds::stop() {
    //stop the blinds
    Serial.println("Blinds are stopped");
    if(blindsState != 0) {
        digitalWrite(pinStop, HIGH);
        this->blindsState = 0;
    }
    digitalWrite(pinStop, LOW);
}