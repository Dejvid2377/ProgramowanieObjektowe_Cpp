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
  Dron Tytan1 = {{20,20,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON1_KORPUS,SKALA_KORPUSU,S,0},
                 Rotory};
  Dron Tytan2 = {{70,70,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON2_KORPUS,SKALA_KORPUSU,S,0},
                Rotory2};

  this->DodajDrona(Tytan1);
  this->DodajDrona(Tytan2);
}

Scena::Scena(PzG::LaczeDoGNUPlota Lacze)
    :Lacze(Lacze)
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
  Dron Tytan1 = {{20,20,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON1_KORPUS,SKALA_KORPUSU,S,0},
                 Rotory};
  Dron Tytan2 = {{70,70,0},0,
                {PLIK_WZORCOWEGO_SZESCIANU,PLIK_ROBOCZY__DRON2_KORPUS,SKALA_KORPUSU,S,0},
                Rotory2};
  
  this->RysujScenerie(); 
  this->DodajDrona(Tytan1);
  this->DodajDrona(Tytan2);             
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
  this->DodajPodstawoweElementy();
}

void Scena::DodajPodstawoweElementy()
{
  Wektor3D Polozenie1 {30,60,0};
  Wektor3D Polozenie2 {170,170,0};
  Wektor3D Polozenie3 {30,170,0};
  Wektor3D Polozenie4 {100,100,0};
  Wektor3D Skala1 {30,30,60};
  Wektor3D Skala2 {60,60,20};
  Wektor3D Skala3 {10,80,40};
  Wektor3D Skala4 {20,20,100};

  if (this->DodajGore(Skala1,Polozenie2)) cout << "Podstawowy obiekt sceny poprawnie wczytany\n";
  if (this->DodajPlaskowyz(Skala2,Polozenie1)) cout << "Podstawowy obiekt sceny poprawnie wczytany\n";
  if (this->DodajKlif(Skala3,Polozenie4)) cout << "Podstawowy obiekt sceny poprawnie wczytany\n";
  if (this->DodajPlaskowyz(Skala4,Polozenie3)) cout << "Podstawowy obiekt sceny poprawnie wczytany\n";
}

Dron& Scena::WezAktywnegoDrona()
{

    Wektor3D temp_wek;
    int temp_liczba;
    list<shared_ptr<Dron>>::iterator dron1 = this->ListaDronow.begin();
    list<shared_ptr<Dron>>::iterator dron2 = ++this->ListaDronow.begin();

    cout << "Wybor aktywnego drona\n\n";
    cout << "1 - Polozenie (x,y): ";
    (*dron1)->ZwrocWsp();
    cout << endl;
    cout << "2 - Polozenie (x,y): ";
    (*dron2)->ZwrocWsp();
    cout << endl;

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
      this->PolozenieAktywnegoDrona(**dron1);
      return **dron1;
    }
    else {
      this->PolozenieAktywnegoDrona(**dron2);
      return **dron2;
    }
}

Dron& Scena::UzyjAktywnegoDrona()
{  
  return this->WezAktywnegoDrona();
}

void Scena::PolozenieAktywnegoDrona(const Dron &Apollo) const
{
  cout << "Polozenie Drona aktywnego (x,y): ";
  Apollo.ZwrocWsp();
  cout << endl;
}

void Scena::UruchomLacze()
{
  this->Lacze.Rysuj();
}

void Scena::DodajPlik(const char* Plik)
{ 
  this->Lacze.DodajNazwePliku(Plik);
}

void Scena::UsunPlik(const char* Plik)
{ 
  this->Lacze.UsunNazwePliku(Plik);
}

void Scena::DodajDrona(Dron &WybranyDron)
{
  WybranyDron.Oblicz_i_Zapisz_WspGlbDrona();
  this->ListaDronow.push_back(make_shared<Dron>(WybranyDron));
  this->ObiektySceny.push_back(make_shared<Dron>(**ListaDronow.begin()));

}

bool Scena::DodajPlaskowyz(Wektor3D &Skala,Wektor3D &Polozenie)
{
  this->ObiektySceny.push_back(make_shared<Plaskowyz>());
  numer_obiektu++;
  
  shared_ptr<Plaskowyz> wsk_na_Plaskowyz = static_pointer_cast<Plaskowyz>(this->ZwrocObiekt(numer_obiektu));
  wsk_na_Plaskowyz->ZmienSkale(Skala);
  Polozenie[2] = Skala[2] * 0.5;
  wsk_na_Plaskowyz->UstalPolozeniePoczatkowe(Polozenie);

  if(!Oblicz_i_Zapisz_WspPlaskowyzu(wsk_na_Plaskowyz)) return false;
 
  auto napis = wsk_na_Plaskowyz->WezNazwePliku_BrylaFinalna().c_str();
  this->DodajPlik(napis);

  return true;
}

bool Scena::Oblicz_i_Zapisz_WspPlaskowyzu(shared_ptr<Plaskowyz> &wsk_na_Plaskowyz)
{
  ifstream Plik_BrylaWzorcowa(wsk_na_Plaskowyz->WezNazwePliku_BrylaWzorcowa());
  ofstream Plik_BrylaWynikowa(wsk_na_Plaskowyz->WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;

  if (!Plik_BrylaWzorcowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku1: " 
         << wsk_na_Plaskowyz->WezNazwePliku_BrylaWzorcowa() << endl << endl;
    return false;
  }

  if (!Plik_BrylaWynikowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku2: " 
         << wsk_na_Plaskowyz->WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_BrylaWzorcowa.good());
  assert(Plik_BrylaWynikowa.good());  
  Plik_BrylaWzorcowa >> Wierz;
  while (!Plik_BrylaWzorcowa.fail()) {
      
    for(unsigned int IloscWierzcholkow = 0; IloscWierzcholkow < ILOSC_WIERZ_LINII_TWORZACEJ;
      ++IloscWierzcholkow) {

      Wierz = wsk_na_Plaskowyz->Skaluj(Wierz);
     /* if (fabs(Polozenie[2]-WYSOKOSC)<EPSILON))
        Wierz = TransformataZ(KatOrientacji_stopnie) * Wierz; */
      Wierz = wsk_na_Plaskowyz->TransfDoUklWspRodzica(Wierz);

      Plik_BrylaWynikowa <<Wierz[0]<<" "<<Wierz[1]<<" "<<Wierz[2]<<endl;
      Plik_BrylaWzorcowa >> Wierz[0] >> Wierz[1] >> Wierz[2];  
      
      assert(IloscWierzcholkow == ILOSC_WIERZ_LINII_TWORZACEJ-1 || !Plik_BrylaWynikowa.fail());
    }
    Plik_BrylaWynikowa <<  endl;
  }
  return !Plik_BrylaWynikowa.fail();
}

bool Scena::DodajKlif(Wektor3D &Skala,Wektor3D &Polozenie)
{
  this->ObiektySceny.push_back(make_shared<Klif>());
  numer_obiektu++;
  
  shared_ptr<Klif> wsk_na_Klif = static_pointer_cast<Klif>(this->ZwrocObiekt(numer_obiektu));
  wsk_na_Klif->ZmienSkale(Skala);
  Polozenie[2] = Skala[2] * 0.5;
  wsk_na_Klif->UstalPolozeniePoczatkowe(Polozenie);

  if(!Oblicz_i_Zapisz_WspKlifu(wsk_na_Klif)) return false;
 
  auto napis = wsk_na_Klif->WezNazwePliku_BrylaFinalna().c_str();
  this->DodajPlik(napis);

  return true;
}

bool Scena::Oblicz_i_Zapisz_WspKlifu(shared_ptr<Klif> &wsk_na_Klif)
{
  ifstream Plik_BrylaWzorcowa(wsk_na_Klif->WezNazwePliku_BrylaWzorcowa());
  ofstream Plik_BrylaWynikowa(wsk_na_Klif->WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;

  if (!Plik_BrylaWzorcowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << wsk_na_Klif->WezNazwePliku_BrylaWzorcowa() << endl << endl;
    return false;
  }

  if (!Plik_BrylaWynikowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << wsk_na_Klif->WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_BrylaWzorcowa.good());
  assert(Plik_BrylaWynikowa.good());  
  Plik_BrylaWzorcowa >> Wierz;
  while (!Plik_BrylaWzorcowa.fail()) {
      
    for(unsigned int IloscWierzcholkow = 0; IloscWierzcholkow < ILOSC_WIERZ_LINII_TWORZACEJ;
      ++IloscWierzcholkow) {
      
      if (Wierz[2] >= 0.5) {
        if (Wierz[0]<0) Wierz[0] = fabs(Wierz[0]);
      }
      Wierz = wsk_na_Klif->Skaluj(Wierz);
     /* if (fabs(Polozenie[2]-WYSOKOSC)<EPSILON))
        Wierz = TransformataZ(KatOrientacji_stopnie) * Wierz; */
      Wierz = wsk_na_Klif->TransfDoUklWspRodzica(Wierz);

      Plik_BrylaWynikowa <<Wierz[0]<<" "<<Wierz[1]<<" "<<Wierz[2]<<endl;
      Plik_BrylaWzorcowa >> Wierz[0] >> Wierz[1] >> Wierz[2];  
      
      assert(IloscWierzcholkow == ILOSC_WIERZ_LINII_TWORZACEJ-1 || !Plik_BrylaWynikowa.fail());
    }
    Plik_BrylaWynikowa <<  endl;
  }
  return !Plik_BrylaWynikowa.fail();
}

bool Scena::DodajGore(Wektor3D &Skala,Wektor3D &Polozenie)
{
  this->ObiektySceny.push_back(make_shared<GoraOstra>());
  numer_obiektu++;
  
  shared_ptr<GoraOstra> wsk_na_Gore = static_pointer_cast<GoraOstra>(this->ZwrocObiekt(numer_obiektu));
  wsk_na_Gore->ZmienSkale(Skala);
  Polozenie[2] = Skala[2] * 0.5;
  wsk_na_Gore->UstalPolozeniePoczatkowe(Polozenie);

  if(!Oblicz_i_Zapisz_WspGory(wsk_na_Gore)) return false;
 
  auto napis = wsk_na_Gore->WezNazwePliku_BrylaFinalna().c_str();
  this->DodajPlik(napis);

  return true;
}

bool Scena::Oblicz_i_Zapisz_WspGory(shared_ptr<GoraOstra> &wsk_na_Gore)
{
  ifstream Plik_BrylaWzorcowa(wsk_na_Gore->WezNazwePliku_BrylaWzorcowa());
  ofstream Plik_BrylaWynikowa(wsk_na_Gore->WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;

  if (!Plik_BrylaWzorcowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << wsk_na_Gore->WezNazwePliku_BrylaWzorcowa() << endl << endl;
    return false;
  }

  if (!Plik_BrylaWynikowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << wsk_na_Gore->WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_BrylaWzorcowa.good());
  assert(Plik_BrylaWynikowa.good());  
  Plik_BrylaWzorcowa >> Wierz;
  while (!Plik_BrylaWzorcowa.fail()) {
      
    for(unsigned int IloscWierzcholkow = 0; IloscWierzcholkow < ILOSC_WIERZ_LINII_TWORZACEJ;
      ++IloscWierzcholkow) {
      
      if (Wierz[2] == 0.5) {
        Wierz[0] = Wierz[1] = 0;
      }
      else if (Wierz[2]==0) {
        Wierz[0] /= 2; Wierz[1] /= 2;
      }
      Wierz = wsk_na_Gore->Skaluj(Wierz);
     /* if (fabs(Polozenie[2]-WYSOKOSC)<EPSILON))
        Wierz = TransformataZ(KatOrientacji_stopnie) * Wierz; */
      Wierz = wsk_na_Gore->TransfDoUklWspRodzica(Wierz);

      Plik_BrylaWynikowa <<Wierz[0]<<" "<<Wierz[1]<<" "<<Wierz[2]<<endl;
      Plik_BrylaWzorcowa >> Wierz[0] >> Wierz[1] >> Wierz[2];  
      
      assert(IloscWierzcholkow == ILOSC_WIERZ_LINII_TWORZACEJ-1 || !Plik_BrylaWynikowa.fail());
    }
    Plik_BrylaWynikowa <<  endl;
  }
  return !Plik_BrylaWynikowa.fail();
}

shared_ptr<BrylaGeometryczna> Scena::ZwrocObiekt (uint indeks_obiektu)
{
  return *this->ZwrocIndeks(indeks_obiektu);
}

void Scena::UsunObiekt(uint indeks_obiektu)
{
  list<shared_ptr<BrylaGeometryczna>>::iterator indeks = this->ZwrocIndeks(indeks_obiektu);
  auto napis = (*indeks)->WezNazwePliku_BrylaFinalna().c_str();
  this->UsunPlik(napis);
  this->ObiektySceny.erase(indeks);
  numer_obiektu--;
}

list<shared_ptr<BrylaGeometryczna>>::iterator Scena::ZwrocIndeks(uint indeks_obiektu)
{
  list<shared_ptr<BrylaGeometryczna>>::iterator licznik = this->ObiektySceny.begin();
  if ((indeks_obiektu-1) < this->ObiektySceny.size()) {
    advance(licznik,indeks_obiektu-1);
    return licznik;
  }
  else {
    cout << "Bledny numer indeksu.." << endl;
    exit(0);
  }
}

bool Scena::WyswietlElementyListy()
{
  int licznik = 1;
  for (const shared_ptr<BrylaGeometryczna> &Obiekty : this->ObiektySceny) {
    cout << licznik << " - ";
    Obiekty->ZwrocWsp(); 
    cout << Obiekty->Nazwa() << endl;
    licznik++;
  }
  if (licznik==1) {
    cout << "Brak elementow na liscie." << endl << endl;
    return false;
  }
  else 
    return true;
}