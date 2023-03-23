#include <iostream>
#include <cassert>
#include <cmath>
#include <initializer_list>
using namespace std;
#define EPSILON __DBL_EPSILON__


template <unsigned int T_Rozmiar>
class Wektor
{
    double Wek[T_Rozmiar];
  public:
    Wektor();
    Wektor(const std::initializer_list<double> &rListaWsp);
    double  operator [] (unsigned int idx) const { assert(idx < T_Rozmiar); return Wek[idx]; }
    double &operator [] (unsigned int idx) { assert(idx < T_Rozmiar); return Wek[idx]; }
    Wektor operator+(const Wektor &W);
    bool operator == (const Wektor &W) const;
        double DlugoscWek() const;


};

template <unsigned int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor()
{
  for (double &idx : Wek) idx = 0;
}

template <unsigned int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor(const std::initializer_list<double> &rListaWsp):
                 Wektor() // Wywolujac ten konstruktor rowniez nie musimy podawac parametrow szablonu.
		          // Domyslnie jest to rozumiane jako: Wektor<Templ_Typ,T_Rozmiar>()
{
  assert(rListaWsp.size() <= T_Rozmiar);
  int Ind = -1;
  for (double Wek_val : rListaWsp) Wek[++Ind] = Wek_val;
}

template <unsigned int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator + (const Wektor &W)
{
  for (int i=0; i < T_Rozmiar; i++)
    Wek[i] = Wek[i] + W.Wek[i];
  return *this;
}

template <unsigned int T_Rozmiar>
bool Wektor<T_Rozmiar>::operator == (const Wektor &W) const
{
  for (int i=0; i<T_Rozmiar;)
    if (fabs(Wek[i]-W.Wek[i]) < EPSILON)
      i++;
    else
     return false;
  return true;
}

template <unsigned int T_Rozmiar>
istream &  operator >> (istream &StrWej, Wektor<T_Rozmiar> & W)
{
  for (int i=0; i<T_Rozmiar;i++)
    if (!(StrWej>>W[i])) {
        cerr << "Blad zapisu wektora" << endl;
        StrWej.setstate(ios::failbit);
        return StrWej;
    }
  return StrWej;
}

template <unsigned int T_Rozmiar>
double Wektor<T_Rozmiar>::DlugoscWek() const
{
  double suma {0};
  for (int i=0; i<T_Rozmiar;i++)
    suma += Wek[i] * Wek[i];
  return sqrt(suma);
}

template <unsigned int T_Rozmiar>
ostream &  operator << (ostream &StrmWy, const Wektor<T_Rozmiar> &  rWek)
{
  for (unsigned int idx = 0; idx < T_Rozmiar; ++idx) StrmWy << rWek[idx] << " ";
  return StrmWy;
}

int main ()
{
    Wektor <4> W1;
    cin >> W1;
    double dlugosc = W1.DlugoscWek();
    cout << dlugosc << endl;
    return 0;
}