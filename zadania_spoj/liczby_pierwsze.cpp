#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    int liczba_testow[100000];
    int ile_liczb;
    cout<<"Podaj ilosc liczb nie wieksza niz 100 000: ";
    cin>>ile_liczb;
    if(ile_liczb>100000){
        cout<<"Za duzo liczb!";
        exit(0);
    }
    for(int i=0; i<ile_liczb; i++){
        cout<<"Podaj "<<i+1<<" liczbe: ";
        cin>>liczba_testow[i];
    }
    for(int i=0; i<ile_liczb; i++){
        bool pierwsza = (liczba_testow[i] >=2);

        for(int j=2; j*j <= liczba_testow[i]; j++){
            if(liczba_testow[i]%j == 0){
                pierwsza = false;
                break;
            }

        }
        if(pierwsza){
            cout<<liczba_testow[i]<<": TAK"<<endl;
        }
        else{
            cout<<liczba_testow[i]<<": NIE"<<endl;
        }
    }
    return 0;
}