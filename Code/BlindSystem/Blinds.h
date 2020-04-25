#ifndef BLINDS_H
#define BLINDS_H

#include "Arduino.h"

class Blinds {
    private:
        char pinUp;     //pin for sending blinds up
        char pinDown;   //pin for sending blinds down
        char pinStop;   //pin for stopping blinds
        char blindsState; //0 stop, 1 down, -1 up

    public:
        Blinds(char pinUp, char pinDown, char pinStop);
        void init();
        void lower();
        void raise();
        void stop();
};

#endif