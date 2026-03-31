#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a;
    cout<<"============================================"<<endl;
    cout<<""<<endl;
    cout<<"Czy liczba jest parzysta, czy nieparzysta?"<<endl;
    cout<<"Wpisz liczbe: ";
    cin>>a;
    if(a%2 == 0){
        int potega;
        potega = pow(a, 3);
        cout<<"Liczba jest parzysta, wynik jej potegi trzeciej wynosi: "<<potega;
    }
    else{
        int pierwiastek;
        pierwiastek = cbrt(a);
        cout<<"Liczba jest nieparzysta, wynik jej pierwiastka szesciennego wynosi: "<<pierwiastek;
    }
    return 0;
}
//B³êdy jakie mia³em:
//1.Zamiast int dalem float, dlatego "if(a%2 == 0) pokazywa³o b³¹d, poniewa¿ % jest do intu czyli calkowitch"
//*RADA NA PRZYSZLOSC, UZYWAJ FMOD
//2.Zamiast jakies sqrt sqrt mialem uzyc cbrt(a) (szescienny)
