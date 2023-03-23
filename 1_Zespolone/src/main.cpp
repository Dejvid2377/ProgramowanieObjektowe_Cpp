/*********************************************************************************
 * \param[Autor projektu]: Dawid Krekora                                         *
 * \param[Nazwa projektu]: Test z arytmetyki liczb zespolonych                   *
 * \param[Opis dzialania]: Program sluzy do sprawdzenia wiedzy uzytkownika z     *
 *                         dziedziny liczb zespolonych w formie testowej.        *
 *                         Po wybraniu trudnosci (latwy/trudny - jako argument   *
 *                         wywolania) i uruchomieniu programu uzytkownik         *
 *                         odpowiada na pytania dotyczace dzialan arytmetycznych *
 *                         zostajac zobligowanym do udzielenia prawidlowej       *
 *                         odpowiedzi. Pod zakonczeniu zostaje przedstawiony     *
 *                         rezultat koncowy w formie statystyki                  *
 *********************************************************************************/
#include <iostream>
#include <cmath>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazZesp.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char **argv) {

  BazaTestu BazaT;
  WyrazZespol PytTest;
  Statystyka Stats;
  
  if (argc < 2) {
    cout << endl;
    cerr << " Brak opcji okreslajacej rodzaj testu.\n";
    cout << " Dopuszczalne nazwy to:  latwy, trudny.\n\n";
    return 1;
  }

  if (BazaT.Inicjalizuj(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie.\n";
    return 1;
  } 

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: Wybrano test " << argv[1];
  cout << endl << endl;
  
  while (BazaT.NastepnePytanie(&BazaT,&PytTest)) {
    cout << ":? Podaj wynik operacji: ";
    PytTest.WyswietlWyraz(PytTest);

    if (BazaT.SprawdzOdpowiedz(PytTest))
      Stats.prawidlowe();
    else
      Stats.bledne();
  }

  cout << " Koniec testu\n\n";
  Stats.rezultat();


  return 0;
}
