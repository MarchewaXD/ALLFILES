#include <iostream>
using namespace std;

float saldo=1000;
int wybor, pin, i;

int main(){
    for(i=1; i<=3; i++){
        cout<<"Podaj pin: ";
        cin>>pin;
        if(pin==1234){
            cout<<"Poprawny PIN!"<<endl;
            break;
        }
        else{
            cout<<"Niepoprawny pin!";
        }
    }
    
        if(pin == 1234){
            cout<<"Witaj w aplikacji banku!"<<endl;
            do{
                cout<<"--------------------------------"<<endl;
                cout<<"1. Sprawdz saldo"<<endl;
                cout<<"2. Wplac pieniadze"<<endl;
                cout<<"3. Wyplac pieniadze"<<endl;
                cout<<"4. Wyjscie"<<endl;
                cout<<"Wybierz opcje: ";
                cin>>wybor;
                switch(wybor){
                    case 1:{
                        cout<<"Twoje saldo: "<<saldo<<"zl"<<endl;
                        break;
                    }
                    case 2:{
                        float wplac;
                        cout<<"Ile pieniedzy chcesz wplacic: ";
                        cin>>wplac;
                        if(wplac <=0){
                            cout<<"Nie mozna wplacic takiej sumy pieniedzy!"<<endl;
                            break;
                        }
                        else{
                            saldo += wplac;
                            cout<<endl;
                        break;
                        }
                    }
                    case 3:{
                        float wyplac;
                        cout<<"Ile pieniedzy chcesz wyplacic: ";
                        cin>>wyplac;
                        if(wyplac <=0){
                            cout<<"Nie mozesz wyplacic takiej ilosci!"<<endl;
                            break;
                        }
                        else if(wyplac>saldo){
                            cout<<"Nie masz wystarczajacej ilosci srodkow!"<<endl;
                            break;
                        }
                        else{
                            saldo -= wyplac;
                            cout<<endl;
                            break;
                        }
                    }
                    case 4:{
                        break;
                    }
                    default:{
                        cout<<"Podano bledny wybor!"<<endl;
                        break;
                    }
                }
            } while (wybor != 4);
        }
        else{
            cout<<"Zbyt wiele prob. Koniec programu.";
            exit(0);
        }
    return 0;
}