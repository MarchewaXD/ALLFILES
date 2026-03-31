#include <iostream>
using namespace std;

int tablica[3];

int main() {
    cout<<"Podaj kolejno 3 liczby: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"Liczba "<<i+1<<": ";
        cin>>tablica[i];
    }
    if((tablica[0]>=tablica[1]) && (tablica[0]>=tablica[2])){
        cout<<"Najwieksza liczba to "<<tablica[0];
    }
    else if((tablica[1]>=tablica[0]) && (tablica[1]>=tablica[2])){
        cout<<"Najwieksza liczba to "<<tablica[1];
    }
    else if((tablica[2]>=tablica[0]) && (tablica[2]>=tablica[1])){
        cout<<"Najwieksza liczba to "<<tablica[2];
    }
    return 0;
}