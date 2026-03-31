#include <iostream>
using namespace std;

int populacja=1, godzin=0;
int main() {
    do{
        godzin++;
        populacja=populacja*2;
        cout<<"Minelo godzin:"<<godzin;
        cout<<" liczba bakterii:"<<populacja<<endl;
    } while(populacja<=1000000000);
    // Aby zrobic bez do (while) trzeba po prostu dac tego while na sama gore i usunac do, reszta jest taka sama
}