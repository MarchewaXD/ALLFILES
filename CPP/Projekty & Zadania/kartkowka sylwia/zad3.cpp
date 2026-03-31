#include <iostream>
#include <cmath>
using namespace std;
int main(){
    char wybor;
    cout<<"Program obliczajacy pole i obwod wybranej figury"<<endl;
    cout<<"Wybierz jaka figure chcialbys obliczyc (a/b/c): "<<endl;
    cout<<"a) Prostokat"<<endl;
    cout<<"b) Trapez"<<endl;
    cout<<"c) Trojkat"<<endl;
    cin>>wybor;
    switch(wybor){
    case 'a':
    case 'A':
        float prostokatA, prostokatB, prostokatPole, prostokatObwod;
        cout<<"Podaj kolejno 2 boki prostokata: "<<endl;
        cin>>prostokatA>>prostokatB;
        prostokatPole = prostokatA * prostokatB;
        prostokatObwod = (2*prostokatA)+(2*prostokatB);
        cout<<"Prostokat o bokach "<<prostokatA<<" i "<<prostokatB<<" posiada pole o powierzchni "<<prostokatPole<<" i obwod dlugosci "<<prostokatObwod;
        break;
    case 'b':
    case 'B':
        float trapezA, trapezB, trapezC, trapezD, trapezH, trapezPole, trapezObwod;
        cout<<"Podaj kolejno 4 boki trapezu i jego wysokosc: "<<endl;
        cin>>trapezA>>trapezB>>trapezC>>trapezD>>trapezH;
        trapezPole = ((trapezA+trapezB)*trapezH)/2;
        trapezObwod = trapezA+trapezB+trapezC+trapezD;
        cout<<"Trapez o bokach "<<trapezA<<", "<<trapezB<<", "<<trapezC<<", "<<trapezD<<" i wysokosci "<<trapezH<<" posiada pole o powierzchni "<<trapezPole<<" i obwod dlugosci "<<trapezObwod;
        break;
    case 'c':
    case 'C':
        float trojkatA, trojkatB, trojkatC, trojkatH, trojkatPole, trojkatObwod;
        cout<<"Podaj kolejno 3 boki trojkata i jego wysokosc: "<<endl;
        cin>>trojkatA>>trojkatB>>trojkatC>>trojkatH;
        trojkatPole = (trojkatA*trojkatH)/2;
        trojkatObwod = trojkatA+trojkatB+trojkatC;
        cout<<"Trojkat o bokach "<<trojkatA<<", "<<trojkatB<<", "<<trojkatC<<" i wysokosci "<<trojkatH<<" posiada pole o powierzchni "<<trojkatPole<<" i obwod dlugosci "<<trojkatObwod;
        break;
    default:
        cout<<"Niestety podales zly wybor";
        break;
    }
    return 0;
}
