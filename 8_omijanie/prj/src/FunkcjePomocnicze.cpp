#include "FunkcjePomocnicze.hh"

double StopnieNaRad(double &Kat_st)
{
    return Kat_st * PI / 180;
}

double ObliczSkale(double v1, double v2)
{
  double Skala;  
  if(v1 > v2) Skala = v1 / v2;
  else  Skala = v2 / v1;
  
  return Skala;
}

Wektor3D ObliczFunkcje(Wektor3D v1, Wektor3D v2)
{
    Wektor3D wspolczynniki;
    wspolczynniki[0] = (v2[1] - v1[1]) / (v2[0] - v1[0]);
    wspolczynniki[1] = v1[1] - wspolczynniki[0] * v1[0];
    return wspolczynniki; 
}

bool SprKtoreWieksze (double v1,double v2)
{
    if (fabs(v1-v2) < 1) return true;
    else if (v1 < v2) return false;
    else return false;
}

void Menu() {
  cout << endl << endl;
  cout << "p - zadaj parametry przelotu" << endl;
  cout << "d - dodaj element powierzchni" << endl;
  cout << "u - usun element powierzchni" << endl;
  cout << "m - wyswietl menu uzytkownika" << endl;
  cout << "k - koniec dzialania programu" << endl << endl;
}

void Menu2() {
  cout << endl << endl;
  cout << "1 - Gora z ostrym szczytem" << endl;
  cout << "2 - Gora z grania" << endl;
  cout << "3 - Plaskowyz" << endl << endl;
  cout << "Wprowadz numer elementu> ";
}