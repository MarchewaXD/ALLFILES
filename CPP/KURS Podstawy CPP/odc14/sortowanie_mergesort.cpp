#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void scal(int tab[], int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    int* L = new int[n1];
    int* P = new int[n2];

    // kopiowanie
    for (int i = 0; i < n1; i++)
        L[i] = tab[lewy + i];
    for (int i = 0; i < n2; i++)
        P[i] = tab[srodek + 1 + i];

    int i = 0, j = 0, k = lewy;

    // scalanie
    while (i < n1 && j < n2) {
        if (L[i] <= P[j]) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = P[j];
            j++;
        }
        k++;
    }

    // reszta elementów
    while (i < n1) {
        tab[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        tab[k] = P[j];
        j++; k++;
    }
    delete[] L;
    delete[] P;
}

void sortuj_przez_scalanie(int tab[], int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = (lewy + prawy) / 2;

        sortuj_przez_scalanie(tab, lewy, srodek);
        sortuj_przez_scalanie(tab, srodek + 1, prawy);

        scal(tab, lewy, srodek, prawy);
    }
}

int main() {
    int liczba;
    cout<<"Podaj liczbe losowych liczb w tablicy: ";
    cin>>liczba;
    int *tab;
    tab = new int[liczba];
    srand(time(NULL));
    for(int i=0; i<liczba; i++){
        tab[i] = rand()%100000+1;
    }
    cout<<"Sortuje teraz sposobem mergesort, prosze czekac."<<endl;
    clock_t start, stop;
    start = clock();
    sortuj_przez_scalanie(tab, 0, liczba-1);
    for(int i=0; i<liczba; i++){
        cout<<tab[i]<<" ";
    }
    stop = clock();

    float czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout<<"Czas wykonania: "<<czas;
    return 0;
}