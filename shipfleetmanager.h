//
// Created by Duru Irmak Öztürk on 14.03.2024.
//

#ifndef UNTITLED_SHIPFLEETMANAGER_H
#define UNTITLED_SHIPFLEETMANAGER_H
#include "spaceships.h"

class ShipFleetManager {
public:
    std::vector<Spaceships*> shipsInFleet;
    void addShip(Spaceships* new_ship) {
        shipsInFleet.emplace_back(new_ship);
    }
    void displayAllSpaceshipStatus() {
        for(auto ship : shipsInFleet) {
            ship->displayStatus();
        }
    }

private:
protected:

};

#endif //UNTITLED_SHIPFLEETMANAGER_H
