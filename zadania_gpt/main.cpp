#include <iostream>
using namespace std;

int ile_ocen, wybor, oceny[100], suma;
float srednia;

int main() {

    cout<<"Ile ocen chcesz wprowadzic (max 100): ";
    cin>>ile_ocen;
    if(ile_ocen <= 0){
        cout<<"Podano bledna ilosc ocen!";
        exit(0);
    }
    else if(ile_ocen > 100){
        cout<<"Podano zbyt duza ilosc ocen!";
        exit(0);
    }
    else{
        for(int i=1; i<= ile_ocen; i++){
            cout<<"Podaj "<<i<<" ocene: ";
            cin>>oceny[i-1];
            if((oceny[i-1]>6) || (oceny[i-1] <=0)){
                cout<<"Nie ma takiej oceny!";
                exit(0);
            }
        }
        do{

            cout<<"1. Wyswietl wszystkie oceny"<<endl;
            cout<<"2. Oblicz srednia"<<endl;
            cout<<"3. Znajdz najwyzsza ocene"<<endl;
            cout<<"4. Znajdz najnizsza ocene"<<endl;
            cout<<"5. Ile ocen jest >= 3"<<endl;
            cout<<"6. Policz oceny"<<endl;
            cout<<"7. Ile ocen jest powyzej sredniej"<<endl;
            cout<<"8. Wyjscie"<<endl;
            cout<<"Wybierz opcje:";
            cin>>wybor;
            switch(wybor){
                case 1:{
                    for(int i=1; i<=ile_ocen; i++){
                        cout<<"Ocena "<<i<<": "<<oceny[i-1]<<endl;
                    }
                break;
                }
                case 2:{
                    suma = 0;
                    for(int i=1; i<=ile_ocen; i++){
                        suma += oceny[i-1];
                    }
                    srednia = (float)suma/ile_ocen;
                    cout<<"Srednia ocen to: "<<srednia<<endl;
                    break;
                }
                case 3:{
                    int najwieksza = oceny[0];
                    for(int i=1; i<=ile_ocen; i++){
                        if(najwieksza < oceny[i-1]){
                            najwieksza = oceny[i-1];
                        }
                    }
                    cout<<"Najwieksza ocena to: "<<najwieksza<<endl;
                    break;
                }
                case 4:{
                    int najmniejsza = oceny[0];
                    for(int i=1; i<=ile_ocen; i++){
                        if(najmniejsza > oceny[i-1]){
                            najmniejsza = oceny[i-1];
                        }
                    }
                    cout<<"Najnizsza ocena to: "<<najmniejsza<<endl;
                    break;
                }
                case 5:{
                    int wiekszeodtrzy = 0;
                    for(int i=1; i<=ile_ocen; i++){
                        if(oceny[i-1]>=3){
                            wiekszeodtrzy += 1;
                        }
                    }
                    cout<<"Ilosc ocen wieksza badz rowna 3 to: "<<wiekszeodtrzy<<endl;
                    break;
                }
                case 6: {
                    int licznik[6] = {0};
                    for(int i = 0; i < ile_ocen; i++)
                        licznik[oceny[i]-1]++;
                    for(int i = 0; i < 6; i++)
                        cout << "Liczba ocen " << i+1 << ": " << licznik[i] << endl;
                    break;
                }
                case 7:{
                    suma = 0;
                    int powyzej_sredniej = 0;
                    for(int i=1; i<=ile_ocen; i++){
                        suma += oceny[i-1];
                    }
                    srednia = (float)suma/ile_ocen;
                    for(int i=1; i<=ile_ocen; i++){
                        if(oceny[i-1]>srednia){
                            powyzej_sredniej += 1;
                        }
                    }
                    cout<<"Liczba ocen powyzej sredniej: "<<powyzej_sredniej<<endl;
                    break;
                }
                case 8:{
                    cout<<"Koniec programu"<<endl;
                    break;
                }
            }
        } while(wybor != 8);
    }
    return 0;
}