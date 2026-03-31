#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string napis = "Ala ma kota";
    transform(napis.begin(), napis.end(), napis.begin(), ::toupper);
    cout<<napis<<endl;
    transform(napis.begin(), napis.end(), napis.begin(), ::tolower);
    cout<<napis;

    string napisS = "Ala ma kota";
    string szukaj = "kot";
    size_t pozycja=napis.find((szukaj));
    if(pozycja!=string::npos){
        cout<<"Znaleziono na pozycji: "<<pozycja;
    }
    else{
        cout<<"Nie znaleziono";
    }

}