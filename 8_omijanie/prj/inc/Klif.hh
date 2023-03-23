#ifndef KLIF_HH
#define KLIF_HH
#include "BrylaGeometryczna.hh"
#include "bibloteki.hh"

class Klif : public BrylaGeometryczna {
    Wektor3D Polozenie;
    double KatOrientacji_stopnie;  
    vector<double> WspObrysu;  
    inline static uint nr_obj_klif=0;
    inline static uint ID=1;
  public:
/************************************************************************************
* Konstruktor bezparametryczny klasy Klif                                           *
* \param[out] - nowy obiekt z domyslnymi wartosciami    			 	                    *
************************************************************************************/
    Klif();

/************************************************************************************
* Konstruktor zapewniajacy mozliwosc deklaracji obiektu z wlasnymi wartosciami      *
* \param[in] Wsp   - wspolrzedne srodka polozenia obiektu                           *
* \param[in] kat   - kat o ktory jest obrocony obiekt                               *
* \param[out] - nowy obiekt z wlasnymi wartosciami      			 	                    *
************************************************************************************/
    Klif(Wektor3D Wsp, double kat);

/************************************************************************************
* Metoda pozwalajaca ustalic poczatkowe wspolrzedne obiektu                         *
* \param[in] Wsp - nowe wspolrzedne obiektu                                         *
* \param[out] - nowa wartosc pola this->Polozenie                                   *
************************************************************************************/
    void UstalPolozeniePoczatkowe(const Wektor3D &Wsp);

/************************************************************************************
* Metoda pozwalajaca przekazac wspolrzedne polozenia obiektu do innego obiektu      *
* \param[in] Wsp - wspolrzedne innego obiektu                                       *
* \param[out] - nowy Wektor zawierajacy wspolrzedne ukladu                          *
* \return - obiekt klasy Wektor                     			 	                        *
************************************************************************************/
    Wektor3D TransfDoUklWspRodzica(const Wektor3D &Wsp) const;

/************************************************************************************
* Metoda pozwalajaca przekowertowac numer przypisany do obiektu na lancuch znakowy  *
* \param[in] nr_obj_klif - indywidualny numer przypisany kazdemu nowemu obiektowi   *
* \return - lancuch znakowy                          			 	                        *
************************************************************************************/
    string ZwrocNumerObiektu() { return to_string(nr_obj_klif); }  
    
/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac informacje o typie obiektu                   *
* \param[out] - strumien wyjsciowy cout                                             * 
* \return - napis                                    			 	                        *
************************************************************************************/  
    const uint ZwrocID() const override {return this->ID;}

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac infoformacje na temat polozenia obiektu      *
* \param[out] - strumien wyjsciowy cout                                             * 
************************************************************************************/
    const char *Nazwa() const override { return "Gora z grania"; } 

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac infoformacje na temat polozenia obiektu      *
* \param[out] - strumien wyjsciowy cout                                             * 
************************************************************************************/
    const void ZwrocWsp() const override {cout << "(" << Polozenie[0] << ", " << Polozenie[1] << ") "; }
    
/************************************************************************************
* Metoda wirtualna pozwalajaca wyznaczyc poziomy obrys obiektu                      *
* \param[out] - informacje o obrysie przeniesione do obiektu klasy vector           * 
* \return - zmienna typu bool informujaca o powodzeniu operacji                     *
************************************************************************************/    
    bool UstalObrys() override ;

/************************************************************************************
* Metoda wirtualna pozwalajaca uzyskac dane na temat obrysu obiektu                 *
* \param[out] - vector z danymi o obrysie obiektu                                   * 
* \return - obiekt typu vector<double>             			 	                *
************************************************************************************/
    vector<double> ZwrocWspObrysu() override {return this->WspObrysu;}
};

#endif