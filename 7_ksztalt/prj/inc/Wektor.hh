#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "bibloteki.hh"

template  <int T_Rozmiar>
class Wektor {
    double Wek[T_Rozmiar];
    inline static uint ile_stworzono=0;
    inline static uint ile_jest=0;
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Wektor                                         *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    Wektor();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] ListaWek - rekurencyjnie przekazana lista z wartosciami pol            *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    Wektor(const std::initializer_list<double> &ListaWek);
    ~Wektor();
/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[out] - liczba znajdujaca sie we wskazanym polu  			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/    
    double  operator [] (unsigned int Idx) const { assert(Idx < T_Rozmiar); return Wek[Idx]; }
    
/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[in] - liczba wprowadzona przez uzytkownika     			 	                    *
* \param[out] - pole z nowo uzupelniona wartoscia       			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/     
    double &operator [] (unsigned int Idx) { assert(Idx < T_Rozmiar); return Wek[Idx]; }

/************************************************************************************
* Przeciazenie operatora dodawania, umozliwia dodawanie do siebie dwoch obiektow    *
* klasy Wektor                                                                      *
* \param[in] W1 - drugi skladnik dodawania                                          *
* \param[out] - nowy Wektor rowny sumie dodawania       			 	                    *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
    Wektor  operator + (const Wektor &W1) const ;

/************************************************************************************
* Przeciazenie operatora odejmowania, umozliwia odejmowanie od siebie dwoch obiektow*
* klasy Wektor                                                                      *
* \param[in] W1 - drugi skladnik odejmowania                                        *
* \param[out] - nowy Wektor rowny roznicy odejmowania   			 	                    *
* \return - nowy obiekt klasy Wektor                     			 	                    *
************************************************************************************/
    Wektor  operator - (const Wektor &W1) const; 

/************************************************************************************
* Przeciazenie operatora mnozenia, umozliwia mnozenie dwoch obiektow klasy Wektor   *                                                                     *
* \param[in] W1 - drugi skladnik mnozenia                                           *
* \param[out] - nowy Wektor rowny ilorazowi mnozenia     			 	                    *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
    Wektor  operator * (const Wektor &W1) const ;

/************************************************************************************
* Przeciazenie operatora mnozenia, umozliwia mnozenie obiektu klasy wektor przez    *
* liczbe                                                                            *
* \param[in] liczba - liczba przez ktora chcemy pomnozyc wektor                     *
* \param[out] - nowy Wektor rowny ilorazowi mnozenia     			 	                    *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
    Wektor  operator * (double liczba) const ;

/************************************************************************************
* Przeciazenie operatora przypisania, umowzliwia przypisanie wartosci jednego       *
* obiektu klasy Wektor do drugiego                                                  *
* \param[in] W1 - wektor ktorego wartosc chcemy powielic                            *
* \param[out] - Wektor z przypisanymi wartosciami drugiego obiektu                  *
* \return - nowy obiekt klasy Wektor                     			 	                    *
************************************************************************************/
    Wektor  operator = ( const Wektor &W1); 

/************************************************************************************
* Przeciazenie operatora porownania, sprawdza czy dwa obiekty sa sobie rowne        *
* \param[in] W1 - wektor ktorego wartosc chcemy porownac                            *
* \return - wartosc logiczna                             			 	                    *
************************************************************************************/   
    bool operator == (const Wektor &W1) const; 

/************************************************************************************
* Metoda sprawdzajaca dlugosc wektora (jego modul) dla danego obiektu               *
* \return - wartosc modulu wektora                       			 	                    *
************************************************************************************/    
    double DlugoscWek() const;
    static uint Zwroc_stworzone() { return ile_stworzono;} 
    static uint Zwroc_obecne() { return ile_jest;} 
};


/*********************************************************************************
    Konstruktory
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor()
{
  for (double &Wek_i : Wek)  Wek_i = 0;
  ile_jest++;
  ile_stworzono++;  
}

template <int T_Rozmiar>
Wektor<T_Rozmiar>::Wektor(const std::initializer_list<double> &ListaWek):
                                  Wektor()
{
  assert(ListaWek.size() <= T_Rozmiar);
  int Ind = -1;
  for (double Wek_i : ListaWek) Wek[++Ind] = Wek_i;
  ile_jest++;
  ile_stworzono++;
}

template <int T_Rozmiar>
Wektor<T_Rozmiar>::~Wektor()
{
  ile_jest--;
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
    Mnozenie przez wektor
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator * (const Wektor &W1) const
{
  Wektor<T_Rozmiar> Temp;
  for (int i=0; i<T_Rozmiar; i++)
    Temp[i] = Wek[i] * W1[i];
   return Temp;
}

/*********************************************************************************
    Mnozenie przez liczbe
*********************************************************************************/
template <int T_Rozmiar>
Wektor<T_Rozmiar> Wektor<T_Rozmiar>::operator * (double liczba) const
{
  Wektor<T_Rozmiar> Temp;
  for (int i=0; i<T_Rozmiar; i++)
    Temp[i] = Wek[i] * liczba;
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
