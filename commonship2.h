//
// Created by Duru Irmak Öztürk on 15.03.2024.
//

#ifndef UNTITLED_COMMONSHIP2_H
#define UNTITLED_COMMONSHIP2_H
#include "spaceships.h"

class commonShip:public Spaceships {
public:
    commonShip():Spaceships(1){}

    int updateHealthDamage10(int& _health) override;
    int updateHealthDamage30(int& _health) override;
    void asteroid() override;
    void run() override;
    void fight() override;

private:
protected:

};

#endif //UNTITLED_COMMONSHIP2_H
