#define D0  16
#define D1  5
#define D2  4
#define D3  0
#define D4  2
#define D5  14
#define D6  12
#define D7  13
#define D8  15
#define D9  3
#define D10 1 


#include <LiquidCrystal_I2C.h>
#include <RotaryEncoder.h>

#include "Place.h"
#include "PlaceStates.h"

using PlaceStates::MainMenu;


Place place = Place::getSelf();


void setup() {
    place.setState(MainMenu::getSelf());
    place.getLCD().init();
    place.getLCD().backlight();
}

void loop() {
    place.run();
}
