#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include "bibloteki.hh"
#include "BrylaGeometryczna.hh"


class Graniastoslup6 : public BrylaGeometryczna {
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
    public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Graniastoslup6                                 *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
  Graniastoslup6();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] Wzorzec - napis bedacy nazwa pliku wzorcowego                          *
* \param[in] Finalna - napis bedacy nazwa pliku wynikowego                          *
* \param[in] Skala   - skala obiektu wzgledem wzorca                                *
* \param[in] Wsp   - wspolrzedne srodka polozenia obiektu                           *
* \param[in] kat   - kat o ktory jest obrocony obiekt                               *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
  Graniastoslup6(string Wzorzec,
                 string Finalna,
                 Wektor3D Skala,
                 Wektor3D Wsp,
                 double kat );

/************************************************************************************
* Metoda pozwalajaca przekazac wspolrzedne polozenia obiektu do innego obiektu      *                                                                     *
* \param[in] Wsp - wspolrzedne innego obiektu                                       *
* \param[out] - nowy Wektor zawierajacy wspolrzedne ukladu                          *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
  Wektor3D TransfDoUklWspRodzica(const Wektor3D &Wsp) const;
};

#endif