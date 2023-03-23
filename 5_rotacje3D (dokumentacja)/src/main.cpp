#include <bibloteki.hh>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"
#define DL_BOKU 50
using namespace std;

void Menu()
{
   cout << " o - obrot bryly o zadana sekwencje katow\n";
   cout << " t - powtorzenie poprzedniego obrotu\n";
   cout << " r - wyswietlenie macierzy rotacji\n";
   cout << " p - przesuniecie bryly o zadany wektor\n";
   cout << " w - wyswietlenie wspolrzednych wierzcholkow\n";
   cout << " s - sprawdzenie dlugosci przeciwleglych bokow\n";
   cout << " m - wyswietl menu\n";
   cout << " a - wyswietl aktualna pozycje w programie Gnuplot\n";
   cout << " c - przywroc ustawienia poczatkowe, wyczysc ekran\n";
   cout << " k - koniec dzialania programu\n";
   cout << endl;
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

void PrzykladZapisuWspolrzednychDoStrumienia( ostream&     StrmWy, 
                                              Prostopadloscian  &Pr
                                            )
{
  for (int i=0; i<8; i+=2) {
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[i][0]
              << setw(16) << fixed << setprecision(10) << Pr[i][1] 
              << setw(16) << fixed << setprecision(10) << Pr[i][2]
       << endl;
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[i+1][0]
              << setw(16) << fixed << setprecision(10) << Pr[i+1][1] 
              << setw(16) << fixed << setprecision(10) << Pr[i+1][2]
       << endl;
       StrmWy << endl;
  }
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[0][0]
              << setw(16) << fixed << setprecision(10) << Pr[0][1] 
              << setw(16) << fixed << setprecision(10) << Pr[0][2]
       << endl; 
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[1][0]
              << setw(16) << fixed << setprecision(10) << Pr[1][1] 
              << setw(16) << fixed << setprecision(10) << Pr[1][2]
       << endl;
}


bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Prostopadloscian  &Pr
                                       )
{
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main()
{  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-150,150);
  Lacze.UstawZakresX(-150,150);
  Lacze.UstawZakresZ(-150,150);
   //---------------------------------------------------------------

   Wektor3D W1;
   Macierz3x3 M1,M_temp,M_pierwotna;
   Prostopadloscian Pr {{0,0,0},{50,0,0},{0,50,0},{50,50,0},{0,50,50},{50,50,50},{0,0,50},{50,0,50}};
   Scena Sc {Pr,M1};
   char wybor = ' ';
   int ilosc_obrotow;
   int domyslna_liczba = 1;

   Pr.SprDlugosc();
   Menu();
 
   while ( wybor!= 'k' ) {
    cout << "Twoj wybor? (m - menu) > ";
    cin >> wybor;

    switch(wybor) 
    {
        case 'o' : Sc = {Pr,M1};
                   Sc.WczytajSekwencje();
                   if (!(M_pierwotna == Sc.ZwrocMacierz(Sc))) {
                     cout << "Ile razy operacja obrotu ma byc powtorzona?\n";
                     if (cin >> ilosc_obrotow)
                       Pr = Sc.ObrocFigure(Sc,ilosc_obrotow);
                     else {
                       cout << "Nie podano liczby, zadana operacja zostanie wykonana jednorazowo\n";
                       ilosc_obrotow = domyslna_liczba;
                       Pr = Sc.ObrocFigure(Sc,ilosc_obrotow);
                       cin.clear();
                       cin.ignore(100000,'\n');
                     }
                   }
                   if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
                   Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                   cin.ignore(100000,'\n');
                   break;

        case 't' : if (!(M_pierwotna == Sc.ZwrocMacierz(Sc)))
                     Pr = Sc.ObrocFigure(Sc,ilosc_obrotow);
                   if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
                   Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                   cin.ignore(100000,'\n');
                   break;

        case 'r' : cout << Sc.ZwrocMacierz(Sc) << endl;
                   break;

        case 'p' : cout<< "Podaj wspolrzedne wektora translacji: ";
                   if (cin >> W1) {
                     Pr.Translacja(W1);
                     if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
                     Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     cin.ignore(100000,'\n');
                   }
                   else {
                     cout << "Bledny zapis wektora.\n";
                     cin.clear();
                     cin.ignore(100000,'\n');
                   }
                   break;

        case 'w' : cout << Pr << endl;
                   break;

        case 'a' : if (!PrzykladZapisuWspolrzednychDoPliku("prostopadloscian.dat",Pr)) return 1;
                   Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                   cin.ignore(100000,'\n');
                   break;

        case 'm' : Menu();
                   break;

        case 'c' : Pr = {{0,0,0},{50,0,0},{0,50,0},{50,50,0},{0,50,50},{50,50,50},{0,0,50},{50,0,50}};
                   Sc = {Pr,M1};
                   system("clear");
                   break;

        case 's' : Pr.SprDlugosc();
                   break;

        case 'k' : cout << "Koncze dzialanie programu.\n";
                   break;

        default  : cout << "Bledny wybor. Sprobuj ponownie...\n\n";
                   break;
    }
  }
}