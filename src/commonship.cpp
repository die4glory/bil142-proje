
#include <iostream>
#include "commonship2.h"

int commonShip :: updateHealthDamage30(int &_health) {
    if (health>=0) {
        health -= damage_*damageCoef;
        return health;
    }
    else {
        health= 0;
        return health;
    }
}
int commonShip ::updateHealthDamage10(int &_health) {
    if (health>=0) {
        health -= damage*damageCoef;
        return health;
    }
    else {
        health= 0;
        return health;
    }
}

void:: commonShip :: asteroid() {
    int asteroidDamage = (rand() % 4) == 0 && 1 ? 10 : 0;
    std::cout << "\nAsteroid kuşağından geçiyorsun!\n\n";
    std::cout << "                      .:'\n"
                 "         ....     _.::'\n"
                 "       .:-\"\"-:.  (_.'\n"
                 "     .:/      \\:.\n"
                 "     :|        |:\n"
                 "     ':\\      /:'\n"
                 "      '::-..-::'\n"
                 "        `''''`";
    if (asteroidDamage > 0) {
        updateHealthDamage10(health);
        std::cout << "\nAsteroidlerden birine çarpıp 10 hasar aldın.\n\n";
        displayStatus();
    } else {
        std::cout << "\nAsteroid kuşağından hasar almadan geçtin.Yakıtın azaldı.\n";
        updateFuel(fuel);
        displayStatus();
    }
}

void commonShip :: run(){
    updateFuel(fuel);
    int oddsOfFlee = (rand() % 4) == 0 && 1 ? 10 : 0;
    if (oddsOfFlee > 0) {
        std::cout<<"Yakıtın azaldı. Tam kaçabildiğini sandığın anda...\n\n";
        updateFuel(fuel);// hocam kacamasa bile yakit harcanir seklinde yaptik
        pirates();
        displayStatus();
    }
    else {
        std::cout<<"Korsanlara izini kaybettirdin! Yakıtın azaldı.\n\n";
        updateFuel(fuel);
        displayStatus();

    }
}

void commonShip :: fight(){
    int oddsOfWin = (rand() % 4) == 0&&1 ? 10 : 0;
    if (oddsOfWin>0) {
        std::cout<<"Savaşın galibi sensin!\n\n";

    }
    else {
        std::cout<<"Savaşı kaybettin. 30 hasar aldın.\n\n";
        updateHealthDamage30(health);
        displayStatus();
    }
}

