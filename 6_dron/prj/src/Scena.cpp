#include "Scena.hh"

Scena::Scena()
{ 
  Wektor3D S {0,0,2};
  Graniastoslup6 Rotory[4] = {{PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR1,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR2,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR3,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_TYLNY,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR4,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_TYLNY,0}};
  Graniastoslup6 Rotory2[4] = {{PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR1,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR2,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR3,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_TYLNY,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR4,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_TYLNY,0}};
  TabDronow[0] = {{20,20,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON1_KORPUS,SKALA_KORPUSU,S,0},
                 Rotory};
  TabDronow[1] = {{70,70,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON2_KORPUS,SKALA_KORPUSU,S,0},
                Rotory2};
}

Scena::Scena(Dron Drony[2],PzG::LaczeDoGNUPlota Lacze)
    :Lacze(Lacze)
{
  for (int i=0;i<2;i++)
    TabDronow[i] = Drony[i];

  Wektor3D S {0,0,2};
  Graniastoslup6 Rotory[4] = {{PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR1,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR2,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR3,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_TYLNY,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON1_ROTOR4,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_TYLNY,0}};
  Graniastoslup6 Rotory2[4] = {{PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR1,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR2,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_PRZEDNI,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR3,SKALA_ROTORA,TRANSLACJA_ROTOR_LEWY_TYLNY,0},
                            {PLIK_WZORCOWEGO_GRANIASTOSLUPA6,PLIK_ROBOCZY__DRON2_ROTOR4,SKALA_ROTORA,TRANSLACJA_ROTOR_PRAWY_TYLNY,0}};
  TabDronow[0] = {{20,20,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON1_KORPUS,SKALA_KORPUSU,S,0},
                 Rotory};
  TabDronow[1] = {{70,70,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON2_KORPUS,SKALA_KORPUSU,S,0},
                Rotory2};
  
  this->RysujScenerie();             
  TabDronow[0].Oblicz_i_Zapisz_WspGlbDrona();  
  TabDronow[1].Oblicz_i_Zapisz_WspGlbDrona(); 
}

void Scena::RysujScenerie()
{  
  Lacze.DodajNazwePliku("bryly_wzorcowe/plaszczyzna.dat");
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON1_KORPUS);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON1_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON1_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON1_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON1_ROTOR4);

  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON2_KORPUS);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON2_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON2_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON2_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_ROBOCZY__DRON2_ROTOR4);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);
  Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok
}
 const Dron& Scena::WezAktywnegoDrona() const
{

    Wektor3D Wsp1 = TabDronow[0].ZwrocPolozenie();
    Wektor3D Wsp2 = TabDronow[1].ZwrocPolozenie();
    Wektor3D temp_wek;
    int temp_liczba;

    cout << "Wybor aktywnego drona\n\n";
    cout << "1 - Polozenie (x,y): " << Wsp1[0] << " " << Wsp1[1] << endl;
    cout << "2 - Polozenie (x,y): " << Wsp2[0] << " " << Wsp2[1] << endl;

    cout << "Wprowadz numer aktywnego drona> ";
    while (!(cin >> temp_liczba)) {
      if (temp_liczba==1);         
      else if (temp_liczba==2);
      else {
        cout << "Bledny numer Drona. Sprobuj ponownie..." << endl;
        cout << "Wprowadz numer aktywnego drona> ";
        cin.clear();
        cin.ignore(100000,'\n');
      }
    }

    if (temp_liczba == 1) {
      this->PolozenieAktywnegoDrona(TabDronow[0]);
      return this->TabDronow[0];
    }
    else {
      this->PolozenieAktywnegoDrona(TabDronow[1]);
      return this->TabDronow[1];
    }
}

Dron& Scena::UzyjAktywnegoDrona()
{  
  this->WezAktywnegoDrona();
}

void Scena::PolozenieAktywnegoDrona(const Dron &Apollo) const
{
  Wektor3D W1 = Apollo.ZwrocPolozenie();
  cout << "Polozenie Drona aktywnego (x,y): " << W1[0] << " " << W1[1] << endl << endl;
}

void Scena::UruchomLacze()
{
  Lacze.Rysuj();
  cout << "Nacisnij ENTER" << flush;
  cin.ignore(10000,'\n');
}

void Scena::DodajPlik(const char* Plik)
{
  Lacze.DodajNazwePliku(Plik);
}