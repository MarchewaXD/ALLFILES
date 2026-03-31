#include <iostream>
using namespace std;
int main(){
    float a, b,c;
    cout<<"Program ten sprawdza ktora z trzech kolejno podanych liczb jest najmniejsza"<<endl;
    cout<<"Podaj 3 liczby rzeczywiste: "<<endl;
    cin>>a>>b>>c;
    if(a <= b && a <=c){
        cout<<"Najmniejsza liczba to: "<<a;
    }
    else if(b <= a && b <= c){
        cout<<"Najmniejsza liczba to: "<<b;
    }
    else{
        cout<<"Najmniejsza liczba to: "<<c;
    }
    return 0;
}
