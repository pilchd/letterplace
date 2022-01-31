#include "Place.h"
#include "PlaceLCD.h"
#include "PlaceState.h"
#include "PlaceStates.h"
#include "Rotor.h"


PlaceState& Place::setState(PlaceState& newState) {
    currentState->out(this);
    currentState = &newState;
    currentState->in(this);
    return newState;
}
void Place::run() {
    currentState->run(this);
}

Place& Place::getSelf() {
    static Place self;
    return self;
}
PlaceLCD& Place::getLCD() {
    return lcd;
}
Rotor& Place::getRotor() {
    return rotor;
}


Place::Place() :
        lcd(),
        rotor(D5, D6, D7),
        currentState(&PlaceStates::None::getSelf())
        {}
