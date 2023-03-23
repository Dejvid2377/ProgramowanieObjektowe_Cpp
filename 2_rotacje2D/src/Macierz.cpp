#include "Macierz.hh"

Macierz::Macierz(double a, double b, double c, double d)
{
  Mac[0][0] = a;
  Mac[0][1] = b;
  Mac[1][0] = c;
  Mac[1][1] = d;
}

Wektor2D Macierz::operator* (const Wektor2D &W) const
{
    Wektor2D NoweWsp;
    for (int i=0; i<ROZMIAR; i++) {
      for (int j=0; j<ROZMIAR; j++) {
          NoweWsp[i] += Mac[i][j] * W[j];
      }
    }
    return NoweWsp;
}

Macierz Macierz::operator*(double liczba)
{
    for (int i=0; i<ROZMIAR; i++) {
      for (int j=0; j<ROZMIAR; j++) {
        Mac[i][j] = Mac[i][j] * liczba;
      }
    }
    return *this;
}

Macierz Macierz::operator=(const Macierz &M)
{
  for (int i=0; i<ROZMIAR; i++) {
    for (int j=0; j<ROZMIAR; j++) {
       Mac[i][j] = M.Mac[i][j]; 
    }
  }
  return *this;
}

ostream& operator << (ostream &StrWyj, const Macierz &M)
{ 
  return StrWyj << "| " << M.Mac[0][0] << " " << M.Mac[0][1] << " |" << endl
    << "| " << M.Mac[1][0] << " " << M.Mac[1][1] << " |" ;
}

Macierz MacierzRotacji (Macierz &M)
{
  double kat;

  if(!(cin >> kat)) {
    cout << "Bledna wartosc kata" << endl;
    exit(0);
  }
  else {
  kat = kat * PI / 180;
  M = {cos(kat),-sin(kat),sin(kat),cos(kat)};
  }

  return M;
}