#ifndef BAZATESTU_HH
#define BAZATESTU_HH
#include "WyrazZesp.hh"

class BazaTestu {
  public:
    BazaTestu() { wskTabTestu=NULL; Ilosc=0; Indeks=0; }
    BazaTestu(WyrazZespol *TabTestu, unsigned int Ilosc, unsigned int Indeks);
    void Ustaw( BazaTestu *wskBazaTestu, WyrazZespol *wskTabTestu, unsigned int Ilosc);
    bool Inicjalizuj( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
    bool NastepnePytanie( BazaTestu  *wskBazaTestu,  WyrazZespol *wskWyr );
    bool SprawdzOdpowiedz (WyrazZespol W1);
  private:
    WyrazZespol  *wskTabTestu;   
    unsigned int Ilosc;    
    unsigned int Indeks; 
};

#endif
