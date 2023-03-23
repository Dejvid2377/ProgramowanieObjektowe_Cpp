#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#include "bibloteki.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

class Prostopadloscian {
  private:
    Wektor3D Wierzcholki[8];
  public:
    Prostopadloscian ();
    Prostopadloscian(const std::initializer_list<Wektor3D> &rListaWierz); 
    Wektor3D operator[] (int Idx) const { return Wierzcholki[Idx]; }
    Wektor3D& operator[] (int Idx) { return Wierzcholki[Idx]; }
    Prostopadloscian operator= (const Prostopadloscian &Pr);
    Prostopadloscian Translacja(const Wektor3D &W1);
    void SprDlugosc(Prostopadloscian &Pr) const;
};

std::ostream& operator << (ostream &StrWyj,const Prostopadloscian &Pr);

#endif
