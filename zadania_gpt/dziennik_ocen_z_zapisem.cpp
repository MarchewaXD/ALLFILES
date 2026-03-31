#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    //zmienne
    int wybor, ocena = 0;
do{
    cout<<"Witaj w dzienniku!"<<endl;
    cout<<"1. Dodaj oceny"<<endl;
    cout<<"2. Wyswietl oceny z dziennika"<<endl;
    cout<<"3. Oblicz srednia z pliku"<<endl;
    cout<<"4. Wyczysc plik"<<endl;
    cout<<"5. Wyjscie"<<endl;
    cin>>wybor;
    switch(wybor){
        case 1:{
            int ocena;
            string przedmiot;
            cout<<"Z jakiego przedmiotu chcesz dodac ocene?";
            cin.ignore();
            getline(cin, przedmiot);
            cout<<"Jaka ocena?";
            cin>>ocena;
            if(ocena>6 || ocena<=0){
                cout<<"Podano bledna ocene!";
                break;
            }
            fstream dziennik;
            dziennik.open("dziennik_ocen.txt", ios::out | ios::app);
            dziennik<<przedmiot<<endl;
            dziennik<<ocena<<endl;
            dziennik.close();
            break;
        }
        case 2:{
            fstream dziennik;
            dziennik.open("dziennik_ocen.txt", ios::in);
            if(!dziennik.good()){
                cout<<"Plik nie istnieje!"<<endl;
                break;
            }
            string linia_przedmiotu, linia_ocena;
            int ocena;
            while(getline(dziennik, linia_przedmiotu) && getline(dziennik, linia_ocena)){
                ocena = atoi(linia_ocena.c_str());
                cout<<linia_przedmiotu<<" "<<ocena<<endl;
            }
            dziennik.close();
            break;
        }
        case 3:{
            fstream dziennik;
            dziennik.open("dziennik_ocen.txt", ios::in);
            if(!dziennik.good()){
                cout<<"Plik nie istnieje!"<<endl;
                break;
            }
            float srednia = 0, suma = 0;
            string linia_przedmiotu, linia_ocena;
            int ocena, dzielnik = 0;
            while(getline(dziennik, linia_przedmiotu) && getline(dziennik, linia_ocena)){
                ocena = atoi(linia_ocena.c_str());
                suma += ocena;
                dzielnik++;
            }
            if(dzielnik<=0){
                cout<<"W dzienniku nie ma ocen!"<<endl;
                dziennik.close();
                break;
            }
            srednia = suma/dzielnik;
            cout<<"Srednia z przedmiotow: "<<srednia<<endl;
            dziennik.close();
            break;
        }
        case 4:{
            fstream dziennik;
            dziennik.open("dziennik_ocen.txt", ios::out);
            if(!dziennik.good()){
                cout<<"Nie mozna otworzyc pliku!"<<endl;
                break;
            }
            else{
                cout<<"Plik zostal wyczyszczony!"<<endl;
                dziennik.close();
                break;
            }
        }
        case 5:{
            cout<<"Koniec programu!";
            exit(0);
        }
        default:{
            cout<<"Podano nieistniejacy wybor!"<<endl;
            break;
        }
    }
} while(wybor!=5);

    return 0;
}