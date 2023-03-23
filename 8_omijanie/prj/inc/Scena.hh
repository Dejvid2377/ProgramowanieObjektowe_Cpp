#ifndef SCENA_HH
#define SCENA_HH
#include "Dron.hh"
#include "Plaskowyz.hh"
#include "Klif.hh"
#include "GoraOstra.hh"
#include "bibloteki.hh"
#include "lacze_do_gnuplota.hh"

class Scena {
    PzG::LaczeDoGNUPlota Lacze;
    list<shared_ptr<BrylaGeometryczna>> ObiektySceny;
    list<shared_ptr<Dron>> ListaDronow;
    inline static uint numer_obiektu=0;
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Scena                                          *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	            *
************************************************************************************/
    Scena();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] TabDronow - tablica obiektow klasy Dron                                *
* \param[in] Lacze - lacze do modulu pozwalajacego na komunikacje z programem       *
*                    zewnetrznym GNUPlot                                            *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	            *
************************************************************************************/
    Scena(PzG::LaczeDoGNUPlota Lacze);

/************************************************************************************
* Metoda umozliwiajaca wybranie Drona ktorego chcemy przemiescic                    *
* \param[out] - strumien wyjsciowy z informacjami o polozeniu dostepnych obiektow   *
* \return - wskaznik na jeden z dwoch dostepnych obiektow z this->TabDronow         *
************************************************************************************/
    Dron & WezAktywnegoDrona();

/************************************************************************************
* Metoda umozliwiajaca uzycie wybranego Drona                                       *
* \return - wskaznik na obiekt z this->TabDronow                                    *
************************************************************************************/
    Dron& UzyjAktywnegoDrona();

/************************************************************************************
* Metoda umozliwiajaca wyswietlenie polozenia wybranego Drona                       *
* \param[in] Apollo - obiekt klasy Dron                                             *
* \param[out] - *
************************************************************************************/
    void PolozenieAktywnegoDrona(const Dron &Apollo) const;

/************************************************************************************
* Metoda umozliwiajaca przekazanie parametrow poczatkowych do modulu Lacza          *
* \param[out] this->Lacze - wskaznik na obiekt umozliwiajacy komunikacje z GNUPlotem*
************************************************************************************/
    void RysujScenerie();

/************************************************************************************
* Metoda wywolujaca aktualizacje obrazu prezentowanego przez GNUPlot-a              *
* \param[out] this->Lacze - wskaznik na obiekt umozliwiajacy komunikacje z GNUPlotem*
************************************************************************************/
    void UruchomLacze ();

/************************************************************************************
* Metoda dodajaca plik do danych prezentowanych przez GNUPlot-a                     *
* \param[in] Plik - nazwa pliku ktory chcemy dodac do Lacza                         *
* \param[out] this->Lacze - wskaznik na obiekt umozliwiajacy komunikacje z GNUPlotem*
************************************************************************************/
    void DodajPlik (const char* Plik);

/************************************************************************************
* Metoda usuwajaca plik z danych prezentowanych przez GNUPlot-a                     *
* \param[in] Plik - nazwa pliku ktory chcemy dodac do Lacza                         *
* \param[out] this->Lacze - wskaznik na obiekt umozliwiajacy komunikacje z GNUPlotem*
************************************************************************************/
    void UsunPlik (const char* Plik);
    void DodajDrona(Dron &WybranyDron);
/************************************************************************************
* Metoda umozliwiajaca dodanie do Sceny obiektu typu Plaskowyz                      *
* \param[in] Skala - parametry okreslajace wielkosc obiektu                         *
* \param[in] Polozenie - paramatry okreslajace polozenie obiektu                    *
* \param[out] Plaskowyz - nowy obiekt typu Plaskowyz                                *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool DodajPlaskowyz (Wektor3D &Skala, Wektor3D &Polozenie);

/************************************************************************************
* Metoda umozliwiajaca dodanie do Sceny obiektu typu Klif                           *
* \param[in] Skala - parametry okreslajace wielkosc obiektu                         *
* \param[in] Polozenie - paramatry okreslajace polozenie obiektu                    *
* \param[out] Klif - nowy obiekt typu Klif                                          *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool DodajKlif (Wektor3D &Skala,Wektor3D &Polozenie);

/************************************************************************************
* Metoda umozliwiajaca dodanie do Sceny obiektu typu Plaskowyz                      *
* \param[in] Skala - parametry okreslajace wielkosc obiektu                         *
* \param[in] Polozenie - paramatry okreslajace polozenie obiektu                    *
* \param[out] GoraOstra - nowy obiekt typu GoraOstra                                *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool DodajGore (Wektor3D &Skala,Wektor3D &Polozenie);

/************************************************************************************
* Metoda umozliwiajaca obliczenie wspolrzednych punktow nadajacych ksztalt obiektowi*
* \param[in] wsk_na_Plaskowyz - wskaznik na obiekt typu Plaskowyz                   *
* \param[out] Plaskowyz - nowy obiekt typu Plaskowyz                                *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool Oblicz_i_Zapisz_WspPlaskowyzu(shared_ptr<Plaskowyz> &wsk_na_Plaskowyz);

/************************************************************************************
* Metoda umozliwiajaca obliczenie wspolrzednych punktow nadajacych ksztalt obiektowi*
* \param[in] wsk_na_Klif - wskaznik na obiekt typu Klif                             *
* \param[out] Klif - nowy obiekt typu Klif                                          *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool Oblicz_i_Zapisz_WspKlifu(shared_ptr<Klif> &wsk_na_Klif);

/************************************************************************************
* Metoda umozliwiajaca obliczenie wspolrzednych punktow nadajacych ksztalt obiektowi*
* \param[in] wsk_na_Gore - wskaznik na obiekt typu GoraOstra                        *
* \param[out] GoraOstra - nowy obiekt typu GoraOstra                                *
* \return - wartosc boolowska informujaca o statusie powodzenia operacji            *
************************************************************************************/
    bool Oblicz_i_Zapisz_WspGory(shared_ptr<GoraOstra> &wsk_na_Gore);

/************************************************************************************
* Metoda umozliwiajaca uzyskanie dostepu do pola this->Lacze                        *
* \param[out] Lacze - dostep do komunikatora z GNUPlotem dla obiektu Scena          *
* \return - adres do prywatnego pola Lacze obiektu Scena                            *
************************************************************************************/
    PzG::LaczeDoGNUPlota& ZwrocLacze () { return this->Lacze;}

/************************************************************************************
* Metoda umozliwiajaca uzyskanie dostepu do wybranego obiektu listy poprzez wskaznik*
* \param[in] indeks_obiektu - numer obiektu na liscie wszystkich objektow           *
* \param[out] - dostep do wybranego obiektu                                         *
* \return - wskaznik na wybrany obiekt listy                                        *
************************************************************************************/
    shared_ptr<BrylaGeometryczna> ZwrocObiekt (uint indeks_obiektu);

/************************************************************************************
* Metoda umozliwiajaca zinkrementowanie iteratora listy do wybranego poziomu        *
* \param[in] indeks_obiektu - numer obiektu na liscie wszystkich objektow           *
* \param[out] - dostep do wybranego obiektu                                         *
* \return - wskaznik na wybrany obiekt listy                                        *
************************************************************************************/
    list<shared_ptr<BrylaGeometryczna>>::iterator ZwrocIndeks (uint indeks_obiektu);
    list<shared_ptr<BrylaGeometryczna>> ZwrocListe() { return this->ObiektySceny;}

/************************************************************************************
* Metoda umozliwiajaca usuniecie wybranego elementu z listy                         *
* \param[in] indeks_obiektu - numer obiektu na liscie wszystkich objektow           *
* \param[out] - lista pomniejszona o wybrany obiekt                                 *
************************************************************************************/    
    void UsunObiekt (uint indeks_obiektu);

/************************************************************************************
* Metoda umozliwiajaca wyswietlenie wszystkich objektow znajdujacych sie na liscie  *
* \param[in] ObiektySceny - lista obiektow                                                   *
* \param[out] - lista wyswietlona na standardowym strumieniu wyjsciowym             *
************************************************************************************/ 
    bool WyswietlElementyListy ();
    void DodajPodstawoweElementy();
};

#endif