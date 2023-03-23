#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <bibloteki.hh>
#include <Wektor.hh>

template  <int T_Rozmiar>
class Macierz {
    double Mac[T_Rozmiar * T_Rozmiar];
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Macierz                                        *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    Macierz();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] ListaMac - rekurencyjnie przekazana lista z wartosciami pol            *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    Macierz(const std::initializer_list<double> &ListaMac);

/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[out] - liczba znajdujaca sie we wskazanym polu  			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/
    double  operator [] (unsigned int Idx) const 
                              { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }

/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[in] - liczba wprowadzona przez uzytkownika     			 	                    *
* \param[out] - pole z nowo uzupelniona wartoscia       			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/    
    double &operator [] (unsigned int Idx) 
                              { assert(Idx < T_Rozmiar*T_Rozmiar); return Mac[Idx]; }
    
/************************************************************************************
* Operator funkcyjny, zapewnia dostep do wybranych pol obiektu poza klasa           *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola (numer wiersza)   *
* \param[in] Idy - dodatnia liczba calkowita do indeksowania pola (numer kolumny)   *
* \param[out] - liczba znajdujaca sie we wskazanym polu  			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/
    double operator () (unsigned int Idx, unsigned int Idy) const;
    
/************************************************************************************
* Operator funkcyjny, zapewnia dostep do wybranych pol obiektu poza klasa           *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola (numer wiersza)   *
* \param[in] Idy - dodatnia liczba calkowita do indeksowania pola (numer kolumny)   *
* \param[in]     - liczba wprowadzona przez uzytkownika                             *
* \param[out] - pole z nowo uzupelniona wartoscia       			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/   
    double &operator () (unsigned int Idx, unsigned int Idy);
    
/************************************************************************************
* Przeciazenie operatora mnozenia, umozliwia mnozenie macierzy przez obiekt         *
* klasy Wektor                                                                      *
* \param[in] W - obiekto klasy Wektor przez ktory mnozymy macierz                   *
* \param[out] - Wektor rowny iloczynowi mnozenia         			 	                    *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/    
    Wektor<T_Rozmiar> operator*(const Wektor<T_Rozmiar> &W) const;
    
/************************************************************************************
* Przeciazenie operatora mnozenia, umozliwia mnozenie macierzy przez obiekt         *
*  tej samej klasy                                                                  *
* \param[in] M - obiekto klasy Macierz przez ktory mnozymy macierz                  *
* \param[out] - macierz rowna iloczynowi mnozenia        			 	                    *
* \return - obiekt klasy Macierz                     			 	                        *
************************************************************************************/ 
    Macierz operator*(const Macierz &M);
    
/************************************************************************************
* Przeciazenie operatora mnozenia, umozliwia mnozenie macierzy przez liczbe         *
* \param[in] M - obiekto klasy Macierz przez ktory mnozymy liczbe                   *
* \param[out] - macierz rowna iloczynowi mnozenia        			 	                    *
* \return - obiekt klasy Macierz                     			 	                        *
************************************************************************************/   
    Macierz operator*(double liczba);
    
/************************************************************************************
* Przeciazenie operatora przypisania, umowzliwia przypisanie wartosci jednego       *
* obiektu klasy Wektor do drugiego                                                  *
* \param[in] W1 - wektor ktorego wartosc chcemy powielic                            *
* \param[out] - Wektor z przypisanymi wartosciami drugiego obiektu                  *
* \return - nowy obiekt klasy Wektor                     			 	                    *
************************************************************************************/   
    Macierz operator=(const Macierz &M);
    
/************************************************************************************
* Przeciazenie operatora porownania, sprawdza czy dwa obiekty sa sobie rowne        *
* \param[in] M - macierz ktorej wartosc chcemy porownac                             *
* \return - wartosc logiczna                             			 	                    *
************************************************************************************/  
    bool operator==(const Macierz &M);  
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


/*********************************************************************************
    Operatory funkcyjne
*********************************************************************************/
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

/*********************************************************************************
    Mnozenie przez macierz
*********************************************************************************/
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


/*********************************************************************************
    Porownanie
*********************************************************************************/
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
