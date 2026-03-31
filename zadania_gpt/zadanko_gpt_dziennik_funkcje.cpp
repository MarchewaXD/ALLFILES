#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void dodajOcene(){
    string uczen;
    int ocena;
    cout<<"Jakiemu uczniowi chcesz wstawic ocene?" ;
    cin>>uczen;
    cout<<"Jaka ocene?";
    cin>>ocena;
    if(ocena <=0 || ocena>6){
        cout<<"Podano bledna ocene!"<<endl;
        return;
    }
    fstream dziennik;
    dziennik.open("oceny.txt", ios::app);
    if(dziennik.good()){
        dziennik<<uczen<<" "<<ocena;
        dziennik.close();
        return;
    }
    else{
        cout<<"Nie udalo sie dostac do pliku!";
        dziennik.close();
        return;
    }

}
void wyswietlOceny(){
    fstream dziennik;
    string uczen;
    int ocena;
    dziennik.open("oceny.txt", ios::in);
    if(!dziennik.good()){
        cout<<"Nie udalo sie otworzyc pliku!";
        dziennik.close();
        return;
    }
    while(dziennik >> uczen >> ocena){
        cout<<uczen<<" "<<ocena<<endl;
    }
    dziennik.close();
    return;
}
void obliczSrednia(){
    fstream dziennik;
    string uczen;
    float ocena, suma=0, srednia;
    int ilosc_ocen=0;
    dziennik.open("oceny.txt", ios::in);
    if(!dziennik.good()){
        cout<<"Nie udalo sie otworzyc pliku!";
        dziennik.close();
        return;
    }
    while(dziennik>>uczen>>ocena){
        suma += ocena;
        ilosc_ocen++;
    }
    dziennik.close();
    if(!ilosc_ocen>0){
        cout<<"Brak ocen!";
        dziennik.close();
        return;
    }
    srednia = suma/ilosc_ocen;
    cout<<"Srednia ocen to: "<<srednia<<endl;
    return;
}
int main() {
    int wybor;
    cout<<"Witaj w dzienniku!"<<endl;
    do{
        cout<<"Jaka operacje chcesz wykonac: "<<endl;
        cout<<"1. Dodaj ocene"<<endl;
        cout<<"2. Wyswietl oceny"<<endl;
        cout<<"3. Oblicz srednia"<<endl;
        cout<<"4. Wyjscie"<<endl;
        cin>>wybor;
        switch(wybor){
            case 1:{
                dodajOcene();
                break;
            }
            case 2:{
                wyswietlOceny();
                break;
            }
            case 3:{
                obliczSrednia();
                break;
            }
            case 4:{
                break;
            }
            default:{
                cout<<"Podano bledny wybor!"<<endl;
                break;
            }
        }
    } while(wybor != 4);
    cout<<"Koniec programu! Nacisnij enter aby zakonczyc...";
    getchar();getchar();
    return 0;
}