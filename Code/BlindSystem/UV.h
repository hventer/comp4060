#ifndef UV_H
#define UV_H

#include "Arduino.h"

class UV {
    private:
        char pinUV;

    public:
        UV(char pinUV);
        int value();
        bool inSunlight();
};

#endif