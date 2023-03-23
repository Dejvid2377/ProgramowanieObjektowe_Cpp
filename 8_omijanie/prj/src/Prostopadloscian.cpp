#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian()
{
    NazwaPliku_BrylaWzorcowa = PLIK_WZORCOWEGO_SZESCIANU;
    NazwaPliku_BrylaFinalna = "";
    Skala = SKALA_KORPUSU;
    Polozenie = {0,0,0};
    KatOrientacji_stopnie = 0;
}

Prostopadloscian::Prostopadloscian(string Wzorzec,
                                   string Finalna,
                                   Wektor3D Skala,
                                   Wektor3D Wsp,
                                   double kat )
:BrylaGeometryczna(Wzorzec,Finalna,Skala), Polozenie(Wsp), KatOrientacji_stopnie(kat)
{
    
}


Wektor3D Prostopadloscian::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
    return Polozenie + Wsp;
}