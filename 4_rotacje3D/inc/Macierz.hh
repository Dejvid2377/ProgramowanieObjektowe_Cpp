#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <bibloteki.hh>
#include <Wektor.hh>

template  <int T_Rozmiar>
class Macierz {
    double Mac[T_Rozmiar * T_Rozmiar];
  public:
    Macierz();
    Macierz(const std::initializer_list<double> &ListaMac);
    double  operator [] (unsigned int Idx) const { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }
    double &operator [] (unsigned int Idx) { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }
    double operator () (unsigned int Idx, unsigned int Idy) const;
    double &operator () (unsigned int Idx, unsigned int Idy);
    Wektor<T_Rozmiar> operator*(const Wektor<T_Rozmiar> &W) const;
    Macierz operator*(const Macierz &M);
    Macierz operator*(double liczba);
    Macierz operator=(const Macierz &M);
    bool operator==(const Macierz &M);
    bool operator!=(const Macierz &M);

};

/*********************************************************************************
    Konstruktory
*********************************************************************************/
template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz()
{
  for (double &Mac_i : Mac)  Mac_i = 1; 
}

template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz(const std::initializer_list<double> &rListaMac):
                 Macierz() // Wywolujac ten konstruktor rowniez nie mu simy podawac parametrow szablonu.
		          // Domyslnie jest to rozumiane jako: Macierz<T_Rozmiar>()
{
  assert(rListaMac.size() <= T_Rozmiar*T_Rozmiar);
  int Ind = -1;
  for (double Mac_val : rListaMac) Mac[++Ind] = Mac_val;
}


template <int T_Rozmiar>
double Macierz<T_Rozmiar>::operator () (unsigned int Idx, unsigned int Idy) const
{
   if ( Idx<0 || Idy<0 || Idx>T_Rozmiar || Idy>T_Rozmiar) {
     cerr<<"Bledny zakres macierzy";
     exit(0);
   }
   else 
    return Mac[(Idx-1)*T_Rozmiar+Idy-1];
}

template <int T_Rozmiar>
double & Macierz<T_Rozmiar>::operator () (unsigned int Idx, unsigned int Idy)
{
   if ( Idx<0 || Idy<0 || Idx>T_Rozmiar || Idy>T_Rozmiar) {
     cerr<<"Bledny zakres macierzy";
     exit(0);
   }
   else 
    return Mac[(Idx-1)*T_Rozmiar+Idy-1];
}

/*********************************************************************************
    Mnozenie przez wektor
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Macierz<T_Rozmiar>::operator * (const Wektor<T_Rozmiar> &W1) const
{
  Wektor<T_Rozmiar> NoweWsp;
  Macierz<T_Rozmiar> Macierz = *this;

    for (int i=0; i<T_Rozmiar; i++) {
      for (int j=0; j<T_Rozmiar; j++) { 
        NoweWsp[i] += Macierz(i+1,j+1) * W1[j];
      }
    }
  return NoweWsp;
}

/*********************************************************************************
    Mnozenie przez liczbe
*********************************************************************************/
template <int T_Rozmiar>
Macierz<T_Rozmiar> Macierz<T_Rozmiar>::operator * (double liczba)
{
  for (int i=0; i<T_Rozmiar*T_Rozmiar; i++)
      Mac[i] = Mac[i] * liczba;
  return *this;
}

template <int T_Rozmiar>
Macierz<T_Rozmiar> Macierz<T_Rozmiar>::operator * (const Macierz &M)
{
  Macierz<T_Rozmiar> M_Temp = *this;
  for (int i=0; i<T_Rozmiar; i++) {
    for (int j=0; j<T_Rozmiar; j++) {
      Mac[i*T_Rozmiar+j] = 0;
      for (int k=0; k<T_Rozmiar; k++) { 
        Mac[i*T_Rozmiar+j] += M_Temp[i*T_Rozmiar+k] * M[k*T_Rozmiar+j];  
      }
    }
  }
  return *this;
}

/*********************************************************************************
    Przypisanie
*********************************************************************************/
template <int T_Rozmiar>
Macierz<T_Rozmiar> Macierz<T_Rozmiar>::operator = (const Macierz &M1)
{
  for (int i=0; i<T_Rozmiar*T_Rozmiar; i++)
    Mac[i] = M1.Mac[i];
  return *this;
}

template <int T_Rozmiar>
bool Macierz<T_Rozmiar>::operator == (const Macierz &M1)
{
  for (int i=0; i<T_Rozmiar*T_Rozmiar;) {
    if (fabs(Mac[i] - M1.Mac[i]) < EPSILON)
      i++;
    else 
      return false;
  }
  return true;
}

/*********************************************************************************
    Przeciazenie operatorow wejscia/wyjscia
*********************************************************************************/
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

#endif
