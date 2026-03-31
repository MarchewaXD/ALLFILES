 #include <iostream>
 #include <time.h>
 #include <string>
 using namespace std;
 
 int main() {
     string t[38];
     string t2[38];
     t[0] = "protection"; t2[0] = "ochrona";
     t[1] = "to commit a crime"; t2[1] = "popelnic przestepstwo";
     t[2] = "to embed"; t2[2] = "wbudowywac";
     t[3] = "malware"; t2[3] = "zlosliwe oprogramowanie";
     t[4] = "a subscriber"; t2[4] = "abonent";
     t[5] = "to take over"; t2[5] = "przejmowac";
     t[6] = "spam"; t2[6] = "niechciane wiadomosci";
     t[7] = "to detect"; t2[7] = "wykrywac";
     t[8] = "an attachment"; t2[8] = "zalacznik";
     t[9] = "to place"; t2[9] = "umiejscowic";
     t[10] = "a vulnerability"; t2[10] = "slaby punkt";
     t[11] = "vast"; t2[11] = "rozlegly";
     t[12] = "self replication"; t2[12] = "samokopiujacy sie";
     t[13] = "to forward"; t2[13] = "przeslac dalej";
     t[14] = "to break into"; t2[14] = "wlamac sie do";
     t[15] = "random"; t2[15] = "losowy";
     t[16] = "lower case letters"; t2[16] = "male litery";
     t[17] = "to encrypt"; t2[17] = "szyfrowac";
     t[18] = "to avoid"; t2[18] = "unikac";
     t[19] = "by default"; t2[19] = "domyslnie";
     t[20] = "malicious"; t2[20] = "zlosliwy";
     t[21] = "ransomware"; t2[21] = "oprogramowanie szantazujace";
     t[22] = "to double-click"; t2[22] = "dwukrotnie kliknac";
     t[23] = "spyware"; t2[23] = "oprogramowanie szpiegujace";
     t[24] = "to involve"; t2[24] = "wymagac";
     t[25] = "remotely"; t2[25] = "zdalnie";
     t[26] = "to steal"; t2[26] = "krasc";
     t[27] = "to contain"; t2[27] = "zawierac";
     t[28] = "intrusive"; t2[28] = "niepozadany";
     t[29] = "to access"; t2[29] = "miec dostep";
     t[30] = "a patch"; t2[30] = "poprawka";
     t[31] = "a scope of"; t2[31] = "zakres";
     t[32] = "to disable"; t2[32] = "unieruchamiac";
     t[33] = "to get access to sth"; t2[33] = "uzyskac dostep do czegos";
     t[34] = "upper case letters"; t2[34] = "duze litery";
     t[35] = "an identity theft"; t2[35] = "przywlaszczenie tozsamosci";
     t[36] = "a notification"; t2[36] = "powiadomienie";
     t[37] = "a firewall"; t2[37] = "zapora sieciowa";
     srand(time(NULL));
     for(int i = 0; i<100; i++){
        int losowa = rand()%38;
        string odp;
        int angpol = rand()%2;
        if(angpol == 0){
            cout<<"Co znaczy: "<<t[losowa]<<"?"<<endl;
            getline(cin, odp);
            if(odp == t2[losowa]) cout<<"Dobrze!"<<endl;
            else cout<<"Zle! Poprawna odpowiedz to: "<<t2[losowa]<<endl;
        }
        else{
            cout<<"Co znaczy: "<<t2[losowa]<<"?"<<endl;
            getline(cin,odp);
            if(odp == t[losowa]) cout<<"Dobrze!"<<endl;
            else cout<<"Zle! Poprawna odpowiedz to: "<<t[losowa]<<endl;
        }
     }
     return 0;
 }
