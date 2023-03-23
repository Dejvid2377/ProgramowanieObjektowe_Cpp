#include "BrylaGeometryczna.hh"

BrylaGeometryczna::BrylaGeometryczna()
{
    NazwaPliku_BrylaWzorcowa = "";
    NazwaPliku_BrylaFinalna = "";
    Skala = {0,0,0}; 
}

BrylaGeometryczna::BrylaGeometryczna(string Wzorzec, string Finalna, Wektor3D Skala)
    :NazwaPliku_BrylaWzorcowa(Wzorzec), NazwaPliku_BrylaFinalna(Finalna), Skala(Skala)
{
    
}

Wektor3D BrylaGeometryczna::Skaluj(const Wektor3D &Wierz) const
{
    Macierz3x3 M1;
    M1 = Przeskaluj(Skala);
    return M1 * Wierz;
}

const string& BrylaGeometryczna::WezNazwePliku_BrylaWzorcowa() const
{
    return NazwaPliku_BrylaWzorcowa;
}

const string& BrylaGeometryczna::WezNazwePliku_BrylaFinalna() const
{
    return NazwaPliku_BrylaFinalna;
}

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



void Menu()
{   
    Wektor3D W1;
    cout << "p - zadaj parametry przelotu" << endl;
    cout << "m - wyswietl menu" << endl << endl;
    cout << "k - koniec dzialania programu" << endl << endl;
    cout << "Aktualna ilosc obiektow Wektor3D: " << W1.Zwroc_stworzone() << endl;
  cout << "  Laczna ilosc obiektow Wektor3D: " << W1.Zwroc_obecne() << endl << endl;

}


