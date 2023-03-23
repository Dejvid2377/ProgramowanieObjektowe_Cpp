#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "bibloteki.hh"

template  <int T_Rozmiar>
class Wektor {
    double Wek[T_Rozmiar];
  public:
    Wektor();
    Wektor(const std::initializer_list<double> &ListaWek);
    double  operator [] (unsigned int Idx) const { assert(Idx < T_Rozmiar); return Wek[Idx]; }
    double &operator [] (unsigned int Idx) { assert(Idx < T_Rozmiar); return Wek[Idx]; }
    Wektor  operator +  (const Wektor &W1) const ;    
    Wektor  operator -  (const Wektor &W1) const; 
    Wektor  operator = ( const Wektor &W1); 
    bool operator == (const Wektor &W1) const; 
    bool operator != (const Wektor &W1) const;
    double DlugoscWek() const;
};
/*********************************************************************************
    Konstruktory
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor()
{
  for (double &Wek_i : Wek)  Wek_i = 0;  
}

template <int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor(const std::initializer_list<double> &ListaWek):
                                  Wektor()
{
  assert(ListaWek.size() <= T_Rozmiar);
  int Ind = -1;
  for (double Wek_i : ListaWek) Wek[++Ind] = Wek_i;
}
/*********************************************************************************
    Dodawanie
*********************************************************************************/

template <int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator + (const Wektor &W1) const
{
  Wektor<T_Rozmiar> Temp;
  for (int i=0; i<T_Rozmiar; i++)
    Temp[i] = Wek[i] + W1[i];
  return Temp;
}
/*********************************************************************************
    Odejmowanie
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator - (const Wektor &W1) const
{
  Wektor<T_Rozmiar> Temp;
  for (int i=0; i<T_Rozmiar; i++)
    Temp[i] = Wek[i] - W1[i];
   return Temp;
}

/*********************************************************************************
    Przypisanie
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator = (const Wektor &W1)
{
  for (int i=0; i<T_Rozmiar; i++)
    Wek[i] = W1[i];
  return *this;
}

/*********************************************************************************
    Porownanie
*********************************************************************************/
template <int T_Rozmiar>
bool Wektor<T_Rozmiar>::operator == (const Wektor &W) const
{
  for (int i=0; i<T_Rozmiar;)
    if (fabs(Wek[i]-W.Wek[i]) < EPSILON)
      i++;
    else
     return false;
  return true;
}
/*********************************************************************************
    Negacja
*********************************************************************************/
template <int T_Rozmiar>
bool Wektor<T_Rozmiar>::operator != (const Wektor &W) const
{
  for (int i=0; i<T_Rozmiar;)
    if (fabs(Wek[i]-W.Wek[i]) > EPSILON)
      i++;
    else
     return false;
  return true;
}

/*********************************************************************************
    Modul
*********************************************************************************/
template <int T_Rozmiar>
double Wektor<T_Rozmiar>::DlugoscWek() const
{
  double suma {0};
  for (int i=0; i<T_Rozmiar;i++)
  {
    suma += Wek[i] * Wek[i];
  }
  return sqrt(suma);
}

/*********************************************************************************
    Przeciazenia wejscia/wyjscia
*********************************************************************************/
template <int T_Rozmiar>
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

template <int T_Rozmiar>
ostream &  operator << (ostream &StrmWy, const Wektor<T_Rozmiar> &  rWek)
{
  for (unsigned int Idx = 0; Idx < T_Rozmiar; ++Idx) StrmWy << rWek[Idx] << " ";
  return StrmWy;
}

#endif
