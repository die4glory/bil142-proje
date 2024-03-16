//
// Created by Duru Irmak Öztürk on 19.02.2024.
//

#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include <cstdlib>
#include <iostream>


class Spaceships {
public:
    Spaceships(double _damageCoef) :damageCoef{_damageCoef}{}

    //UPDATES
    virtual int updateHealthDamage10(int& _health) = 0;
    virtual int updateHealthDamage30(int&  _health)=0;

    inline int earnMoney(int& _money);
    inline int loseMoney(int& _money) ;
     int updateFuel(int& _fuel);

    //EVENTS
    virtual void asteroid()=0;
    void abandonedPlanet();
    void pirates();

    //ACTIONS

    virtual void run()=0;
    virtual void fight()=0;
    void debate();

    //DISPLAY
    inline void displayStatus() const ;

    //GAME ENDING
     void gameScore();

    int fuel{100};

protected:

    //ATTRIBUTIONS
    int money{0};
    int health{100};
    double damageCoef{0};////

    //CONSTANTS
    const int prize{10};
    const int spentFuel{33};
    const int damage{10};
    const int damage_{30};
};

#endif //COSMIC_VOYAGER_CAPTAIN_H
