 #include <iostream>
 #include <fstream>
 #include <string>
 #include <cstdlib>
 #include <windows.h>
 #include <vector>
 #include <filesystem>
 using namespace std;
 namespace fs = std::filesystem;
 
void dodajOcene(){
    fstream dziennik;
    string przedmiot;
    int ocena=0;
    cout<<"Z jakiego przedmiotu chcesz dodać ocenę? Wpisuj nazwy używając podłogi i bez polskich znaków (np. jezyk_polski) ";
    cin>>przedmiot;
    cout<<"Jaka ocena? ";
    cin>>ocena;
    dziennik.open("oceny_" + przedmiot + ".txt", ios::app);
    if(!dziennik.good())
    {
    cout<<"Wystąpił problem!";
    return;
    }
    dziennik << ocena <<endl;
}

void usunOcene() {
    string przedmiot;
    int ocena;
    cout << "Z jakiego przedmiotu chcesz usunąć ocene? ";
    cin >> przedmiot;
    cout << "Jaka ocene? ";
    cin >> ocena;
    string nazwaPliku = "oceny_" + przedmiot + ".txt";
    fstream in;
    in.open(nazwaPliku, ios::in);
    if (!in.is_open()) {
        cout << "Nie można otworzyć pliku!" << endl;
        return;
    }
    vector<int> oceny;
    int x;
    while (in >> x) {
        oceny.push_back(x);
    }
    in.close();
    bool znaleziono = false;
    for (int i = (int)oceny.size() - 1; i >= 0; i--) {
        if (oceny[i] == ocena) {
            oceny.erase(oceny.begin() + i);
            znaleziono = true;
            break;
        }
    }
    if (!znaleziono) {
        cout << "Nie znaleziono takiej oceny!" << endl;
        return;
    }
    fstream out;
    out.open(nazwaPliku, ios::out);
    for (int o : oceny) {
        out << o << endl;
    }
    out.close();
    cout << "Usunieto ocene!" << endl;
}

void wyswietlOcene(){
    fstream dziennik;
    string przedmiot;
    cout<<"Z jakiego przedmiotu chcesz wyświetlić oceny? Nazwe zapisz nie używając polskich znaków, zamiast spacji użyj podłogi. ";
    cin>>przedmiot;
    dziennik.open("oceny_" + przedmiot + ".txt", ios::in);
    if(!dziennik.good()){
        cout<<"Wystąpił błąd!";
        return;
    }
    vector<int> oceny;
    int x;
    while(dziennik >> x){
        oceny.push_back(x);
    }
    cout<<"Oceny z pliku: "<<przedmiot<<".txt"<<endl;
    for(int i=0; i<oceny.size(); i++){
        cout<< oceny[i] <<" "<< endl;
    }
}

void obliczSredniaPrzedmiot(){
    string przedmiot;
    cout<<"Z jakiego przedmiotu chcesz obliczyc srednia? ";
    cin>>przedmiot;
    fstream dziennik;
    dziennik.open("oceny_" + przedmiot + ".txt", ios::in);
    if(!dziennik.good()){
        cout<<"Wystąpił błąd!";
        return;
    }
    vector<int> oceny;
    int x;
    while(dziennik >> x){
        oceny.push_back(x);
    }
    double suma = 0;
    int dzielnik = 0;
    for(int i=0; i<oceny.size(); i++){
        suma += oceny[i];
    }
    float srednia = suma/oceny.size();
    cout<<"Srednia ocen z "<<przedmiot<<" to: "<<srednia<<endl;
}
void obliczSredniaOgolna(){
    double sumaSrednich = 0;
    int liczbaPrzedmiotow = 0;
    for(const auto& entry : fs::directory_iterator(".")){
        string nazwa = entry.path().filename().string();
        if(nazwa.rfind("oceny_", 0) != 0) continue;
        if(nazwa.size()< 11) continue;
        if(nazwa.substr(nazwa.size() - 4) != ".txt") continue;
        string przedmiot = nazwa.substr(6, nazwa.size() - 10);
        fstream dziennik(nazwa, ios::in);
        vector<int> oceny;
        int x;
        while(dziennik >> x) oceny.push_back(x);
        if(oceny.empty()) continue;
        double suma = 0;
        for(int o : oceny) suma+= o;
        double srednia = suma/oceny.size();
        double czescDziesietna = srednia-(int)srednia;
        double zaokraglenie;
        if(czescDziesietna >=0.75) zaokraglenie = (int)srednia+1;
        else zaokraglenie = (int)srednia;
        cout<<przedmiot<<": "<<srednia<<" -> "<<zaokraglenie<<endl;
        sumaSrednich += zaokraglenie;
        liczbaPrzedmiotow++;
    }
    if(liczbaPrzedmiotow == 0){
        cout<<"Brak przedmiotów!"<<endl;
        return;
    }
    cout<<"Średnia ogólna: "<<sumaSrednich/liczbaPrzedmiotow<<endl;

}
 int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int wybor=0;
    do{
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"Witaj w dzienniku ocen!"<<endl;
    cout<<"---------------------------------------------------------"<<endl<<endl;
    cout<<"1. Dodaj oceny"<<endl;
    cout<<"2. Usuń oceny"<<endl;
    cout<<"3. Wyświetl oceny"<<endl;
    cout<<"4. Oblicz średnią z przedmiotu"<<endl;
    cout<<"5. Oblicz średnią ogólną"<<endl;
    cout<<"6. Wyjście"<<endl;
    cout<<"Wybierz działanie: ";
    cin>>wybor;
        switch(wybor){
            case 1: dodajOcene(); break;
            case 2: usunOcene(); break;
            case 3: wyswietlOcene(); break;
            case 4: obliczSredniaPrzedmiot(); break;
            case 5: obliczSredniaOgolna(); break;
            case 6: break;
        }
    } while(wybor!=6);
    return 0;
 }
