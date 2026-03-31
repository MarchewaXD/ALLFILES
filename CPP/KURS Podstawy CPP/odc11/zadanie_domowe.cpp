#include <iostream>
#include <cmath>
using namespace std;

float a=0,b,c,d,e,srednia, najb, minimum, maximum, roz1, roz2, roz3, roz4, roz5, najbs;

int main() {
    cout<<"Podaj 5 liczb po spacji: ";
    cin>>a>>b>>c>>d>>e;
                                                    //MINIMUM
    minimum=a;
    if (b<minimum){minimum=b;} 
    if (c<minimum) {minimum=c;}
    if (d<minimum) {minimum=d;}
    if (e<minimum) {minimum=e;}
    cout<<"Najmniejsza liczba: "<<minimum<<endl;
                                                    //MAXIMUM
    maximum=a;
    if (b>maximum) {maximum=b;}
    if (c>maximum) {maximum=c;}
    if (d>maximum) {maximum=d;}
    if (e>maximum) {maximum=e;}
    cout<<"Najwieksza liczba: "<<maximum<<endl;
                                                    //SREDNIA I NAJBLIZSZA SREDNIEJ
    srednia = (a+b+c+d+e)/5;
    cout<<"Srednia: "<<srednia<<endl;
    roz1 = fabs(a-srednia);
    roz2 = fabs(b-srednia);
    roz3 = fabs(c-srednia);
    roz4 = fabs(d-srednia);
    roz5 = fabs(e-srednia);
    najb = roz1;
    najbs = a;
    if(roz2<najb) {najb = roz2; najbs = b;}
    if(roz3<najb) {najb = roz3; najbs = c;}
    if(roz4<najb) {najb = roz4; najbs = d;}
    if(roz5<najb) {najb = roz5; najbs = e;}
    cout<<"Liczba najblizsza sredniej: ";
    if(fabs(a - srednia) == najb) cout << a << " ";
    if(fabs(b - srednia) == najb) cout << b << " ";
    if(fabs(c - srednia) == najb) cout << c << " ";
    if(fabs(d - srednia) == najb) cout << d << " ";
    if(fabs(e - srednia) == najb) cout << e << " ";
    return 0;
}
//Napisz program znajdujacy liczbe najblizsza sredniej z 5-ciu podanych liczb (mozesz pokazac ile wynosi srednia)