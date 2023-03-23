#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
using namespace std;
#define EPSILON __DBL_EPSILON__
#define PI 3.14


template  <int T_Rozmiar>
class Macierz {
    double Mac[T_Rozmiar * T_Rozmiar];
  public:
    Macierz();
    Macierz(const std::initializer_list<double> &ListaMac);
    double  operator [] (unsigned int Idx) const { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }
    double &operator [] (unsigned int Idx) { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }
   // Wektor2x2 operator*(const Wektor2x2 &W) const;
    Macierz operator*(double liczba);
    Macierz operator=(const Macierz &M);
};

typedef Macierz<2>  Macierz2x2;

template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz()
{
  for (double &Mac_i : Mac)  Mac_i = 0; 
}

template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz(const std::initializer_list<double> &rListaMac):
                 Macierz() // Wywolujac ten konstruktor rowniez nie musimy podawac parametrow szablonu.
		          // Domyslnie jest to rozumiane jako: Wektor<Templ_Typ,T_Rozmiar>()
{
  assert(rListaMac.size() <= T_Rozmiar*T_Rozmiar);
  int Ind = -1;
  for (double Mac_val : rListaMac) Mac[++Ind] = Mac_val;
}

template <int T_Rozmiar>
Macierz<T_Rozmiar> Macierz<T_Rozmiar>::operator = (const Macierz &M1)
{
  for (int i=0; i<T_Rozmiar; i++)
    Mac[i] = M1.Mac[i];
  return *this;
}

template <int T_Rozmiar>
Macierz<T_Rozmiar> Macierz<T_Rozmiar>::operator * (double liczba)
{
    for (int i=0; i<T_Rozmiar*T_Rozmiar; i++)
        Mac[i] = Mac[i] * liczba;
    return *this;
}


template <int T_Rozmiar>
ostream &  operator << (ostream &StrmWy, const Macierz<T_Rozmiar> & rMac)
{
  for (unsigned int Idx = 0; Idx < T_Rozmiar*T_Rozmiar; ++Idx)
  {
    if (Idx%T_Rozmiar == 0 && Idx!=0) StrmWy << endl;
    StrmWy << rMac[Idx] << " ";
  }
  StrmWy << endl;
  return StrmWy;
}

Macierz2x2 MacierzRotacji2x2 (Macierz2x2 &M)
{
  double kat;

  if(!(cin >> kat)) 
  {
    cout << "Bledna wartosc kata" << endl;
    exit(0);
  }
  else 
  {
    kat = kat * PI / 180;
    M = {cos(kat),-sin(kat),sin(kat),cos(kat)};
  }

  return M;
}

int main ()
{
    Macierz2x2 M1;
    cout << M1 << endl;
    MacierzRotacji2x2(M1);
    cout << M1 << endl;
    return 0;
}