//
// Created by Duru Irmak Öztürk on 13.03.2024.
//
#include <iostream>
#include <algorithm>
#include "spaceships.h"
#include "commonship2.h"
#include "speedship2.h"
#include "strongship2.h"
#include "events.h"

void Events::start_game(){
    playersShip()->displayStatus();
    int counter{0};
    int max_event{5};
    do {
        int randomEvent = (rand() %3 + 1);
        switch(randomEvent){
            case 1: //asteroid
                playersShip()->asteroid();
                counter++;
                break;
            case 2: //pirates
                playersShip()->pirates();
                counter++;
                break;
            case 3: //abandonedPlanet
                playersShip()->abandonedPlanet();
                counter++;
                break;
            default:
                break;
        }
    } while(counter<max_event&&playersShip()->fuel>1);
    playersShip()->gameScore();

}


std::shared_ptr<Spaceships> Events::playersShip() {
    static std::shared_ptr<Spaceships> playersShip;

    if (!playersShip) {
        int shipChoice{0};
        bool valid_choice = false;

        while (!valid_choice) {
            std::cout << "\nYolculuğuna başlamak için bir gemi seç: Normal gemi (1) Hızlı gemi (2) Güçlü gemi (3)\n";
            std::cin >> shipChoice;

            switch (shipChoice) {
                case 1:
                    playersShip = std::make_shared<commonShip>();
                    valid_choice = true;
                    break;
                case 2:
                    playersShip = std::make_shared<speedShip>();
                    valid_choice = true;
                    break;
                case 3:
                    playersShip = std::make_shared<strongShip>();
                    valid_choice = true;
                    break;
                default:
                    std::cout << "Geçersiz gemi seçimi. Lütfen tekrar deneyin.\n";
                    Events::playersShip();
                    break;
            }
        }
    }

    return playersShip;
}







/*std::shared_ptr<Spaceships>Events :: playersShip() {
       static std::shared_ptr<Spaceships> playersShip;
    if (!playersShip) {
        int shipChoice{0
        };
        std::cout << "\nYolculuğuna başlamak için bir gemi seç: Normal gemi (1) Hızlı gemi (2) Güçlü gemi (3)\n";
        std::cin >> shipChoice;
        switch (shipChoice) {
            case 1:
                playersShip = std::make_shared<commonShip>();
                break;
            case 2:
                playersShip = std::make_shared<speedShip>();
                break;
            case 3:
                playersShip = std::make_shared<strongShip>();

                break;
            default:
                std::cout << "Geçersiz gemi seçimi.\n\n";
                //Spaceships::secilen_gemi();
                break;
        }
    }
    return playersShip;

};    */
