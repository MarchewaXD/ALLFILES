#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

int main(){
    int wybor;
    cout<<"================================";
    cout<<"";
    cout<<"Witaj w programie do obliczania wzorow, jaki wzor chcialbys obliczyc?"<<endl;
    sleep(1);
    cout<<"1.Pole kwadratu"<<endl;
    cout<<"2.Obwod kwadratu"<<endl;
    cout<<"3.Pole prostokata"<<endl;
    cout<<"4.Obwod prostokata"<<endl;
    cout<<"5.Pole trojkata"<<endl;
    cout<<"6.Obwod trojkata"<<endl;
    sleep(1);
    cout<<"Aby wybrac jaki wzor obliczyc wpisz jego numer: ";
    cin>>wybor;
        switch(wybor){
        case 1:
            float a1, pole1;
            cout<<"Podaj dlugosc boku kwadratu: ";
            cin>>a1;
            pole1 = pow(a1,2);
            cout<<"Pole kwadratu o boku "<<a1<<" wynosi "<<pole1;
            break;
        case 2:
            float a2, obwod2;
            cout<<"Podaj dlugosc boku kwadratu: ";
            cin>>a2;
            obwod2 = a2*4;
            cout<<"Obwod kwadratu o boku "<<a2<<" wynosi "<<obwod2;
            break;
        default:
            cout<<"Niestety wybrales zly numer";
            break;
        }
}
