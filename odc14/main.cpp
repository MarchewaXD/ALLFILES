#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

clock_t start, stop;
double czas;

void sortowanie_babelkowe(int *tab, int n){
    for(int i=1; i<n; i++){
        for(int j=n-1; j>=1; j--){
            if(tab[j]<tab[j-1]){
                int bufor;
                bufor = tab[j-1];
                tab[j-1] = tab[j];
                tab[j] = bufor;
            }
        }
    }
}
void sortowanie_quicksort(int *tab, int lewy, int prawy){
     int v=tab[(lewy+prawy)/2];
     int i,j,x;
     i=lewy;
     j=prawy;
     do{
        while(tab[i]<v) i++;
        while(tab[j]>v) j--;
        if(i<=j){
            x=tab[i];
            tab[i] = tab[j];
            tab[j] = x;
            i++;
            j--;
        }
     } while(i<=j);
     if(j>lewy) sortowanie_quicksort(tab,lewy,j);
     if(i<prawy) sortowanie_quicksort(tab,i,prawy);
}
int main() {
    int ile;
    cout<<"Porownanie czasow sortowania v.1"<<endl;
    cout<<"Ile losowych liczb w tablicy: ";
    cin>>ile;

    //dynamiczna
    int *tablica;
    tablica = new int[ile];
    int *tablica2;
    tablica2 = new int[ile];
    srand(time(NULL));

    //wczytywanie losowych liczb
    for(int i=0; i<ile; i++){
        tablica[i] = rand()%100000+1;
        //cout<<tablica[i]<<" ";
    }
    for(int i=0; i<ile; i++){
        tablica2[i] = tablica[i];
    }
    /*
    cout<<"Przed posortowaniem"<<endl;
    for(int i=0; i<ile; i++){
        cout<<tablica2[i]<<" ";
    } */
                            //SORTOWANIE BABELKOWE
    cout<<endl<<"Sortuje teraz babelkowo. Prosze czekac."<<endl;
    start = clock();
    sortowanie_babelkowe(tablica, ile);
    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout<<endl<<"Czas wykonania: "<<czas<<" s"<<endl;
                            //SORTOWANIE QUICKSORT
    cout<<endl<<"Sortuje teraz quicksort. Prosze czekac."<<endl;
    start = clock();
    sortowanie_quicksort(tablica2, 0, ile-1);
    stop = clock();
    /*cout<<endl<<"Po posortowaniu"<<endl;
    for(int i=0; i<ile; i++){
        cout<<tablica[i]<<" ";
    } */
    czas = (double)(stop-start)/CLOCKS_PER_SEC;
    cout<<endl<<"Czas wykonania quicksort: "<<czas<<" s"<<endl;
    /*
    cout<<endl<<"Po posortowaniu"<<endl;
    for(int i=0; i<ile; i++){
        cout<<tablica2[i]<<" ";
    } */
    delete [] tablica;
    delete [] tablica2;
    return 0;
}