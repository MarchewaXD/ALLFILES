#pragma once
#include <iostream>
#include <string>

class Pytanie{
    public: 
    std::string tresc, a, b, c, d, odpowiedz, poprawna;
    int nr_pytania, punkt;

    void wczytaj(); //z pliku
    void zadaj(); // pokazuje pytanie, czyta odp
    void sprawdz(); // sprawdza poprawnosc
};