/*!
 * \file
 * \brief Przykład animacji przelotu drona
 *
 * Przykład ten ma tylko i wyłącznie za zadanie pokazanie efektów animacji lotu
 * drona. Kod w nim zawarty nie jest pisany w sposób obiektowo zorientowany.
 * Dlatego też nie należy wzorować się na nim.
 * Niemniej można się wzorować na ciągu operacji, które należy wykonać,
 * aby otrzymać właściwą animację.
 */

#include "lacze_do_gnuplota.hh"
#include "BrylaGeometryczna.hh"
#include "Dron.hh"
#include "Graniastoslup6.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "Scena.hh"
#include "Wektor3D.hh"

using namespace std;

int main()
{  
  PzG::LaczeDoGNUPlota Lacze;
  vector<Wektor3D> PunktySciezki;
  Wektor3D temp;
  double kat,dlugosc_lotu;
  char znak;
  Dron Drony[2];
  Scena Mars = {Drony,Lacze};
  Mars.UruchomLacze();

  Menu();
  
  do {
    cout << "Twoj wybor, m - menu> ";
    cin >> znak;
    switch (znak) {
      case 'p': cout << "Podaj kat lotu: ";
                cin >> kat;
                cout << "Podaj dlugosc lotu: ";
                cin >> dlugosc_lotu;
                Mars.UzyjAktywnegoDrona().WykonajPrzemieszczenie(kat,dlugosc_lotu,PunktySciezki,Mars.ZwrocLacze());
                temp.WyswietlObiekty();
                cout << endl;
                break;
      
      case 'm': Menu();
                break;
      case 'k': break;
      default : cout << "Nie rozpoznano, sprobuj ponownie..." << endl << endl;
                break;
    }
  } while (znak!='k');
  cout << "Koniec dzialania programu." << endl;
}