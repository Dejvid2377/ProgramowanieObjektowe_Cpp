#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#include <bibloteki.hh>
#include <Wektor2D.hh>
#include <Macierz.hh>

class Prostokat {
    Wektor2D Wierzcholki[4];
  public:
    Prostokat(): Wierzcholki {{0,0},{0,0},{0,0},{0,0}} {}
    Prostokat(Wektor2D A, Wektor2D B, Wektor2D C, Wektor2D D);
    Wektor2D operator[] (int i) const { return Wierzcholki[i]; }
    Wektor2D& operator[] (int i) { return Wierzcholki[i]; }
    Prostokat Translacja(const Wektor2D &);
    Prostokat Obrot (const Macierz &);
    void SprDlugosc (Prostokat &Pr) const;
    friend ostream & operator << (ostream&, const Prostokat&);
};
  Prostokat KilkaObrotow (Prostokat &Pr, Macierz &M);
#endif
