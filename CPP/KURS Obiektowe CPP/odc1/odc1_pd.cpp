#include <iostream>
using namespace std;

class Samochod{

    public:
    string marka, model;
    int rocznik, przebieg;

    void wczytaj(){
        cout<<"Podaj marke samochodu: ";
        cin>>marka;
        cout<<"Podaj model: ";
        cin>>model;
        cout<<"Podaj rocznik: ";
        cin>>rocznik;
        cout<<"Podaj przebieg: ";
        cin>>przebieg;
    }

    void wypisz(){
        cout<<"Marka: "<<marka<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Rocznik: "<<rocznik<<endl;
        cout<<"Przebieg: "<<przebieg<<endl;
    }
};

int main() {
    Samochod toyota;
    toyota.wczytaj();
    Samochod bmw;
    bmw.wczytaj();
    cout<<"-------------------"<<endl;
    toyota.wypisz();
    cout<<"-------------------"<<endl;
    bmw.wypisz();
    return 0;
}