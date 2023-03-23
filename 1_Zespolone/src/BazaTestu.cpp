#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"
using namespace std;
  
static WyrazZespol TestLatwy[] =
{
  {{2,1}, {1,2}, Op_Dodaj},
  {{1,0}, {0,1}, Op_Odejmij},
  {{3,0}, {0,3}, Op_Mnoz},
  {{4,8}, {1,0}, Op_Dziel},
};

static WyrazZespol TestTrudny[] =
{
  {{4, 8}, {2,2}, Op_Dziel},
  {{1.25, -2}, {-0.5, 2.01}, Op_Dodaj},
  {{0.25, 1}, {-0.375, 2}, Op_Odejmij},
  {{3, -0.5}, {1.5, 2}, Op_Mnoz},
};

BazaTestu::BazaTestu(WyrazZespol *wskTabTestu, unsigned int Ilosc, unsigned int Indeks)
    : wskTabTestu(wskTabTestu), Ilosc(Ilosc), Indeks(Indeks)
{
}

void BazaTestu::Ustaw(BazaTestu *wskBazaTestu, WyrazZespol *wskTabTestu, unsigned int Ilosc)
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->Ilosc = Ilosc;
  wskBazaTestu->Indeks = 0;
}

bool BazaTestu::Inicjalizuj(BazaTestu *wskBazaTestu, const char *sNazwaTestu)
{
  if (!strcmp(sNazwaTestu, "latwy"))
  {
    Ustaw(wskBazaTestu, TestLatwy, sizeof(TestLatwy) / sizeof(WyrazZespol));
    return true;
  }

  if (!strcmp(sNazwaTestu, "trudny"))
  {
    Ustaw(wskBazaTestu, TestTrudny, sizeof(TestTrudny) / sizeof(WyrazZespol));
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}

bool BazaTestu::NastepnePytanie(BazaTestu *wskBazaTestu, WyrazZespol *wskWyrazenie)
{
  if (wskBazaTestu->Indeks >= wskBazaTestu->Ilosc)
    return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->Indeks];
  ++wskBazaTestu->Indeks;
  return true;
}

bool BazaTestu::SprawdzOdpowiedz(WyrazZespol W1)
{
  int i = 2;
  LZespolona wprowadzona;
  LZespolona poprawna{W1.ObliczWyraz(W1)};

  cout << "   Twoja odpowiedz:  ";

  while (!wprowadzona.Wczytaj(wprowadzona) && i-- > 0 ) 
  {
    cout << "Sprobuj ponownie.\n\n";
    cout << "   Twoja odpowiedz: ";
  }

  if (poprawna == wprowadzona) 
  {
    cout << ":) Odpowiedz poprawna\n\n";
    return true;
  }
  else 
  {
    cout << "\n\n:( Blad. Prawidlowym wynikiem jest: " << poprawna;
    cout << endl << endl;
    return false;
  }
}
