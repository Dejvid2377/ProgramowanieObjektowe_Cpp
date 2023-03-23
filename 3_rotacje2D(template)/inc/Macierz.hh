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
    Wektor<T_Rozmiar> operator*(const Wektor<T_Rozmiar> &W) const;
    Macierz operator*(double liczba);
    Macierz operator=(const Macierz &M);
};

/*********************************************************************************
    Konstruktory
*********************************************************************************/
template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz()
{
  for (double &Mac_i : Mac)  Mac_i = 0; 
}

template <int T_Rozmiar>
Macierz<T_Rozmiar>::Macierz(const std::initializer_list<double> &rListaMac):
                 Macierz() // Wywolujac ten konstruktor rowniez nie musimy podawac parametrow szablonu.
		          // Domyslnie jest to rozumiane jako: Macierz<T_Rozmiar>()
{
  assert(rListaMac.size() <= T_Rozmiar*T_Rozmiar);
  int Ind = -1;
  for (double Mac_val : rListaMac) Mac[++Ind] = Mac_val;
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

/*********************************************************************************
    Mnozenie przez wektor
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Macierz<T_Rozmiar>::operator * (const Wektor<T_Rozmiar> &W1) const
{
  Wektor2D NoweWsp;
    NoweWsp[0] += Mac[0] * W1[0];
    NoweWsp[0] += Mac[1] * W1[1];
    NoweWsp[1] += Mac[2] * W1[0];
    NoweWsp[1] += Mac[3] * W1[1];
    /*for (int i=0; i<T_Rozmiar*T_Rozmiar; i++) 
      NoweWsp[i%j] += Mac[i] * W1[i%j];*/
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

/*********************************************************************************
    Wypelnianie macierzy wartoscia kata
*********************************************************************************/
template <int T_Rozmiar>
Macierz<T_Rozmiar> MacierzRotacji2x2 (Macierz<T_Rozmiar> &M)
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
