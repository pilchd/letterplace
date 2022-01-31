#pragma once

#include "PlaceLCD.h"
#include "Rotor.h"

class PlaceState;


class Place {
    
    public:
    PlaceState& setState(PlaceState& newState);
    void run();

    static Place& getSelf();
    PlaceLCD& getLCD();
    Rotor& getRotor();


    private:
    Place();

    PlaceLCD lcd;
    Rotor rotor;

    PlaceState* currentState;
};
