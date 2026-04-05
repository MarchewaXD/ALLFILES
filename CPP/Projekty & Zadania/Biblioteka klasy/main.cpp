#include <iostream>
#include "klasy.h"

int main()
{
int wybor = 0;
do{
    std::cout << "Witaj w bibliotece! Co chcesz zrobic?\n";
    std::cout << "1. Wypozycz ksiazke\n";
    std::cout << "2. Oddaj ksiazke\n";
    std::cout << "3. Wyswietl wypozyczone ksiazki\n";
    std::cout << "4. Wyjscie\n";
    while(true){
        std::cout << "Podaj liczbe (1-5): ";
        if (std::cin >> wybor && wybor >= 1 && wybor <= 4) break;
        std::cout << "Nieprawidlowa wartosc! Podaj int z zakresu 1-5.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    Ksiazka k1("", "", 0, false);
    switch (wybor) {
        case 1: {
            k1.wypozycz();
            break;
        }
        case 2:{
            k1.oddaj();
            break;
        }
        case 3:{
            k1.wyswietl_info();
            break;
        }
        case 4:{
            exit(0);
        }
    }
}while (true);
return 0;
}