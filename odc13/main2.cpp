#include <iostream>
#include <time.h>
using namespace std;

long long silnia(int n){
    if(n==0) return 1;
    else return n * silnia(n-1);
}

long long silniafor(int n){
    long long suma = 1;
    for(int i = 1; i <= n; i++){
        suma *= i;
    }
    return suma;
}

int main() {
    const int N = 15;
    const int POWTORZENIA = 1000000;

    clock_t start, stop;
    long long wynik;

    // 🔹 REKURENCJA
    start = clock();
    for(int i = 0; i < POWTORZENIA; i++){
        wynik = silnia(N);
    }
    stop = clock();
    double czas_rek = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << "Rekurencja wynik: " << wynik << endl;
    cout << "Czas rekurencji: " << czas_rek << endl;

    // 🔹 ITERACJA
    start = clock();
    for(int i = 0; i < POWTORZENIA; i++){
        wynik = silniafor(N);
    }
    stop = clock();
    double czas_iter = (double)(stop - start) / CLOCKS_PER_SEC;

    cout << "Iteracja wynik: " << wynik << endl;
    cout << "Czas iteracji: " << czas_iter << endl;

    return 0;
}