#include <iostream>

class Ksiazka{
    std::string nazwa, autor;
    int rok_wydania;
    bool czy_wypozyczona;

    public:
    Ksiazka(std::string, std::string, int, bool);
    void wypozycz();
    void oddaj();
    void wyswietl_info();
};