
#ifndef UNTITLED_STRONGSHIP2_H
#define UNTITLED_STRONGSHIP2_H
#include "spaceships.h"

class strongShip: public Spaceships{
public:
    strongShip():Spaceships(0.5){}

    int updateHealthDamage30(int& _health) override;
    int updateHealthDamage10(int& _health) override;
    void asteroid() override;
    void run() override;
    void fight() override;

private:
protected:

};

#endif //UNTITLED_STRONGSHIP2_H
