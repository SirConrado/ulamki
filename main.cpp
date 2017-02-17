#include <iostream>
#include <math.h>
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
        else
        dziesietna = licznik / mianownik;
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
    ulamek & skroc();
    ulamek & odwroc();
    ulamek & potegowanie(int wykladnik);
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
}
ulamek & ulamek::skroc(){
int x = 2;
while((*this).mianownik % x == 0){
     if((*this).mianownik % x == 0){
        (*this).mianownik /= x;
        (*this).licznik /= x;
     }
    x++;
}
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
uwCalkowita = u1Calkowita + u2Calkowita;
if(u1Mianownik != u2Mianownik){
    uwMianownik = u1Mianownik * u2Mianownik;
    uwLicznik = (u1Licznik * u2Mianownik) + (u2Licznik * u1Mianownik);
}
else{
    uwMianownik = u1Mianownik;
    uwLicznik = u1Licznik + u2Licznik;
}
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
if(u2Licznik >= u1Licznik)
    uwCalkowita = u1Calkowita - u2Calkowita - (u1Licznik / u2Licznik);
else{
    uwCalkowita = u1Calkowita - u2Calkowita;
}
if(u1Mianownik !=u2Mianownik){
    wm = wspolnyMianownik(u1,u2);
    uwMianownik = wm;
    //uw.mianownik = u1.mianownik * u2.mianownik;
    uwLicznik = (u1Licznik * (wm / u1Mianownik)) - (u2Licznik * (wm  / u2Mianownik ));
}
else{
    uwMianownik = u1Mianownik;
    uwLicznik = u1Licznik - u2Licznik;
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
int main()
{
    ulamek u1,u2(0,7,2),u3(u2);
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
    //u3.wypiszDziesietne();
    return 0;
}
