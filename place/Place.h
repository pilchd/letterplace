#pragma once

#include <LiquidCrystal_I2C.h>
#include <RotaryEncoder.h>


class PlaceState;


class Place {
    
    public:
    void setState(PlaceState& newState);
    void run();

    static Place& getSelf();
    PlaceState* getState() const;
    LiquidCrystal_I2C& getLCD() const;
    RotaryEncoder& getCtrl() const;
    
    private:
    Place();

    PlaceState* currentState;
    
    LiquidCrystal_I2C* lcd;
    RotaryEncoder* ctrl;
};
