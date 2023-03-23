#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <bibloteki.hh>
#include <Wektor2D.hh>

class Macierz {
    double Mac[ROZMIAR][ROZMIAR];
  public:
    Macierz(): Mac {{0,0},{0,0}} {}
    Macierz(double a, double b, double c, double d);
    Wektor2D operator*(const Wektor2D &W) const;
    Macierz operator*(double liczba);
    Macierz operator=(const Macierz &M);
    friend ostream& operator << (ostream &, const Macierz &);
};

  Macierz MacierzRotacji (Macierz &M);
#endif
