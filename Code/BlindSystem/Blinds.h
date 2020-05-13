#ifndef BLINDS_H
#define BLINDS_H

#include "Arduino.h"

class Blinds {
    private:
        int pinUp;     //pin for sending blinds up
        int pinStop;   //pin for stopping blinds
        int pinDown;   //pin for sending blinds down
        char blindsState; //0 stop, 1 down, -1 up

    public:
        Blinds(int pinUp, int pinStop, int pinDown);
        void init();
        void lower();
        void raise();
        void stop();
};

#endif