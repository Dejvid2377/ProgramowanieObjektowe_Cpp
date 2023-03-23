#include "lacze_do_gnuplota.hh"
#include "Scena.hh"

int main()
{   
  PzG::LaczeDoGNUPlota Lacze;
  vector<Wektor3D> PunktySciezki;
  Wektor3D Skala, Polozenie;
  double kat,dlugosc_lotu;
  char znak;
  int temp;
  Dron Drony[2];
  Scena Mars = {Drony,Lacze};
  Mars.UruchomLacze();
  
  cout << "Kliknij ENTER, aby rozpoczac..";
  cin.ignore(10000,'\n');
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
                cout << endl;
                break;
      case 'd': cout << "Wybierz rodzaj powierzchniowego elementu";
                Menu2();
                if(cin >> temp) {
                  cout << "Podaj Skale wzdluz kolejnych osi (X,Y,Z) > ";
                  cin >> Skala;
                  cout << "Podaj wspolrzedne srodka podstawy (x,y) > ";
                  cin >> Polozenie[0] >> Polozenie[1];
                  if (temp==1) Mars.DodajGore(Skala,Polozenie);
                  if (temp==2) Mars.DodajKlif(Skala,Polozenie);
                  if (temp==3) Mars.DodajPlaskowyz(Skala,Polozenie);
                  cout << "Element zostal dodany do scenu" << endl << endl;
                  Mars.UruchomLacze();
                }
                else 
                  cout << "Niewlasciwy numer elementu.";
                break;
      case 'u': cout << "Wybierz element powierzchni do usuniecia: " << endl;
                if(Mars.WyswietlElementyListy()) { 
                  cout << "Podaj numer elementu > ";
                  cin>> temp;
                  Mars.UsunObiekt(temp);
                  cout << "Element zostal usuniety." << endl;
                  Mars.UruchomLacze();
                }
                break;
      case 'm': Menu();
                break;
      case 'k': break;
      default : cout << "Nie rozpoznano, sprobuj ponownie..." << endl << endl;
                break;
    }
  } while (znak!='k');
  cout << "Koniec dzialania programu." << endl;
  return 0;
}

