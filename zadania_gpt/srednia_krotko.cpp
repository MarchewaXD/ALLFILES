#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int ilosc_przedmiotow;
    cout<<"Ile przedmiotow? ";
    cin>>ilosc_przedmiotow;
    float srednia, suma;
    for(int i=0; i<ilosc_przedmiotow; i++){
        int ocena=0;
        cout<<"Podaj ocene jaka ci wypada z "<<i+1<<" przedmiotu: ";
        cin>>ocena;
        suma += ocena;
    }
    srednia = suma/ilosc_przedmiotow;
    cout<<"Srednia ogolna to: "<<srednia;
    return 0;
}