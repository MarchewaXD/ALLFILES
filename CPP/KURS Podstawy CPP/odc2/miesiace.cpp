#include <iostream>
#include <cstdlib>
using namespace std;

int numer_miesiaca;

int main() {
    cout<<"Podaj numer miesiaca: ";
    if(!(cin>>numer_miesiaca)){
        cerr<<"To nie jest liczba!";
        exit(0);
    }

    switch(numer_miesiaca){
        case 1: 
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            cout<<"Ten miesiac ma 31 dni"<<endl;
        }
        break;

        case 4:
        case 6:
        case 9:
        case 11:
        {
            cout<<"Ten miesiac ma 30 dni"<<endl;
        }
        break;
        case 2:
        {
            int rok;
            cout<<"Podaj rok: ";
            cin>>rok;
            if(((rok%4==0) && (rok%100 != 0)) || (rok%400 == 0)){
                cout<<"Ten miesiac ma 29 dni"<<endl;
            }
            else{
                cout<<"Ten miesiac ma 28 dni"<<endl;
            }
            break;
        }
        default:
        {
            cout<<"Niepoprawny numer miesiaca!";
        }
    }
    return 0;
}