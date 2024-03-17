
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "spaceships.h"
#include "commonship2.h"
#include "speedship2.h"
#include "strongship2.h"
#ifndef UNTITLED_EVENTS_H
#define UNTITLED_EVENTS_H
class Events {
public:
    //GAME STARTER
    static void start_game();

    //SHIP SELECTOR
    static std::shared_ptr<Spaceships>playersShip();
};
#endif //UNTITLED_EVENTS_H