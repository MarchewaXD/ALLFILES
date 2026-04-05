#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "klasy.h"

Ksiazka::Ksiazka(std::string n, std::string a, int r, bool czyw){
    nazwa = n;
    autor = a;
    rok_wydania = r;
    czy_wypozyczona = czyw;
}

void Ksiazka::wypozycz(){
    std::cin.ignore();
    std::cout << "Jaka ksiazke chcesz wypozyczyc: ";
    std::getline(std::cin, nazwa);
    std::cout << "Jaki jest autor tej ksiazki: ";
    std::getline(std::cin, autor);
    std::cout << "Jaki jest rok wydania tej ksiazki (np. 2025): ";
    while(true){
        if(std::cin >> rok_wydania && rok_wydania >= -10000 && rok_wydania <= 2027) break;
        std::cout << "Nieprawidlowy rok! Upewnij sie, ze podajesz odpowiedni format! (RRRR)\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    czy_wypozyczona = true;

    // Zapis do pliku
    std::ofstream plik("biblioteka.txt", std::ios::app);
    if(plik.is_open()){
        plik << nazwa << "\n";
        plik << autor << "\n";
        plik << rok_wydania << "\n";
        plik << (czy_wypozyczona ? "true" : "false") << "\n";
        plik.close();
        std::cout << "Ksiazka zapisana!\n";
    } else {
        std::cout << "Blad otwarcia pliku!\n";
    }
}

void Ksiazka::oddaj(){
    std::string oddanie;
    std::cin.ignore();
    std::cout << "Jaka ksiazke chcesz oddac: ";
    std::getline(std::cin, oddanie);

    // Wczytaj cały plik do wektora
    std::ifstream plik("biblioteka.txt");
    if(!plik.is_open()){
        std::cout << "Brak pliku z ksiazkami!\n";
        return;
    }

    std::vector<std::string> linie;
    std::string linia;
    while(std::getline(plik, linia)){
        linie.push_back(linia);
    }
    plik.close();

    // Znajdź tytuł i zmień true -> false
    bool znaleziono = false;
    for(int i = 0; i + 3 < (int)linie.size(); i += 4){
        if(linie[i] == oddanie){
            if(linie[i+3] == "false"){
                std::cout << "Ta ksiazka nie jest wypozyczona!\n";
                return;
            }
            linie[i+3] = "false";
            znaleziono = true;
            break;
        }
    }

    if(!znaleziono){
        std::cout << "Nie znaleziono ksiazki o tytule: " << oddanie << "\n";
        return;
    }

    // Nadpisz plik
    std::ofstream zapis("biblioteka.txt");
    for(const std::string& l : linie){
        zapis << l << "\n";
    }
    zapis.close();
    std::cout << "Ksiazka oddana!\n";
}

void Ksiazka::wyswietl_info(){
    std::ifstream plik("biblioteka.txt");
    if(!plik.is_open()){
        std::cout << "Brak pliku z ksiazkami!\n";
        return;
    }

    std::string n, a, r, w;
    bool cokolwiek = false;
    while(
        std::getline(plik, n) &&
        std::getline(plik, a) &&
        std::getline(plik, r) &&
        std::getline(plik, w)
    ){
        cokolwiek = true;
        std::cout << "------------------------\n";
        std::cout << "Tytul:          " << n << "\n";
        std::cout << "Autor:          " << a << "\n";
        std::cout << "Rok wydania:    " << r << "\n";
        std::cout << "Czy wypozyczona: " << (w == "true" ? "TAK" : "NIE") << "\n";
    }
    plik.close();

    if(!cokolwiek){
        std::cout << "Brak ksiazek w bibliotece!\n";
    } else {
        std::cout << "------------------------\n";
    }
}