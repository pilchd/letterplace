#include "PlaceStates.h"

using namespace PlaceStates;


PlaceState& MainMenu::getSelf() {
    static MainMenu self;
    return self;
}

void MainMenu::in(Place* place) {};
void MainMenu::run(Place* place) {}
void MainMenu::out(Place* place) {};
