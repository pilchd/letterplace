#pragma once

class Place;


class PlaceState {
    public:
    virtual void in(Place* place) = 0;
    virtual void run(Place* place) = 0;
    virtual void out(Place* place) = 0;
};
