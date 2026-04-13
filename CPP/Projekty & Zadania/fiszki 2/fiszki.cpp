 #include <iostream>
 #include <time.h>
 #include <string>
 using namespace std;
 
 int main() {
     string t[52];
     string t2[52];
        t[0] = "attend"; t2[0] = "uczeszczac";
        t[1] = "collaborate with sb"; t2[1] = "wspolpracowac z kims";
        t[2] = "cooperate with sb"; t2[2] = "wspolpracowac z kims";
        t[3] = "copy homework from sb"; t2[3] = "przepisywac prace domowa od kogos";
        t[4] = "discuss set books"; t2[4] = "omawiac lektury";
        t[5] = "do a task"; t2[5] = "wykonywac zadanie";
        t[6] = "do an activity/exercise"; t2[6] = "robic cwiczenie";
        t[7] = "do an experiment"; t2[7] = "przeprowadzic eksperyment";
        t[8] = "do well"; t2[8] = "dobrze sobie radzic";
        t[9] = "do your best"; t2[9] = "bardzo sie starac";
        t[10] = "expel sb from school"; t2[10] = "wydalic kogos ze szkoly";
        t[11] = "find it impossible to do sth"; t2[11] = "nie byc w stanie czegos zrobic";
        t[12] = "knowledge"; t2[12] = "wiedza";
        t[13] = "learn about sth"; t2[13] = "dowiadywac sie o czyms";
        t[14] = "learn new skills"; t2[14] = "nabyc nowych umiejetnosci";
        t[15] = "make progress"; t2[15] = "robic postepy";
        t[16] = "memorise"; t2[16] = "uczyc sie na pamiec";
        t[17] = "miss lessons"; t2[17] = "opuszczac lekcje";
        t[18] = "report findings"; t2[18] = "przedstawiac wyniki";
        t[19] = "study hard"; t2[19] = "uczyc sie pilnie";
        t[20] = "turn up late"; t2[20] = "spozniac sie";
        t[21] = "be off school"; t2[21] = "byc nieobecnym w szkole";
        t[22] = "catch up on"; t2[22] = "nadrobic";
        t[23] = "cause disruption"; t2[23] = "zaklocac porzadek";
        t[24] = "conduct an experiment"; t2[24] = "przeprowadzac eksperyment";
        t[25] = "excel at sth"; t2[25] = "celowac w czyms";
        t[26] = "expulsion"; t2[26] = "wydalenie ze szkoly";
        t[27] = "show up late"; t2[27] = "spoznic sie";
        t[28] = "achieve your aims"; t2[28] = "osiagnac swoje cele";
        t[29] = "advance"; t2[29] = "rozwijac sie";
        t[30] = "aim"; t2[30] = "cel";
        t[31] = "autonomous study"; t2[31] = "samodzielna nauka";
        t[32] = "develop"; t2[32] = "rozwijac";
        t[33] = "development"; t2[33] = "rozwoj";
        t[34] = "do a course"; t2[34] = "chodzic na kurs";
        t[35] = "goal"; t2[35] = "cel";
        t[36] = "improve"; t2[36] = "poprawic";
        t[37] = "learning objective"; t2[37] = "cel nauki";
        t[38] = "lack in"; t2[38] = "miec zbyt malo";
        t[39] = "motivator"; t2[39] = "czynnik motywujacy";
        t[40] = "online education"; t2[40] = "ksztalcenie na odleglosc";
        t[41] = "professional life"; t2[41] = "zycie zawodowe";
        t[42] = "self-motivated learner"; t2[42] = "uczen o silnej motywacji wewnetrznej";
        t[43] = "take an active role"; t2[43] = "brac aktywny udzial";
        t[44] = "think flexibly"; t2[44] = "myslec elastycznie";
        t[45] = "training"; t2[45] = "szkolenie";
        t[46] = "set clear targets"; t2[46] = "wyznaczac jasne cele";
        t[47] = "stick to your guns"; t2[47] = "obstawac przy swoim";
        t[48] = "cheat in an exam"; t2[48] = "sciagac na egzaminie";
        t[49] = "sit an exam"; t2[49] = "przystepowac do egzaminu";
        t[50] = "get good marks"; t2[50] = "dostawac dobre oceny";
        t[51] = "grade a test"; t2[51] = "sprawdzac test";
     srand(time(NULL));
     for(int i = 0; i<100; i++){
        int losowa = rand()%52;
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
