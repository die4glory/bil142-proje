
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
            std::cout<<"       _________\n"
                       "      (=========)\n"
                       "      |=========|\n"
                       "      |====_====|\n"
                       "      |== / \\ ==|\n"
                       "      |= / _ \\ =|\n"
                       "   _  |=| ( ) |=|\n"
                       "  /=\\ |=|     |=| /=\\\n"
                       "  |=| |=| ALP |=| |=|\n"
                       "  |=| |=|  _  |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |/  | |  \\| |=|\n"
                       "  |=|/    | |    \\|=|\n"
                       "  |=/TEKIN |_| TEKIN\\=|\n"
                       "  |(_______________)|\n"
                       "  |=| |_|__|__|_| |=|\n"
                       "  |=|   ( ) ( )   |=|\n"
                       " /===\\           /===\\\n"
                       "|||||||         |||||||\n"
                       "-------         -------\n"
                       " (~~~)           (~~~)";
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
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                    break;
            }
        }
    }

    return playersShip;
}