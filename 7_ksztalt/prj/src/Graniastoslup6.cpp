#include "Graniastoslup6.hh"

Graniastoslup6::Graniastoslup6()
{ 
    NazwaPliku_BrylaWzorcowa = PLIK_WZORCOWEGO_GRANIASTOSLUPA6;
    Skala = SKALA_ROTORA;
    Polozenie={0,0,0};
    KatOrientacji_stopnie=0;
}

Graniastoslup6::Graniastoslup6(string Wzorzec,
                               string Finalna,
                               Wektor3D Skala,
                               Wektor3D Wsp,
                               double kat)
:BrylaGeometryczna(Wzorzec,Finalna,Skala), Polozenie(Wsp), KatOrientacji_stopnie(kat)
{
    
}

Wektor3D Graniastoslup6::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
    return Polozenie + Wsp;
}
