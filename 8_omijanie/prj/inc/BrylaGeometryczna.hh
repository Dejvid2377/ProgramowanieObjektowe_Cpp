#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH
#include "bibloteki.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "FunkcjePomocnicze.hh"

class BrylaGeometryczna {
  protected:
    string NazwaPliku_BrylaWzorcowa;
    string NazwaPliku_BrylaFinalna;
    Wektor3D Skala;
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy BrylaGeometryczna                              *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	            *
************************************************************************************/
    BrylaGeometryczna();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] Wzorzec - napis bedacy nazwa pliku wzorcowego                          *
* \param[in] Finalna - napis bedacy nazwa pliku wynikowego                          *
* \param[in] Skala   - skala obiektu wzgledem wzorca                                *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	            *
************************************************************************************/
    BrylaGeometryczna(string Wzorzec, string Finalna, Wektor3D Skala);

/************************************************************************************
* Metoda pozwalajaca zwiekszyc rozmiar wynikowego obiektu                           *
* \param[in] Wierz - wektor zawierajacy parametry skalowania                        *
* \param[out] - nowy Wektor zawierajacy wspolrzedne przeskalowanego punktu          *
* \return - obiekt klasy Wektor                     			 	                *
************************************************************************************/
    Wektor3D Skaluj (const Wektor3D &Wierz) const;

/************************************************************************************
* Metoda pozwalajaca uzyskac nazwe pliku wzorcowego                                 *
* \param[out] - nazwa pliku wzorcowego                                              * 
* \return - napis                                    			 	                *
************************************************************************************/
    const string& WezNazwePliku_BrylaWzorcowa() const;

/************************************************************************************
* Metoda pozwalajaca uzyskac nazwe pliku wzorcowego                                 *
* \param[out] - nazwa pliku wynikowego                                              * 
* \return - napis                                    			 	                *
************************************************************************************/
    const string& WezNazwePliku_BrylaFinalna() const;

/************************************************************************************
* Metoda pozwalajaca zmienic wartosc pola Skala w sekcji private                    *
* \param[in] Wsp - Wektor3D z nowa wartoscia Skali                                  * 
* \param[out] Skala - zmienna z pola protected z nowymi wartosciami                 * 
************************************************************************************/
    void ZmienSkale(const Wektor3D &Wsp) {Skala = Wsp;}

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac informacje o typie obiektu                   *
* \param[out] - strumien wyjsciowy cout                                             * 
* \return - napis                                    			 	                *
************************************************************************************/
    virtual const char *Nazwa() const { return "Bryla geometryczna"; }

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac unikalne ID obiektu                          *
* \param[out] - unikalne ID obiektu                                                 * 
* \return - liczba typu uint                                                        *
************************************************************************************/
    virtual const uint ZwrocID() const {return 1;}

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac infoformacje na temat polozenia obiektu      *
* \param[out] - strumien wyjsciowy cout                                             * 
************************************************************************************/
    virtual const void ZwrocWsp() const { cout <<"Klasa bazowa nie posiada takiego pola\n"; }

/************************************************************************************
* Metoda wirtualna pozwalajaca wektor polozenia obiektu                             *
* \param[out] - polozenie obiektu w bazie R3                                        * 
* \return - Wektor3D                                  			 	                *
************************************************************************************/
    virtual const Wektor3D ZwrocPolozenie() const { return {0,0,0}; }

/************************************************************************************
* Metoda wirtualna pozwalajaca wyznaczyc poziomy obrys obiektu                      *
* \param[out] - informacje o obrysie przeniesione do obiektu klasy vector           * 
* \return - zmienna typu bool informujaca o powodzeniu operacji                     *
************************************************************************************/
    virtual bool UstalObrys() {return false;}

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac dane na temat obrysu obiektu                 *
* \param[out] - vector z danymi o obrysie obiektu                                   * 
* \return - obiekt typu vector<double>             			 	                *
************************************************************************************/
    virtual vector<double> ZwrocWspObrysu() { vector<double> Wek; return Wek;}
    
/************************************************************************************
* Metoda wirtualna pozwalajaca sprawdzic czy dwa obiekty nie koliduja ze soba       *
* \param[out] - informacja o biezacym polozeniu drona                               * 
* \return - zmienna typu bool informujaca o powodzeniu operacji                     *
************************************************************************************/    
    virtual bool CzyKolizja(const vector<double> &ObrysBryl) {return false;}
};

#endif