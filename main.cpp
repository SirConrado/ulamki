#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
class ulamek{

    int calkowita, licznik, mianownik;
    double dziesietna;
public:
    ulamek(){
    calkowita = 1;
    licznik = 1;
    mianownik = 2;
    dziesietna = licznik / mianownik;
    }
    ulamek(int c, int l, int m){
    calkowita = c;
    licznik = l;
    mianownik = m;
    dziesietna = licznik / mianownik;
    }
    ulamek(ulamek &u){
    calkowita = u.calkowita;
    licznik = u.licznik;
    mianownik = u.mianownik;
    dziesietna = licznik / mianownik;
    }
    void wypisz(){
        if(licznik == 0)
             cout << calkowita << endl;
         else if(licznik == mianownik)
             cout << licznik << endl;
        else if(calkowita == 0)
            cout << licznik << "/" << mianownik << endl;
        else
    cout << calkowita << " " << licznik << "/" << mianownik << endl;
    }
    void wypiszDziesietne(){
        if(licznik == 0)
            dziesietna = calkowita;
        else{
        if(calkowita)
        dziesietna = (double(calkowita) * double(mianownik) + double(licznik)) / double(mianownik);
        else
        dziesietna = double(licznik) / double(mianownik);
        }
        cout << dziesietna << endl;
    }
    int getCalkowita(){
        return calkowita;
    }
    int getLicznik(){
        return licznik;
    }
    int getMianownik(){
        return mianownik;
    }
    void setCalkowita(int c){
        calkowita = c;
    }
    void setLicznik(int l){
        licznik = l;
    }
    void setMianownik(int m){
        mianownik = m;
    }
    ulamek & wyciagnijCalosci();
    ulamek & zamienNaDziesietne();
    ulamek & NWD();
    ulamek & skroc();
    ulamek & odwroc();
    ulamek & potegowanie(int wykladnik);
    ulamek & pierwiastkowanie();
    //ulamek & rozszerz(int m); // m - mianownik
    //int wspolnyMianownik(ulamek u1, ulamek u2);
    //ulamek & operator=(const ulamek & u);
    ulamek & operator=(const ulamek & u){
    (*this).calkowita = u.calkowita;
    (*this).licznik = u.licznik;
    (*this).mianownik = u.mianownik;

    //return * this;
    }
};
class menu{
    int menu1,wyswietlMenu;
public:
    menu(){
    menu1 = -1;
    wyswietlMenu = 1;
    }
    menu(int m1,int wM){
    menu1 = m1;
    wyswietlMenu = wM;
    }
    menu(menu & m){
    menu1 = m.menu1;
    wyswietlMenu = m.wyswietlMenu;
    }
    void wyswietlMenu1(){
    cout << "Witaj w programie ulamki. Wybierz co chcesz zrobic: " << endl;
    cout << "1 - skroc ulamki" << endl;
    cout << "2 - rozszerz ulamki" << endl;
    cout << "3 - wyciag calosci" << endl;
    cout << "4 - odwroc ulamek" << endl;
    cout << "5 - zamien na dziesietne" << endl;
    cout << "6 - dodaj ulamki" << endl;
    cout << "7 - odejmij ulamki" << endl;
    cout << "8 - pomnoz ulamki" << endl;
    cout << "9 - podziel ulamki" << endl;
    cout << "10 - potegowanie" << endl;
    cout << "11 - pierwiastkowanie" << endl;
    cout << "12 - dzialanie arytmetyczne z jednej linii" << endl;
    cout << "13 - wiele dzialan arytmetycznych z jednej linii" << endl;
    cout << "0 - wyjscie z programu" << endl;
    //cout << "11 - pierwiastkowanie" << endl;
    }
    int getMenu1(){
        return menu1;
    }
    int getWyswietlMenu(){
        return wyswietlMenu;
    }
    void setMenu1(int m){
        menu1 = m;
    }
    void setWyswietlMenu(int wM){
        wyswietlMenu = wM;
    }
};
ulamek & ulamek::wyciagnijCalosci(){
//ulamek uw;
if((*this).licznik > (*this).mianownik){
    (*this).calkowita += ((*this).licznik / (*this).mianownik);
    (*this).licznik = (*this).licznik % (*this).mianownik;
}
else if((*this).licznik < (-(*this).mianownik)){
     (*this).calkowita -= ((*this).licznik / (-(*this).mianownik));
      (*this).licznik = (*this).licznik % (-(*this).mianownik);
}
else if((*this).licznik == (*this).mianownik){
    (*this).calkowita += ((*this).licznik / (*this).mianownik);
    (*this).licznik = 0;
    (*this).mianownik = 1;
}
if((*this).licznik < 0)
    (*this).licznik = -(*this).licznik;
}
ulamek & ulamek::skroc(){
/*int x = 2;
while((*this).mianownik % x == 0){
     if((*this).mianownik % x == 0){
        (*this).mianownik /= x;
        (*this).licznik /= x;
     }
    x++;
}*/
// obliczanie NWD
int tymczasowa;
int m = (*this).mianownik;
int l = (*this).licznik;
while(m != 0){
    tymczasowa = m;
    m = l % m;
    l = tymczasowa;
}
// skracanie ulamkow przez NWD
(*this).mianownik /= l;
(*this).licznik /= l;
}
ulamek & ulamek::odwroc(){
int tMianownik = 0;
tMianownik = (*this).mianownik;
(*this).mianownik = (*this).licznik;
(*this).licznik = tMianownik;
}
ulamek & ulamek::potegowanie(int wykladnik = 2){
(*this).licznik = pow(double((*this).licznik),wykladnik);
(*this).mianownik = pow(double((*this).mianownik),wykladnik);
}
ulamek & ulamek::pierwiastkowanie(){
(*this).licznik = sqrt(double((*this).licznik));
(*this).mianownik = sqrt(double((*this).mianownik));
}
int wspolnyMianownik(ulamek u1, ulamek u2){
int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int tMianownik1 = 0, tMianownik2 = 0;
for(int i = 2; i <= 100; i++){
    tMianownik1 = u1Mianownik * i;
    //cout << tMianownik1 << " ";
    for(int j = 2; j <= 100; j++){
        tMianownik2 = u2Mianownik * j;
        if(tMianownik1 == tMianownik2){
            return tMianownik1;
        }
    }
}
}
void rozszerz(ulamek & u1, ulamek & u2, int m){
int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int u1Licznik = u1.getLicznik();
int u2Licznik = u2.getLicznik();
    int i1,i2; // i - o ile pomnozyc licznik
    i1 = m / u1Mianownik;
    i2 = m / u2Mianownik;
    u1Licznik *= i1;
    u2Licznik *= i2;
    u1Mianownik = m;
    u2Mianownik = m;
    u1.setLicznik(u1Licznik);
    u2.setLicznik(u2Licznik);
    u1.setMianownik(u1Mianownik);
    u2.setMianownik(u2Mianownik);
}

ulamek operator+(ulamek u1, ulamek u2){

int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int u1Licznik = u1.getLicznik();
int u2Licznik = u2.getLicznik();
int u1Calkowita = u1.getCalkowita();
int u2Calkowita = u2.getCalkowita();
int uwCalkowita, uwLicznik, uwMianownik;
ulamek uw;
//int tmianownik;
//uwCalkowita = u1Calkowita + u2Calkowita;
int wm = 0; // wm - wspolny mianownik
if(u1Mianownik !=u2Mianownik){
    wm = (wspolnyMianownik(u1,u2));
    uwMianownik = wm;
    u1Licznik *= wm / u1Mianownik;
    u2Licznik *= wm / u2Mianownik;
}
else{
    uwMianownik = u1Mianownik;
}
if(u1Calkowita > 0 && u2Calkowita == 0){
     u1Licznik += u1Calkowita * uwMianownik;
     uwLicznik = u1Licznik + u2Licznik;
     uwCalkowita = 0;
}
else if(u1Calkowita == 0 && u2Calkowita > 0){
    u2Licznik += u2Calkowita * uwMianownik;
    uwLicznik = u1Licznik + u2Licznik;
    uwCalkowita = 0;
}

else if(u1Calkowita > 0 && u2Calkowita > 0){
    u1Licznik += u1Calkowita * uwMianownik;
    u2Licznik += u2Calkowita * uwMianownik;
    uwLicznik = u1Licznik + u2Licznik;
    uwCalkowita = 0;
}
else{
     uwLicznik = u1Licznik + u2Licznik;
     uwCalkowita = 0;
}
//cout << uwCalkowita;
uw.setCalkowita(uwCalkowita);
uw.setLicznik(uwLicznik);
uw.setMianownik(uwMianownik);
return uw;
}

ulamek operator-(ulamek u1, ulamek u2){
int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int u1Licznik = u1.getLicznik();
int u2Licznik = u2.getLicznik();
int u1Calkowita = u1.getCalkowita();
int u2Calkowita = u2.getCalkowita();
int uwCalkowita, uwLicznik, uwMianownik;
ulamek uw;
//int tmianownik;
int wm = 0; // wm - wspolny mianownik
if(u1Mianownik !=u2Mianownik){
    wm = (wspolnyMianownik(u1,u2));
    uwMianownik = wm;
    u1Licznik *= wm / u1Mianownik;
    u2Licznik *= wm / u2Mianownik;
}
else{
    uwMianownik = u1Mianownik;
}
if(u1Calkowita > 0 && u2Calkowita == 0){
     u1Licznik += u1Calkowita * uwMianownik;
     uwLicznik = u1Licznik - u2Licznik;
     uwCalkowita = 0;
}
else if(u1Calkowita == 0 && u2Calkowita > 0){
    u2Licznik += u2Calkowita * uwMianownik;
    uwLicznik = u1Licznik - u2Licznik;
    uwCalkowita = 0;
}

else if(u1Calkowita > 0 && u2Calkowita > 0){
    u1Licznik += u1Calkowita * uwMianownik;
    u2Licznik += u2Calkowita * uwMianownik;
    uwLicznik = u1Licznik - u2Licznik;
    uwCalkowita = 0;
}
else{
     uwLicznik = u1Licznik - u2Licznik;
     uwCalkowita = 0;
}
uw.setCalkowita(uwCalkowita);
uw.setLicznik(uwLicznik);
uw.setMianownik(uwMianownik);
//uw.wyciagnijCalosci();
return uw;
}

ulamek operator*(ulamek u1, ulamek u2){
int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int u1Licznik = u1.getLicznik();
int u2Licznik = u2.getLicznik();
int u1Calkowita = u1.getCalkowita();
int u2Calkowita = u2.getCalkowita();
int uwCalkowita, uwLicznik, uwMianownik;
ulamek uw;
//int tmianownik;
uwMianownik = u1Mianownik * u2Mianownik;
if(u1Calkowita && u2Calkowita)
    uwLicznik = ((u1Calkowita * u1Mianownik) + u1Licznik) * ((u2Calkowita * u2Mianownik) + u2Licznik);
else if(u1Calkowita && u2Calkowita == 0)
    uwLicznik = ((u1Calkowita * u1Mianownik) + u1Licznik) * u2Licznik;
else if(u1Calkowita == 0 && u2Calkowita)
    uwLicznik = u1Licznik * ((u2Calkowita* u2Mianownik) + u2Licznik);
else
    uwLicznik = u1Licznik * u2Licznik;

uwCalkowita = 0;
//uw.wyciagnijCalosci();
uw.setCalkowita(uwCalkowita);
uw.setLicznik(uwLicznik);
uw.setMianownik(uwMianownik);
return uw;
}
ulamek operator/(ulamek u1, ulamek u2){
int u1Mianownik = u1.getMianownik();
int u2Mianownik = u2.getMianownik();
int u1Licznik = u1.getLicznik();
int u2Licznik = u2.getLicznik();
int u1Calkowita = u1.getCalkowita();
int u2Calkowita = u2.getCalkowita();
int uwCalkowita, uwLicznik, uwMianownik;
ulamek uw;
//int tmianownik;
int tLicznik1 = 0,tLicznik2 = 0;
//uw.mianownik = u1.mianownik * u2.mianownik;
if(u1Calkowita && u2Calkowita){
//uw.licznik = ((u1.calkowita * u1.mianownik) + u1.licznik) * ((u2.calkowita * u2.mianownik) + u2.licznik);
    tLicznik1 = ((u1Calkowita * u1Mianownik) + u1Licznik);
    tLicznik2 = ((u2Calkowita * u2Mianownik) + u2Licznik);
    uwLicznik = tLicznik1 * u2Mianownik;
    uwMianownik = u1Mianownik * tLicznik2;
}
else if(u1Calkowita && u2Calkowita == 0){
    tLicznik1 = ((u1Calkowita * u1Mianownik) + u1Licznik);
    uwLicznik = tLicznik1 * u2Mianownik;
    uwMianownik = u1Mianownik * u2Licznik;
}
else if(u1Calkowita == 0 && u2Calkowita){
    tLicznik2 = ((u2Calkowita * u2Mianownik) + u2Licznik);
    uwLicznik = u1Licznik * u2Mianownik;
    uwMianownik = u1Mianownik * tLicznik2;
}
else{
uwLicznik = u1Licznik * u2Mianownik;
uwMianownik = u1Mianownik * u2Licznik;
}
uwCalkowita = 0;
//uw.wyciagnijCalosci();
uw.setCalkowita(uwCalkowita);
uw.setLicznik(uwLicznik);
uw.setMianownik(uwMianownik);
return uw;
}
ostream & operator<<(ostream &o, ulamek u1){
int u1Mianownik = u1.getMianownik();
int u1Licznik = u1.getLicznik();
int u1Calkowita = u1.getCalkowita();
  if(u1Licznik == 0)
             o << u1Calkowita << endl;
         else if(u1Licznik == u1Mianownik)
             o << u1Licznik << endl;
        else if(u1Calkowita == 0)
            o << u1Licznik << "/" << u1Mianownik << endl;
        else
    o << u1Calkowita << " " << u1Licznik << "/" << u1Mianownik << endl;
return o;
}
int jednaLinia(string linia ,ulamek & u1, ulamek & u2){
 string liczba1C, liczba1U, liczba1L, liczba1M, liczba2C, liczba2U, liczba2L, liczba2M;
    int liczba1Calkowita, liczba1Ulamkowa, liczba1Licznik, liczba1Mianownik, liczba2Calkowita, liczba2Ulamkowa, liczba2Licznik, liczba2Mianownik;
    int znak, dzialanie;
    if( linia.find("+") != -1){
        znak = linia.find("+");
        dzialanie = 1;
    }
    else if(linia.find("-") != -1){
        znak =  linia.find("-");
        dzialanie = 2;
    }
    else if(linia.find("*") != -1){
        znak =  linia.find("*");
        dzialanie = 3;
    }
    else if(linia.find("/") != -1){
        znak =  linia.find("/");
        dzialanie = 4;
    }
    int dLinia = linia.size();
    string liczba1 = linia.substr(0,znak - 1);
    string liczba2 = linia.substr(znak + 2,dLinia);
    int spacja1 = liczba1.find(" ");
    int spacja2 = liczba2.find(" ");
    int kreska1 = -1, kreska2 = -1;


    if(spacja1 != -1){
            //cout << spacja1;
        liczba1C = liczba1.substr(0,spacja1);
        liczba1U = liczba1.substr(spacja1 + 1,liczba1.size());
         //cout << liczba1C << " " << liczba1U;
        if(liczba1.find("/") != -1){
            kreska1 = liczba1U.find("/");
            liczba1L = liczba1U.substr(0,kreska1);
            liczba1M = liczba1U.substr(kreska1 + 1, liczba1U.size());
        }
    }
    else if(liczba1.find("/") != -1){
            kreska1 = liczba1.find("/");
            liczba1L = liczba1.substr(0,kreska1);
            liczba1M = liczba1.substr(kreska1 + 1, liczba1.size());
    }
    else{
        liczba1C = liczba1.substr(0,liczba1.size());
        //cout << liczba1C;
    }
     if(spacja2 != -1){
        // cout << spacja2;
        liczba2C = liczba2.substr(0,spacja2);
        liczba2U = liczba2.substr(spacja2 + 1,liczba2.size());
         //cout << liczba2C <<" " << liczba2U;
        if(liczba2.find("/") != -1){
            kreska2 = liczba2U.find("/");
            liczba2L = liczba2U.substr(0,kreska2);
            liczba2M = liczba2U.substr(kreska2 + 1, liczba2U.size());
        }
     }
      else if(liczba2.find("/") != -1){
            kreska2 = liczba2.find("/");
           // cout << kreska2;
            liczba2L = liczba2.substr(0,kreska2);
            liczba2M = liczba2.substr(kreska2 + 1, liczba2.size());
            //cout << liczba2L << " " << liczba2M;
    }
    else{
         liczba2C = liczba2.substr(0,liczba2.size());
    }
    if(spacja1 != -1)
        liczba1Calkowita = atoi(liczba1C.c_str());
    if(kreska1 != -1){
        liczba1Licznik = atoi(liczba1L.c_str());
        liczba1Mianownik = atoi(liczba1M.c_str());
    }
    if(spacja1 == -1 && kreska1 == -1){
        liczba1Calkowita = atoi(liczba1C.c_str());
        //cout << liczba2Calkowita;
    }
    if(spacja1 != -1 && kreska1 != -1){
        u1.setCalkowita(liczba1Calkowita);
        u1.setLicznik(liczba1Licznik);
        u1.setMianownik(liczba1Mianownik);
    }
    else if(spacja1 == -1 && kreska1 != -1){
        u1.setCalkowita(0);
        u1.setLicznik(liczba1Licznik);
        u1.setMianownik(liczba1Mianownik);
        //cout << u1.getCalkowita() << " " << u1.getLicznik() << "/" << u1.getMianownik();
    }
    else if(spacja1 != -1 && kreska1 == -1){
        u1.setCalkowita(liczba1Calkowita);
        u1.setLicznik(0);
        u1.setMianownik(1);
    }
    else if(spacja1 == -1 && kreska1 == -1){
      //  cout << liczba1Calkowita;
        u1.setCalkowita(liczba1Calkowita);
        u1.setLicznik(0);
        u1.setMianownik(1);
    }

    //cout << liczba1Calkowita << " " << liczba1Licznik << "/" << liczba1Mianownik << endl;
     if(spacja2 != -1)
        liczba2Calkowita = atoi(liczba2C.c_str());
    if(kreska2 != -1){
        liczba2Licznik = atoi(liczba2L.c_str());
        liczba2Mianownik = atoi(liczba2M.c_str());
    }
      if(spacja2 == -1 && kreska2 == -1){
        liczba2Calkowita = atoi(liczba2C.c_str());
        //cout << liczba2Calkowita;
    }
    //cout << liczba2Licznik << "/" << liczba2Mianownik << endl;
    if(spacja2 != -1 && kreska2 != -1){
        u2.setCalkowita(liczba2Calkowita);
        u2.setLicznik(liczba2Licznik);
        u2.setMianownik(liczba2Mianownik);
    }
    else if(spacja2 == -1 && kreska2 != -1){
        u2.setCalkowita(0);
        u2.setLicznik(liczba2Licznik);
        u2.setMianownik(liczba2Mianownik);
    }
    else if(spacja2 != -1 && kreska2 == -1){
        u2.setCalkowita(liczba2Calkowita);
        u2.setLicznik(1);
        u2.setMianownik(0);
    }
     else if(spacja2 == -1 && kreska2 == -1){
       // cout << liczba2Calkowita;
        u2.setCalkowita(liczba2Calkowita);

        u2.setLicznik(0);
        u2.setMianownik(1);
    }
    return dzialanie;
}
int * jednaLiniaWieleDzialan(string linia, ulamek *& u){
    string * liczba = new string[10];
    string * liczbaC = new string[10];
    string * liczbaU = new string[10];
    string * liczbaL = new string[10];
    string * liczbaM = new string[10];
    int * liczbaCalkowita = new int[10];
    int * liczbaUlamkowa = new int[10];
    int * liczbaLicznik = new int[10];
    int * liczbaMianownik = new int[10];
    int * dzialanie = new int[10];
    int * miejsceDzialan = new int[10];
    int * miejsceSpacji = new int[10];
    int * miejsceKresek = new int[10];
    int counterDzialan = 0;
    int dLinia = linia.size();
    for(int i = 0; i < dLinia; i++){
        if(i > 0 && i < dLinia && linia[i + 1] == ' ' && linia[i - 1] == ' '){
             if(linia[i] == '+' || linia[i] == '-' || linia[i] == '*' || linia[i] == '/'){
                if(linia[i] == '+')
                    dzialanie[counterDzialan] = 1;
                else if(linia[i] == '-')
                    dzialanie[counterDzialan] = 2;
                else if(linia[i] == '*')
                    dzialanie[counterDzialan] = 3;
                else if(linia[i] == '/')
                    dzialanie[counterDzialan] = 4;
                miejsceDzialan[counterDzialan] = i;
                counterDzialan++;
             }
        }
    }
   // cout << miejsceDzialan[0] << " " << miejsceDzialan[1];
    //cout << counterDzialan;
    // int x = 0;
     for(int i = 0; i <= counterDzialan; i++){
        if(i == 0){
            liczba[i] = linia.substr(0,miejsceDzialan[i] - 1);
        }
        else if(i == counterDzialan){
            liczba[i] = linia.substr(miejsceDzialan[i - 1] + 2,dLinia - 2);
        }
        else{
            liczba[i] = linia.substr(miejsceDzialan[i - 1] + 2, miejsceDzialan[i] - miejsceDzialan[i - 1] - 3);
            //cout << liczba[i] << endl;
        }
        //cout << liczba[i] << " ";
        if(liczba[i].find(" ") == -1){
           // cout << liczba[i] << endl;
            miejsceSpacji[i] = -1;
            if(liczba[i].find("/") != -1){
            miejsceKresek[i] = liczba[i].find("/");
            //liczbaU[i] = liczba[i].substr(0, liczba[i].size());
            liczbaL[i] = liczba[i].substr(0, miejsceKresek[i]);
            liczbaM[i] = liczba[i].substr(miejsceKresek[i] + 1, liczba[i].size());
            //cout << liczbaL[i] << " " << liczbaM[i];
            }
            else{
                liczbaC[i] = liczba[i].substr(0, liczba[i].size());
                miejsceKresek[i] = -1;
                //cout << liczbaC[i] << endl;
                //cout << liczbaC[i] << endl;
            }
        }
        else{
             miejsceSpacji[i] = liczba[i].find(" ");
             liczbaC[i] = liczba[i].substr(0,miejsceSpacji[i]);
             liczbaU[i] = liczba[i].substr(miejsceSpacji[i] + 1, liczba[i].size());
             miejsceKresek[i] = liczbaU[i].find("/");

             liczbaL[i] = liczbaU[i].substr(0, miejsceKresek[i]);
             liczbaM[i] = liczbaU[i].substr(miejsceKresek[i] + 1, liczba[i].size());
        }
        if(miejsceSpacji[i] != -1)
            liczbaCalkowita[i] = atoi(liczbaC[i].c_str());
        if(miejsceKresek[i] != -1){
            liczbaLicznik[i] = atoi(liczbaL[i].c_str());
            liczbaMianownik[i] = atoi(liczbaM[i].c_str());
            //cout << liczbaLicznik[i] << " " << liczbaMianownik[i] << endl;
        }
        if(miejsceSpacji[i] == -1 && miejsceKresek[i] == -1){
            liczbaCalkowita[i] = atoi(liczbaC[i].c_str());
            //cout << liczbaCalkowita[i] << endl;
        //cout << liczba2Calkowita;
        }
        if(miejsceSpacji[i] != -1 && miejsceKresek[i] != -1){
            u[i].setCalkowita(liczbaCalkowita[i]);
            u[i].setLicznik(liczbaLicznik[i]);
            u[i].setMianownik(liczbaMianownik[i]);
        }
        else if(miejsceSpacji[i] == -1 && miejsceKresek[i] != -1){
            u[i].setCalkowita(0);
            u[i].setLicznik(liczbaLicznik[i]);
            u[i].setMianownik(liczbaMianownik[i]);
            //cout << u[i].getLicznik() << "  " << u[i].getMianownik();
        }
        else if(miejsceSpacji[i] != -1 && miejsceKresek[i] == -1){
            u[i].setCalkowita(liczbaCalkowita[i]);
            u[i].setLicznik(1);
            u[i].setMianownik(0);
        }
         else if(miejsceSpacji[i] == -1 && miejsceKresek[i] == -1){
            u[i].setCalkowita(liczbaCalkowita[i]);
            u[i].setLicznik(0);
            u[i].setMianownik(1);
            //cout << u[i].getCalkowita() << endl;
        }

     }
     //cout << liczbaC[2] << " " << liczbaU[2];

    return dzialanie;
}
int main()
{
    ulamek u1, u2, u3;
    menu m;
    int m1, licznik1, mianownik1, calkowita1,tymczasowa1, licznik2, mianownik2, calkowita2, dzialanie;
    string linia;
    while(m.getMenu1() != 0){
        m.wyswietlMenu1();
        cin >> m1;
        //m.setMenu1(m1);
         if(m1 == 1){
            system("CLS");
            cout << "Skracanie ulamkow:" << endl;
            cout << "Podaj licznik: ";
            cin >> licznik1;
            cout << "Podaj mianownik: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.skroc();
            cout << u1;
            //ulamek u1;
         }
         else if(m1 == 2){
              system("CLS");
            cout << "Rozszerzanie ulamkow: " << endl;
            cout << "Podaj licznik 1-ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik 1-ulamka: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
             cout << "Podaj licznik 2-ulamka: ";
            cin >> licznik2;
            cout << "Podaj mianownik 2-ulamka: ";
            cin >> mianownik2;
            ulamek u2(0,licznik2,mianownik2);
            cout << "Podaj do jakiego mianownika chcesz rozszerzyc: ";
            cin >> tymczasowa1;
            rozszerz(u1,u2,tymczasowa1);
            u1.wyciagnijCalosci();
            u2.wyciagnijCalosci();
            cout << "Pierwszy ulamek: " << u1 << "Drugi ulamek: " << u2;
         }
         else if(m1 == 3){
            system("CLS");
            cout << "Wyciaganie calosci:" << endl;
             cout << "Podaj licznik: ";
            cin >> licznik1;
            cout << "Podaj mianownik: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.wyciagnijCalosci();
            cout << u1;
         }
         else if(m1 == 4){
             system("CLS");
            cout << "Odwracanie ulamkow:" << endl;
            cout << "Podaj licznik: ";
            cin >> licznik1;
            cout << "Podaj mianownik: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.odwroc();
            u1.wyciagnijCalosci();
            cout << u1;
         }
         else if(m1 == 5){
             system("CLS");
            cout << "Zamien na dziesietne:" << endl;
            cout << "Podaj licznik: ";
            cin >> licznik1;
            cout << "Podaj mianownik: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.wypiszDziesietne();
         }
         else if(m1 == 6){
            system("CLS");
            cout << "Dodawanie ulamkow:" << endl;
            cout << "Podaj czesc calkowita 1-ulamka: ";
            cin >> calkowita1;
            cout << "Podaj licznik 1-ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik 1-ulamka: ";
            cin >> mianownik1;
            ulamek u1(calkowita1,licznik1,mianownik1);
            cout << "Podaj czesc calkowita 2-ulamka: ";
            cin >> calkowita2;
             cout << "Podaj licznik 2-ulamka: ";
            cin >> licznik2;
            cout << "Podaj mianownik 2-ulamka: ";
            cin >> mianownik2;
            ulamek u2(calkowita2,licznik2,mianownik2);
            ulamek u3;
            u3 = u1 + u2;
            u3.wyciagnijCalosci();
            cout << "Ulamek wynikowy: " << u3;
         }
         else if(m1 == 7){
            system("CLS");
            cout << "Odejmowanie ulamkow:" << endl;
            cout << "Podaj czesc calkowita 1-ulamka: ";
            cin >> calkowita1;
            cout << "Podaj licznik 1-ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik 1-ulamka: ";
            cin >> mianownik1;
            ulamek u1(calkowita1,licznik1,mianownik1);
            cout << "Podaj czesc calkowita 2-ulamka: ";
            cin >> calkowita2;
             cout << "Podaj licznik 2-ulamka: ";
            cin >> licznik2;
            cout << "Podaj mianownik 2-ulamka: ";
            cin >> mianownik2;
            ulamek u2(calkowita2,licznik2,mianownik2);
            ulamek u3;
            u3 = u1 - u2;
            u3.wyciagnijCalosci();
            cout << "Ulamek wynikowy: " << u3;
         }
        else if(m1 == 8){
            system("CLS");
            cout << "Mnozenie ulamkow:" << endl;
            cout << "Podaj czesc calkowita 1-ulamka: ";
            cin >> calkowita1;
            cout << "Podaj licznik 1-ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik 1-ulamka: ";
            cin >> mianownik1;
            ulamek u1(calkowita1,licznik1,mianownik1);
            cout << "Podaj czesc calkowita 2-ulamka: ";
            cin >> calkowita2;
             cout << "Podaj licznik 2-ulamka: ";
            cin >> licznik2;
            cout << "Podaj mianownik 2-ulamka: ";
            cin >> mianownik2;
            ulamek u2(calkowita2,licznik2,mianownik2);
            ulamek u3;
            u3 = u1 * u2;
            u3.wyciagnijCalosci();
            cout << "Ulamek wynikowy: " << u3;
         }
          else if(m1 == 9){
            system("CLS");
            cout << "Dzielenie ulamkow:" << endl;
            cout << "Podaj czesc calkowita 1-ulamka: ";
            cin >> calkowita1;
            cout << "Podaj licznik 1-ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik 1-ulamka: ";
            cin >> mianownik1;
            ulamek u1(calkowita1,licznik1,mianownik1);
            cout << "Podaj czesc calkowita 2-ulamka: ";
            cin >> calkowita2;
             cout << "Podaj licznik 2-ulamka: ";
            cin >> licznik2;
            cout << "Podaj mianownik 2-ulamka: ";
            cin >> mianownik2;
            ulamek u2(calkowita2,licznik2,mianownik2);
            ulamek u3;
            u3 = u1 / u2;
            u3.wyciagnijCalosci();
            cout << "Ulamek wynikowy: " << u3;
         }
         else if(m1 == 10){
            system("CLS");
            cout << "Potegowanie ulamkow:" << endl;
            cout << "Podaj licznik ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik ulamka: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.potegowanie();
            cout << "Ulamek wynikowy: " << u1;
         }
          else if(m1 == 11){
            system("CLS");
            cout << "Pierwiastkowanie ulamkow:" << endl;
            cout << "Podaj licznik ulamka: ";
            cin >> licznik1;
            cout << "Podaj mianownik ulamka: ";
            cin >> mianownik1;
            ulamek u1(0,licznik1,mianownik1);
            u1.pierwiastkowanie();
            cout << "Ulamek wynikowy: " << u1;
         }
         else if(m1 == 12){
              system("CLS");
              cout << "Dzialania arytmetyczne z jednej linii:" << endl;
              cout << "Podaj dwie liczby w jednej linni, miedzy nimi wstaw znak arytmetyczny(+,-,*,/)" << endl;
              cin.ignore();
              getline(cin, linia);
             // cout << linia;
              dzialanie = jednaLinia(linia, u1, u2);
            //  cout << u1 << u2;
                if(dzialanie == 1)
                    u3 = u1 + u2;
                else if(dzialanie == 2)
                    u3 = u1 - u2;
                else if(dzialanie == 3)
                    u3 = u1 * u2;
                else if(dzialanie == 4)
                    u3 = u1 / u2;
                u3.wyciagnijCalosci();
                u3.skroc();
             //  cout << u3.getLicznik() << " " << u3.getMianownik();
                cout << "Ulamek wynikowy: " << u3;
         }
         else if(m1 == 13){
                system("CLS");
                cout << "Dzialania arytmetyczne z jednej linii:" << endl;
                cout << "Podaj kilka liczb w jednej linni, miedzy nimi wstaw znak arytmetyczny(+,-,*,/)" << endl;
                cin.ignore();
                getline(cin, linia);
                //linia = "1/2 + 1/4";
                ulamek * u = new ulamek[10];
                int * dzialania = new int[10];
                int iloscDzialan = 0;
                dzialania = jednaLiniaWieleDzialan(linia, u);
                while(dzialania[iloscDzialan] != 0){
                    iloscDzialan++;
                }
                ulamek uw = u[0];
               // cout << u[0] << u[1] << u[2];
                for(int i = 1; i <= iloscDzialan; i++){
                    if(dzialania[i - 1] == 1)
                        uw = uw + u[i];
                    else if(dzialania[i - 1] == 2)
                        uw = uw - u[i];
                    else if(dzialania[i - 1] == 3)
                        uw = uw * u[i];
                    else if(dzialania[i - 1] == 4)
                        uw = uw / u[i];
                    //cout << u[i];
                }
                uw.wyciagnijCalosci();
                uw.skroc();
                cout << "Ulamek wynikowy: " << uw;
            }
         else if(m1 == 0)
            break;
         else{
            cout << "Bledna liczba." << endl;
            //m.wyswietlMenu1();
            //cin >> m1;
         }

    }

   /* ulamek u1,u2(0,7,2),u3(u2);
   cout << u1;
   cout << u2;
   cout << u3;
    u3 = u1 + u2;
    u3.wyciagnijCalosci();
   cout << u3;
   // u3.wypiszDziesietne();
    u3 = u1 - u2;
    u3.wyciagnijCalosci();
    cout << u3;
    u3 = u1 * u2;
    u3.wyciagnijCalosci();
    cout << u3;
    u3 = u1 / u2;
    u3.wyciagnijCalosci();
    u3.skroc();
    cout << u3;
    ulamek u4(0,2,4),u5(0,4,6),u6;
    cout << u4;
   // u4.skroc();
    //cout << u4.licznik << " " << u4.mianownik << endl;
   // u4.wypisz();
    cout << u5;
    u6 = u5 - u4;
    cout << u6;
    u6.odwroc();
    u6.wyciagnijCalosci();
    cout << u6;
    rozszerz(u4,u5,12);
    cout << u4 << u5;
    ulamek u7(0,2,4);
    //u7.skroc();
    u7.potegowanie();
    u7.skroc();
    cout << u7;
    //cout << endl << endl << wspolnyMianownik(u4,u5) << endl << endl;
    //u3.wypiszDziesietne();*/
    return 0;
}
