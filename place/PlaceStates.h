#pragma once

#include "Place.h"
#include "PlaceState.h"


namespace PlaceStates {
    
class MainMenu : public PlaceState {
    public:
    static PlaceState& getSelf();
    
    void in(Place* place);
    void run(Place* place);
    void out(Place* place);

    private:
    MainMenu() {};
};

}
