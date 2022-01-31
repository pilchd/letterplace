#pragma once

#include <RotaryEncoder.h>


class Rotor {
    
    public:
    Rotor(const int& swPin, const int& clkPin, const int& datPin) :
            encoder(clkPin, datPin), swPin(swPin), lastPos(0) {
        pinMode(swPin, INPUT);
        encoder.tick();
    }

    void tick() {
        encoder.tick();
    }

    enum class Dir {
        None,
        CW,
        CCW
    };
    Dir getDir() {
        int pos = encoder.getPosition();
        if (pos < lastPos) {
            return Dir::CCW;
        }
        if (pos > lastPos) {
            return Dir::CW;
        }
        if (pos == lastPos) {
            return Dir::None;
        }
        lastPos = pos;
    }


    private:
    RotaryEncoder encoder;
    
    const int swPin;
    int lastPos;
};
