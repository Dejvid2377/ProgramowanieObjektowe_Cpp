#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH
#include "bibloteki.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

class Prostopadloscian {
  private:
    Wektor3D Wierzcholki[8];
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Prostopadloscian                               *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    Prostopadloscian ();
  
/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] LisaWierz - rekurencyjnie przekazana lista z wartosciami pol           *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    Prostopadloscian(const std::initializer_list<Wektor3D> &rListaWierz); 
  
/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - Wektor znajdujacy sie we wskazanym polu  			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/
    Wektor3D operator[] (int Idx) const { return Wierzcholki[Idx]; }

/************************************************************************************
* Operator indeksowania, zapewnia dostep do wybranych pol obiektu poza klasa        *
* \param[in] Idx - dodatnia liczba calkowita do indeksowania pola                   *
* \param[in] - Wektor wprowadzony przez uzytkownika     			 	                    *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - pole z nowo uzupelniona wartoscia       			 	                    *
* \return - wskazane pole                               			 	                    *
************************************************************************************/   
    Wektor3D &operator[] (int Idx) { return Wierzcholki[Idx]; }
  
/************************************************************************************
* Przeciazenie operatora przypisania, umowzliwia przypisanie wartosci jednego       *
* obiektu klasy Prostopadloscian do drugiego                                        *
* \param[in] Pr - Prostopadloscian ktorego wspolrzedne wierzcholkow chcemy powielic *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - Prostopadloscian z przypisanymi wartosciami drugiego obiektu        *
* \return - nowy obiekt klasy Prostopadloscian           			 	                    *
************************************************************************************/  
    Prostopadloscian operator= (const Prostopadloscian &Pr);
  
/*************************************************************************************
* Metoda klasy pozwalajaca dokonac przesuniecia obiektu o zadany wektor w przestrzeni*         *
* \param[in] W1 - wektor o ktorego wartosc chcemy dokonac translacje                 *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - Prostopadloscian z nowymi wartosciami wspolrzednych                  *
* \return - nowy obiekt klasy Protopadloscian                             			 	   *
*************************************************************************************/ 
    Prostopadloscian Translacja(const Wektor3D &W1);
  
/*************************************************************************************
* Metoda klasy pozwalajaca sprawdzic dlugosc przeciwleglych bokow                    *
* \param[in]  - obiekt klasy Prostopadloscian                                        *
* \param[out] - komunikat o dlugosci przeciwleglych bokow                            *
*************************************************************************************/
    void SprDlugosc() const;
};

bool Porownaj(double v1, double v2, double v3, double v4);
std::ostream& operator << (ostream &StrWyj,const Prostopadloscian &Pr);

#endif
