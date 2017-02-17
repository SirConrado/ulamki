#include <iostream>
#include <math.h>
using namespace std;
class ulamek{
public:
    int calkowita, licznik, mianownik;
    double dziesietna;

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
int tMianownik1 = 0, tMianownik2 = 0;
for(int i = 2; i <= 100; i++){
    tMianownik1 = u1.mianownik * i;
    //cout << tMianownik1 << " ";
    for(int j = 2; j <= 100; j++){
        tMianownik2 = u2.mianownik * j;
        if(tMianownik1 == tMianownik2){
            return tMianownik1;
        }
    }
}
}
void rozszerz(ulamek & u1, ulamek & u2, int m){
    int i1,i2; // i - o ile pomnozyc licznik
    i1 = m / u1.mianownik;
    i2 = m / u2.mianownik;
    u1.licznik *= i1;
    u2.licznik *= i2;
    u1.mianownik = m;
    u2.mianownik = m;
}

ulamek operator+(ulamek u1, ulamek u2){
ulamek uw;
//int tmianownik;
uw.calkowita = u1.calkowita + u2.calkowita;
if(u1.mianownik != u2.mianownik){
    uw.mianownik = u1.mianownik * u2.mianownik;
    uw.licznik = (u1.licznik * u2.mianownik) + (u2.licznik * u1.mianownik);
}
else{
    uw.mianownik = u1.mianownik;
    uw.licznik = u1.licznik + u2.licznik;
}
return uw;
}

ulamek operator-(ulamek u1, ulamek u2){
ulamek uw;
//int tmianownik;
int wm = 0; // wm - wspolny mianownik
if(u2.licznik >= u1.licznik)
    uw.calkowita = u1.calkowita - u2.calkowita - (u1.licznik / u2.licznik);
else{
    uw.calkowita = u1.calkowita - u2.calkowita;
}
if(u1.mianownik != u2.mianownik){
    wm = wspolnyMianownik(u1,u2);
    uw.mianownik = wm;
    //uw.mianownik = u1.mianownik * u2.mianownik;
    uw.licznik = (u1.licznik * (wm / u1.mianownik)) - (u2.licznik * (wm  / u2.mianownik ));
}
else{
    uw.mianownik = u1.mianownik;
    uw.licznik = u1.licznik - u2.licznik;
}
//uw.wyciagnijCalosci();
return uw;
}

ulamek operator*(ulamek u1, ulamek u2){
ulamek uw;
//int tmianownik;
uw.mianownik = u1.mianownik * u2.mianownik;
if(u1.calkowita && u2.calkowita)
    uw.licznik = ((u1.calkowita * u1.mianownik) + u1.licznik) * ((u2.calkowita * u2.mianownik) + u2.licznik);
else if(u1.calkowita && u2.calkowita == 0)
    uw.licznik = ((u1.calkowita * u1.mianownik) + u1.licznik) * u2.licznik;
else if(u1.calkowita == 0 && u2.calkowita)
    uw.licznik = u1.licznik * ((u2.calkowita * u2.mianownik) + u2.licznik);
else
    uw.licznik = u1.licznik * u2.licznik;

uw.calkowita = 0;
//uw.wyciagnijCalosci();
return uw;
}
ulamek operator/(ulamek u1, ulamek u2){
ulamek uw;
//int tmianownik;
int tLicznik1 = 0,tLicznik2 = 0;
//uw.mianownik = u1.mianownik * u2.mianownik;
if(u1.calkowita && u2.calkowita){
//uw.licznik = ((u1.calkowita * u1.mianownik) + u1.licznik) * ((u2.calkowita * u2.mianownik) + u2.licznik);
    tLicznik1 = ((u1.calkowita * u1.mianownik) + u1.licznik);
    tLicznik2 = ((u2.calkowita * u2.mianownik) + u2.licznik);
    uw.licznik = tLicznik1 * u2.mianownik;
    uw.mianownik = u1.mianownik * tLicznik2;
}
else if(u1.calkowita && u2.calkowita == 0){
    tLicznik1 = ((u1.calkowita * u1.mianownik) + u1.licznik);
    uw.licznik = tLicznik1 * u2.mianownik;
    uw.mianownik = u1.mianownik * u2.licznik;
}
else if(u1.calkowita == 0 && u2.calkowita){
    tLicznik2 = ((u2.calkowita * u2.mianownik) + u2.licznik);
    uw.licznik = u1.licznik * u2.mianownik;
    uw.mianownik = u1.mianownik * tLicznik2;
}
else{
uw.licznik = u1.licznik * u2.mianownik;
uw.mianownik = u1.mianownik * u2.licznik;
}
uw.calkowita = 0;
//uw.wyciagnijCalosci();
return uw;
}
ostream & operator<<(ostream &o, ulamek u1){
  if(u1.licznik == 0)
             o << u1.calkowita << endl;
         else if(u1.licznik == u1.mianownik)
             o << u1.licznik << endl;
        else if(u1.calkowita == 0)
            o << u1.licznik << "/" << u1.mianownik << endl;
        else
    o << u1.calkowita << " " << u1.licznik << "/" << u1.mianownik << endl;
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
