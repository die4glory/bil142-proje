#include <iostream>
#include "events.h"
#include "spaceships.h"
#include <cstdlib>
#include "shipfleetmanager.h"
#include "speedship2.h"
#include "strongship2.h"
#include "commonship2.h"

int main() {

    srand(time(0));
    std::shared_ptr<Spaceships>playersShip;
    Events::start_game();

    return 0;
}

