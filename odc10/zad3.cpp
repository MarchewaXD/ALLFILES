#include <iostream>
#include <cstdlib>
using namespace std;

float srednia(float *tab, int ile){
    float suma = 0;
    for(int i = 0; i < ile; i++){
        suma += tab[i];
    }
    return suma / ile;
}

int main() {
    int ile;
    cout << "Ile rubryk w tablicy: ";
    cin >> ile;

    if(ile > 0){
        float *tablica = new float[ile];  // ✅ poprawna alokacja

        for(int i = 0; i < ile; i++){
            tablica[i] = i;  // przykładowe wartości
        }

        cout << "Srednia: " << srednia(tablica, ile) << endl;

        delete[] tablica; // ✅ zwolnienie pamięci
    }
    else{
        cout << "Blad!";
        exit(0);
    }

    return 0;
}