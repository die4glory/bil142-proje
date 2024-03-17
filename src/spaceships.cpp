
#include <cstdlib>
#include <iostream>
#include "spaceships.h"


void Spaceships::wait_for_enter() {
    std::cout << "Devam etmek için Enter'a bas.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

 int Spaceships::loseMoney(int& money) {
    int moneyLoss = (rand() % 3 + 1);
    moneyLoss=moneyLoss*10;
    if(money<moneyLoss){
        std::cout<<"Pazarlık etmek için yeterli altın yok.\n";
        pirates();
        return money;
    }
    else {
        return money-=moneyLoss;
    }
}
 int Spaceships::earnMoney(int& money) {
    money += prize;
    return money;
}
 int Spaceships::updateFuel(int& fuel) {
    if(fuel>34) {
        fuel -= spentFuel;
        return fuel;
    }
    else {
        fuel=0;
        std::cout<<"\nOyuna devam etmek için yeterli yakıt kalmadı.";
        return fuel;
    }

}
void Spaceships::abandonedPlanet() {
    int oran = (rand() % 2) == 0 ? 10: 0;
    if(oran>0){
        std::cout<<"⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⢯⠙⠩⠀⡇⠊⠽⢖⠆⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠱⣠⠀⢁⣄⠔⠁⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠀⣷⣶⣾⣾⠀⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⢀⡔⠙⠈⢱⡟⣧⠀⠀⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⠀⠀⡠⠊⠀⠀⣀⡀⠀⠘⠕⢄⠀⠀⠀⠀⠀\n"
                   "⠀⠀⠀⢀⠞⠀⠀⢀⣠⣿⣧⣀⠀⠀⢄⠱⡀⠀⠀⠀\n"
                   "⠀⠀⡰⠃⠀⠀⢠⣿⠿⣿⡟⢿⣷⡄⠀⠑⢜⢆⠀⠀\n"
                   "⠀⢰⠁⠀⠀⠀⠸⣿⣦⣿⡇⠀⠛⠋⠀⠨⡐⢍⢆⠀\n"
                   "⠀⡇⠀⠀⠀⠀⠀⠙⠻⣿⣿⣿⣦⡀⠀⢀⠨⡒⠙⡄\n"
                   "⢠⠁⡀⠀⠀⠀⣤⡀⠀⣿⡇⢈⣿⡷⠀⠠⢕⠢⠁⡇\n"
                   "⠸⠀⡕⠀⠀⠀⢻⣿⣶⣿⣷⣾⡿⠁⠀⠨⣐⠨⢀⠃\n"
                   "⠀⠣⣩⠘⠀⠀⠀⠈⠙⣿⡏⠁⠀⢀⠠⢁⡂⢉⠎⠀\n"
                   "⠀⠀⠈⠓⠬⢀⣀⠀⠀⠈⠀⠀⠀⢐⣬⠴⠒⠁⠀⠀\n"
                   "⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀";
        std::cout<<"\nTerk edilmiş bir gezegende yerde 10 altın buldun! Şanslı günündesin!\n\n";
        earnMoney(money);
        displayStatus();
    }
    else {
        std::cout<<"\nTerk edildiğini sandığın gezegene geldiğinde yanıldığını anladın ve...\n\n";
        pirates();
    }
   wait_for_enter();
}


void Spaceships::pirates() { //3 secenek kac savas pazarlık
    std::cout<<"                       ______\n"
               "                    .-\"      \"-.\n"
               "                   /            \\\n"
               "       _          |              |          _\n"
               "      ( \\         |,  .-.  .-.  ,|         / )\n"
               "       > \"=._     | )(__/  \\__)( |     _.=\" <\n"
               "      (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)\n"
               "             \"=._ (_     ^^     _)\"_.=\"\n"
               "                 \"=\\__|IIIIII|__/=\"\n"
               "                _.=\"| \\IIIIII/ |\"=._\n"
               "      _     _.=\"_.=\"\\          /\"=._\"=._     _\n"
               "     ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )\n"
               "      > _.=\"                            \"=._ <\n"
               "     (_/                                    \\_)";
    if (fuel>=33) {
        displayStatus();
        std::cout << "Uzay korsanlarıyla karşılaştın! Kaç (0), savaş (1) ya da pazarlık et (2)!\n";
        int choice{0};
        std::cin >> choice;
        switch(choice) {
            case 0: //kac
                run();
                break;
            case 1: //savas
                fight();
                break;
            case 2: //pazarlik et
                debate();
                break;
            default:
                std::cout << "Sadece 3 seçeneğin var!\n\n";
                pirates();
                break;
        }
    }
    else if(fuel<33) {
        displayStatus();
        std::cout << "Uzay korsanlarıyla karşılaştın! Kaçmak için yeterli yakıtın yok. Savaş (1) ya da pazarlık et (2)!\n";
        int choice{1};
        std::cin >> choice;
        switch (choice) {
            case 1: //savas
                fight();
                break;
            case 2: //pazarlik et
                debate();
                break;
            default:
                std::cout << "Sadece 2 seçeneğin var!\n\n";
                pirates();
                break;
        }
    }
    wait_for_enter();

}

void Spaceships::debate() {
    if (money<=0){
        std::cout<<"Pazarlık etmek için cebinde beş kuruş olmadığını fark ettin.\n\n";
        pirates();
    }
    else {
        loseMoney(money);
        displayStatus();
    }
}
 void Spaceships::displayStatus() const {
    std::cout<<"\nGemi sağlığı: "<<health<<" Depodaki yakıt: "<<fuel<<" Toplam altın: "<<money<<"\n";
}


 void Spaceships::gameScore() {
    std::cout<<"Oyun sona erdi. Puanınız :" << ((fuel*5)+(health*10)+(money*10));
}
