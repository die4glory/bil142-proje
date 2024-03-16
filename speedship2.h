//
// Created by Duru Irmak Öztürk on 15.03.2024.
//

#ifndef UNTITLED_SPEEDSHIP2_H
#define UNTITLED_SPEEDSHIP2_H
#include "spaceships.h"

class speedShip:public Spaceships {
public:
    speedShip(): Spaceships(1.5){}

    int updateHealthDamage10(int& _health) override;
    int updateHealthDamage30(int& _health) override;
    void asteroid() override;
    void run() override;
    void fight() override;

private:
protected:

};
#endif //UNTITLED_SPEEDSHIP2_H
