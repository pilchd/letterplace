#include <LiquidCrystal_I2C.h>
#include <RotaryEncoder.h>

#include "Place.h"
#include "PlaceState.h"


void Place::setState(PlaceState& newState) {
    currentState->out(this);
    currentState = &newState;
    currentState->in(this);
}
void Place::run() {
    currentState->run(this);
}

Place& Place::getSelf() {
    static Place self;
    return self;
}
PlaceState* Place::getState() const {
    return currentState;
}
LiquidCrystal_I2C& Place::getLCD() const {
    return *(this->lcd);
}
RotaryEncoder& Place::getCtrl() const {
    return *(this->ctrl);
}

Place::Place() {
    currentState = NULL;
    lcd = new LiquidCrystal_I2C(0x27, 4, 20);
    ctrl = new RotaryEncoder(D6, D7);
}
