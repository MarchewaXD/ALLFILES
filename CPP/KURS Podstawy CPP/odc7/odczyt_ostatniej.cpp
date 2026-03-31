#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    string imie;
    cout<<"Podaj imie: ";
    cin>>imie;
    int dlugosc;
    dlugosc = imie.length();
    if(imie[dlugosc-1]=='a'){
        cout<<"Wydaje mi sie ze jestes kobieta!";
    }
    else{
        cout<<"Wydaje mi sie ze jestes facetem";
    }
    return 0;
}