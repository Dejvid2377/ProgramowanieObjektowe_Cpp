#ifndef SCENA_HH
#define SCENA_HH
#include "bibloteki.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"

class Scena {
  private:
    Prostopadloscian Figura;
    Macierz3x3 MacObrotu;
  public:
    Scena();
    Scena(Prostopadloscian Figura, Macierz3x3 MacObrotu);
    Scena operator = (const Scena &Sc);
    Scena WczytajSekwencje ();
    Prostopadloscian ObrocFigure (const Scena &Sc,int liczba);
    Macierz3x3 ZwrocMacierz (const Scena &Sc);
    Prostopadloscian ZwrocFigure (const Scena &Sc);
};

#endif