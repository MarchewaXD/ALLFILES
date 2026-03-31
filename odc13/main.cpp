#include <iostream>
#include <time.h>
using namespace std;

int funkcja(int n){
    if(n==0) return 3;
    else return funkcja(n-1)+2;
}

long int potega(int p, int w){
    if(w==0) return 1;
    else return p*potega(p,w-1);
}

long int fib(int nr_wyrazow){
    if(nr_wyrazow == 1 || nr_wyrazow == 2) return 1;
    else return fib(nr_wyrazow-1)+ fib(nr_wyrazow-2);
}

long int silnia(int n){
    if(n==0) return 1;
    else return n*silnia(n-1);
}
int main() {
    cout<<funkcja(3)<<endl;
    cout<<potega(3,4)<<endl;
    cout<<fib(6)<<endl;
    cout<<silnia(6)<<endl;
    return 0;
}