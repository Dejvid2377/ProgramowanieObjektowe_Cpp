#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH
#include "bibloteki.hh"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

class BrylaGeometryczna {
  protected:
    string NazwaPliku_BrylaWzorcowa;
    string NazwaPliku_BrylaFinalna;
    Wektor3D Skala;
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy BrylaGeometryczna                              *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    BrylaGeometryczna();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] Wzorzec - napis bedacy nazwa pliku wzorcowego                          *
* \param[in] Finalna - napis bedacy nazwa pliku wynikowego                          *
* \param[in] Skala   - skala obiektu wzgledem wzorca                                *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    BrylaGeometryczna(string Wzorzec, string Finalna, Wektor3D Skala);

/************************************************************************************
* Metoda pozwalajaca zwiekszyc rozmiar wynikowego obiektu                           *                                                                     *
* \param[in] Wierz - wektor zawierajacy parametry skalowania                        *
* \param[out] - nowy Wektor zawierajacy wspolrzedne przeskalowanego punktu          *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
    Wektor3D Skaluj (const Wektor3D &Wierz) const;

/************************************************************************************
* Metoda pozwalajaca uzyskac nazwe pliku wzorcowego                                 *                                                                     *
* \param[out] - nazwa pliku wzorcowego                                              * 
* \return - napis                                    			 	                        *
************************************************************************************/
    const string& WezNazwePliku_BrylaWzorcowa() const;

/************************************************************************************
* Metoda pozwalajaca uzyskac nazwe pliku wzorcowego                                 *                                                                     *
* \param[out] - nazwa pliku wynikowego                                              * 
* \return - napis                                    			 	                        *
************************************************************************************/
    const string& WezNazwePliku_BrylaFinalna() const;
};

  double StopnieNaRad(double &Kat_st);
  double ObliczSkale(double v1, double v2);
  Wektor3D ObliczFunkcje(Wektor3D v1, Wektor3D v2);
  bool SprKtoreWieksze (double v1,double v2);
  void Menu (); 
#endif