#include <iostream>
#include <cmath>
using namespace std;
int kalkulator(){
    float a,b,dod,od,mn,dz,pw,pt;
    cout<<"Podaj pierwsza liczbe: ";
    cin>>a;
    cout<<"Podaj druga liczbe: ";
    cin>>b;
    dod = a+b;
    od = a-b;
    mn = a*b;
    dz = a/b;
    pw = sqrt(a);
    pt = a*a
    cout<<"Wynik dodania a i b wynosi: "<<dod<<"."<<endl;
    cout<<"Wynik odjecia b od a wynosi: "<<od<<"."<<endl;
    cout<<"Wynik mnozenia a i b wynosi: "<<mn<<"."<<endl;
    cout<<"Wynik dzielenia a i b wynosi: "<<dz<<"."<<endl;
    cout<<"Wynik pierwiastkowania a wynosi: "<<pw<<"."<<endl;
    cout<<"Wynik potegowania a wynosi: "<<pt<<"."<<endl;
}