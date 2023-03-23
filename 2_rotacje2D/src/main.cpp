#include <bibloteki.hh>
#include "Wektor2D.hh"
#include "Macierz.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

void Menu()
{
   cout << " o - obrot prostokata o zadany kat\n";
   cout << " p - przesuniecie prostokata o zadany wektor\n";
   cout << " w - wyswietlenie wspolrzednych wierzcholkow\n";
   cout << " s - wyswietlenie aktualnej pozycji w programie Gnuplot\n";
   cout << " m - wyswietl menu\n";
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
                                              Prostokat    &Pr
                                            )
{
   //---------------------------------------------------------------
   // To tylko przyklad !!!
   // W programie nalezy uzywać pojęcia wektora, a nie oddzielnych 
   // zmiennych do reprezentowania wspolrzednych!
   //
  for (int i=0; i<4; i++) {
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[i][0]
       << setw(16) << fixed << setprecision(10) << Pr[i][1] << endl;
  }
       StrmWy << setw(16) << fixed << setprecision(10) << Pr[0][0]
       << setw(16) << fixed << setprecision(10) << Pr[0][1] << endl;
       
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool PrzykladZapisuWspolrzednychDoPliku( const char  *sNazwaPliku,
                                         Prostokat    &Pr
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



int main() {
       
/*****************************************************************************/
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji 
                                // rysunku prostokata                         

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
   //      których połowa długości boku wynosi 2.
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
  Lacze.ZmienTrybRys(PzG::TR_2D);
/*****************************************************************************/

  Wektor2D W1;
  Macierz M1;
  Prostokat Pr {{0,0},{0,200},{100,200},{100,0}};
  char wybor = ' ';
  Pr.SprDlugosc(Pr);
  Menu();

  while ( wybor!= 'k' ) {
    cout << "Twoj wybor? (m - menu) > ";
    cin >> wybor;

    switch(wybor) 
    {
        case 'o' : cout << "Podaj kat o ktory chcesz obrocic prostokat: ";
                   MacierzRotacji(M1);
                   cout << "Ile razy chcesz dokonac obrotu? ";
                   KilkaObrotow(Pr,M1);
                   cout << endl;
                   
                   if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Pr)) return 1;
                   Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                   cin.ignore(100000,'\n');
                   Pr.SprDlugosc(Pr);
                   break;
        case 'p' : cout << "Podaj wspolrzedne wektora translacji: ";
                   if (cin >> W1) {
                     Pr.Translacja(W1);
                     if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Pr)) return 1;
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
        case 's' : if (!PrzykladZapisuWspolrzednychDoPliku("prostokat.dat",Pr)) return 1;
                   Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                   cin.ignore(100000,'\n');
                   break;
        case 'm' : Menu();
                   break;
        case 'c' : Pr = {{0,0},{0,200},{100,200},{100,0}};
                   system("clear");
                   break;
        case 'k' : cout << "Koncze dzialanie programu.\n";
                   break;
        default  : cout << "Bledny wybor. Sprobuj ponownie...\n\n";
                   break;
    }
  }
return 0;
}