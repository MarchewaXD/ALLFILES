#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int liczba, strzal, i=0;

int main() {
    cout<<"Witaj! Pomyslalem sobie liczbe z zakresu od 1 do 100"<<endl;
    srand(time(NULL));
    liczba = rand()%100+1;

    while(strzal!=liczba){
        cout<<"Podaj liczbe:";
        cin>>strzal;
        i++;
        if(strzal>liczba){
            cout<<"Liczba jest za duza"<<endl;
        }
        else if(strzal<liczba){
            cout<<"Liczba jest za mala"<<endl;
        }
        else{
            cout<<"Zgadles! Zgadles za "<<i<<" razem!"<<endl;
        }
    }
    system("pause");
    return 0;
}