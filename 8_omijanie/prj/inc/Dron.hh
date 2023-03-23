#ifndef DRON_HH
#define DRON_HH
#include "bibloteki.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Dron.hh"
#include "lacze_do_gnuplota.hh"

class Dron : public BrylaGeometryczna {
  private:
    Wektor3D Polozenie;
    double KatOrientacji_stopnie;
    Prostopadloscian KorpusDrona;
    vector<double> WspObrysu;
    Graniastoslup6  RotorDrona[4];
    inline static uint nr_obj_dron=0;
    inline static uint ID=0;
/************************************************************************************
* Metoda prywatna pozwalajaca obliczyc i zapisac wspolrzedne globalne korpusu drona *                                                                     *
* \param[in] - dane z pliku                                                         *
* \param[out] - nowo utworzone wspolrzedne wierzcholkow                             *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool Oblicz_i_Zapisz_WspGlbKorpusu();
/************************************************************************************
* Metoda prywatna pozwalajaca obliczyc i zapisac wspolrzedne globalne rotora drona  *                                                                     *
* \param[in] - dane z pliku                                                         *
* \param[out] - nowo utworzone wspolrzedne wierzcholkow                             *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool Oblicz_i_Zapisz_WspGlbRotora(Graniastoslup6 &Rotor);

/************************************************************************************
* Metoda pozwalajaca przekazac wspolrzedne polozenia obiektu do innego obiektu      *
* \param[in] Wsp - wspolrzedne innego obiektu                                       *
* \param[out] - nowy Wektor zawierajacy wspolrzedne ukladu                          *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
  protected:
    Wektor3D TransfDoUklWspRodzica(const Wektor3D &Wsp) const;

  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Dron                                           *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    Dron();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] Wsp   - wspolrzedne srodka polozenia obiektu                           *
* \param[in] kat   - kat o ktory jest obrocony obiekt                               *
* \param[in] Pr    - obiekt klasy Prostopadloscian                                  *
* \param[in] TabRot - tablica obiektow klasy Graniastoslup6                         *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    Dron(Wektor3D Wsp, double kat,Prostopadloscian Pr,Graniastoslup6 TabRot[4]);

/************************************************************************************
* Metoda umozliwiajaca rysowanie trasy przelotu dla Drona                           *
* \param[in] KatSkretu_stopnie - kat obrotu Drona                                   *
* \param[in] DlugoscLotu - dlugosc trasy jaka ma pokonac Dron                       *
* \param[in] PunktySciezki - obiekt klasy vector przechowujacy punkty sciezki       *
* \param[out] - plik z zapisanymi punktami trasy Drona   			 	                    *
************************************************************************************/
    void PlanujPoczatkowaSciezke(double KatSkretu_stopnie,
                                 double DlugoscLotu,
                                 vector<Wektor3D> &PunktySciezki);
    void ModyfikujTrasePrzelotu(double DlugoscLotu,
                                PzG::LaczeDoGNUPlota &Lacze,
                                vector<Wektor3D> &PunktySciezki);

/************************************************************************************
* Metoda umozliwiajaca wykonanie animacji pionowego lotu Drona                      *
* \param[in] PunktySciezki - obiekt klasy vector przechowujacy punkty sciezki       *
* \param[in] Lacze - zmienna zapewniajaca polaczenie z laczem programu GNUPlot      *
* \param[out] - nowe wspolrzedne polozenia drona         			 	                    *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool WykonajPionowyLot(vector<Wektor3D> &PunktySciezki,PzG::LaczeDoGNUPlota &Lacze);

/************************************************************************************
* Metoda umozliwiajaca wykonanie animacji poziomego lotu Drona                      *
* \param[in] PunktySciezki - obiekt klasy vector przechowujacy punkty sciezki       *
* \param[in] Lacze - zmienna zapewniajaca polaczenie z laczem programu GNUPlot      *
* \param[out] - nowe wspolrzedne polozenia drona         			 	            *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool WykonajPoziomyLot(vector<Wektor3D> &PunktySciezki,PzG::LaczeDoGNUPlota &Lacze);
    bool EtapLadowania(list<shared_ptr<BrylaGeometryczna>> Lista,vector<Wektor3D> &PunktySciezki,PzG::LaczeDoGNUPlota &Lacze);

/************************************************************************************
* Metoda umozliwiajaca wykonanie animacji obrotu Drona                              *
* \param[in] KatSkretu_stopnie - wartosc kata o ktory ma skrecic uklad Drona        *
* \param[in] Lacze - zmienna zapewniajaca polaczenie z laczem programu GNUPlot      *
* \param[out] - nowe wspolrzedne polozenia drona         			 	            *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool WykonajObrot(double KatSkretu_stopnie, PzG::LaczeDoGNUPlota &Lacze);

/************************************************************************************
* Metoda umozliwiajaca wykonanie animacji calego lotu Drona                         *
* \param[in] KatSkretu_stopnie - wartosc kata o ktory ma skrecic uklad Drona        *
* \param[in] DlugoscLotu - dlugosc trasy jaka ma pokonac Dron                       *
* \param[in] PunktySciezki - obiekt klasy vector przechowujacy punkty sciezki       *
* \param[in] Lacze - zmienna zapewniajaca polaczenie z laczem programu GNUPlot      *
* \param[out] - nowe wspolrzedne polozenia drona         			 	            *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/
    bool WykonajPrzemieszczenie(double KatSkretu_stopnie,
                                double DlugoscLotu,
                                vector<Wektor3D> &PunktySciezki,
                                list<shared_ptr<BrylaGeometryczna>> Lista,
                                PzG::LaczeDoGNUPlota &Lacze);

/************************************************************************************
* Metoda pozwalajaca obliczyc i zapisac wspolrzedne globalne calego drona           *                                                                     *
* \param[in] - dane z plikow opisujacych korpus i rotory                            *
* \param[out] - bryly umieszczone we wspolnym ukladzie odniesienia                  *
* \return - logiczna wartosc informujaca o powodzeniu operacji                      *
************************************************************************************/                                
    bool Oblicz_i_Zapisz_WspGlbDrona();

/************************************************************************************
* Metoda pozwalajaca ustalic kat obrotu Drona                                       * 
* \param[in] kat - kat o ktory chcemy obrocic Drona                                 *
* \param[out] KatOrientacji_stopnie - zmienna opisujaca klase Dron z przypisana     *
*                                     wartoscia zmiennej kat                        *
************************************************************************************/
    void UstawKat(double kat) { KatOrientacji_stopnie = kat; }

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac unikalne ID obiektu                          *
* \param[out] - unikalne ID obiektu                                                 * 
* \return - liczba typu uint                                                        *
************************************************************************************/
    const uint ZwrocID() const override {return this->ID;}
    const uint ZwrocNumerObiektu() const { return nr_obj_dron; } 

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac informacje o typie obiektu                   *
* \param[out] - strumien wyjsciowy cout                                             * 
* \return - napis                                    			 	                *
************************************************************************************/
    const char *Nazwa() const { return "Dron"; }
    
/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac infoformacje na temat polozenia obiektu      *
* \param[out] - strumien wyjsciowy cout                                             * 
************************************************************************************/
    virtual const void ZwrocWsp() const override {cout << "(" << Polozenie[0] << ", " << Polozenie[1] << ") "; }

/************************************************************************************
* Metoda wirtualna pozwalajaca wektor polozenia obiektu                             *
* \param[out] - polozenie obiektu w bazie R3                                        * 
* \return - Wektor3D                                  			 	                *
************************************************************************************/
    const Wektor3D ZwrocPolozenie() const override { return Polozenie; }

/************************************************************************************
* Metoda wirtualna pozwalajaca wyznaczyc poziomy obrys obiektu                      *
* \param[out] - informacje o obrysie przeniesione do obiektu klasy vector           * 
* \return - zmienna typu bool informujaca o powodzeniu operacji                     *
************************************************************************************/
    bool UstalObrys() override;

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac dane na temat obrysu obiektu                 *
* \param[out] - vector z danymi o obrysie obiektu                                   * 
* \return - obiekt typu vector<double>             			 	                *
************************************************************************************/
    vector<double> ZwrocWspObrysu() override {return this->WspObrysu;}

/************************************************************************************
* Metoda wirtualna pozwalajaca sprawdzic czy dwa obiekty nie koliduja ze soba       *
* \param[out] - informacja o biezacym polozeniu drona                               * 
* \return - zmienna typu bool informujaca o powodzeniu operacji                     *
************************************************************************************/
    bool CzyKolizja(const vector<double> &ObrysBryl) override;
};
#endif