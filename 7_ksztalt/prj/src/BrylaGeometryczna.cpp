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

