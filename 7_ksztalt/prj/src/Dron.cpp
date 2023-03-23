#include "Dron.hh"

Dron::Dron()
{
  Polozenie = {0,0,0};
  KatOrientacji_stopnie = 0;
}

Dron::Dron(Wektor3D Wsp, double kat,Prostopadloscian Pr,Graniastoslup6 TabRot[4])
    :Polozenie(Wsp),KatOrientacji_stopnie(kat),KorpusDrona(Pr)
{
  for(int i=0; i<4; i++) 
    RotorDrona[i] = TabRot[i]; 
}

bool Dron::Oblicz_i_Zapisz_WspGlbKorpusu()
{
  ifstream Plik_BrylaWzorcowa(KorpusDrona.WezNazwePliku_BrylaWzorcowa());
  ofstream Plik_BrylaWynikowa(KorpusDrona.WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;

  if (!Plik_BrylaWzorcowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << KorpusDrona.WezNazwePliku_BrylaWzorcowa() << endl << endl;
    return false;
  }

  if (!Plik_BrylaWynikowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << KorpusDrona.WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_BrylaWzorcowa.good());
  assert(Plik_BrylaWynikowa.good());  
  Plik_BrylaWzorcowa >> Wierz;
  while (!Plik_BrylaWzorcowa.fail()) {
      
    for(unsigned int IloscWierzcholkow = 0; IloscWierzcholkow < ILOSC_WIERZ_LINII_TWORZACEJ;
      ++IloscWierzcholkow) {

      Wierz = KorpusDrona.Skaluj(Wierz);
     /* if (fabs(Polozenie[2]-WYSOKOSC)<EPSILON))
        Wierz = TransformataZ(KatOrientacji_stopnie) * Wierz; */
      Wierz = KorpusDrona.TransfDoUklWspRodzica(Wierz);
      Wierz = this->TransfDoUklWspRodzica(Wierz);

      Plik_BrylaWynikowa <<Wierz[0]<<" "<<Wierz[1]<<" "<<Wierz[2]<<endl;
      Plik_BrylaWzorcowa >> Wierz[0] >> Wierz[1] >> Wierz[2];  
      
      assert(IloscWierzcholkow == ILOSC_WIERZ_LINII_TWORZACEJ-1 || !Plik_BrylaWynikowa.fail());
    }
    Plik_BrylaWynikowa <<  endl;
  }
  return !Plik_BrylaWynikowa.fail();
}

bool Dron::Oblicz_i_Zapisz_WspGlbRotora(Graniastoslup6 &Rotor)
{
  ifstream Plik_BrylaWzorcowa(Rotor.WezNazwePliku_BrylaWzorcowa());
  ofstream Plik_BrylaWynikowa(Rotor.WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;

  if (!Plik_BrylaWzorcowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << Rotor.WezNazwePliku_BrylaWzorcowa() << endl << endl;
    return false;
  }
  
  if (!Plik_BrylaWynikowa.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << Rotor.WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_BrylaWzorcowa.good());
  assert(Plik_BrylaWynikowa.good());  
  Plik_BrylaWzorcowa >> Wierz;
  while (!Plik_BrylaWzorcowa.fail()) {
      
    for(unsigned int IloscWierzcholkow = 0; IloscWierzcholkow < ILOSC_WIERZ_LINII_TWORZACEJ;
      ++IloscWierzcholkow) {

      Wierz = Rotor.Skaluj(Wierz);
      /* if (fabs(Polozenie[2]-WYSOKOSC)<EPSILON))
        Wierz = TransformataZ(KatOrientacji_stopnie) * Wierz; */
      Wierz = Rotor.TransfDoUklWspRodzica(Wierz);
      Wierz = this->TransfDoUklWspRodzica(Wierz);

      Plik_BrylaWynikowa <<Wierz[0]<<" "<<Wierz[1]<<" "<<Wierz[2]<<endl;
      Plik_BrylaWzorcowa >> Wierz[0] >> Wierz[1] >> Wierz[2];  
      
      assert(IloscWierzcholkow == ILOSC_WIERZ_LINII_TWORZACEJ-1 || !Plik_BrylaWynikowa.fail());
    }
    Plik_BrylaWynikowa <<  endl;
  }
  return !Plik_BrylaWynikowa.fail();
}

Wektor3D Dron::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
  return Polozenie + Wsp;
}

void Dron::PlanujPoczatkowaSciezke(double KatSkretu_stopnie,
                                   double DlugoscLotu,
                                   vector<Wektor3D> &PunktySciezki)
{
  Wektor3D temp_wek = Polozenie;
  KatSkretu_stopnie += KatOrientacji_stopnie;
  KatOrientacji_stopnie = KatSkretu_stopnie;

  double temp_kat;
  ofstream  StrWy(PLIK_TRASY_PRZELOTU);

  if (PunktySciezki.size() > 1) 
    for (Wektor3D x : PunktySciezki) PunktySciezki.pop_back();

  if (!StrWy.is_open()) {
    cerr << endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
	 << endl;
    exit(0);
  }

  PunktySciezki.push_back(temp_wek);
  temp_wek[2] = WYSOKOSC;
  PunktySciezki.push_back(temp_wek);
  temp_kat = StopnieNaRad(KatSkretu_stopnie);
  temp_wek[0] += sin(temp_kat) * DlugoscLotu;
  temp_wek[1] += cos(temp_kat) * DlugoscLotu;
  PunktySciezki.push_back(temp_wek);
  temp_wek[2] = Polozenie[2];
  PunktySciezki.push_back(temp_wek);
  
  for (uint i=0;i<PunktySciezki.size();++i)
    StrWy << PunktySciezki[i] << endl;
}

bool Dron::WykonajPionowyLot(vector<Wektor3D> &PunktySciezki,PzG::LaczeDoGNUPlota &Lacze)
{
  if (Polozenie[2]==0) {
    cout << endl << "Wznoszenie ... " << endl;
    for (; Polozenie[2] <= PunktySciezki[2][2]-2; Polozenie[2]+=PREDKOSC) {
      if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    }
  }
  else {
    cout << endl << "Opadanie ... " << endl;
    for (; Polozenie[2] >= PunktySciezki[4][2]; Polozenie[2]-=PREDKOSC) {
      if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    }
    cout << "Ladowanie zakonczone." << endl;
  }
  return true;
}

bool Dron::WykonajPoziomyLot(vector<Wektor3D> &PunktySciezki,PzG::LaczeDoGNUPlota &Lacze)
{
  Wektor3D wspolczynniki = ObliczFunkcje(Polozenie,PunktySciezki[3]);
  double temp1 = PREDKOSC;
  double temp2 = PREDKOSC;

  if (Polozenie[0]>PunktySciezki[3][0]) temp1 *= -1;
  if (Polozenie[1]>PunktySciezki[3][1]) temp2 *= -1;

  cout << endl << "Lot przed siebie ... " << endl;
  
  if(SprKtoreWieksze(Polozenie[1],PunktySciezki[3][1])){
    do {
      Polozenie[0]+=temp1;
      if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    } while (!SprKtoreWieksze(Polozenie[0],PunktySciezki[3][0]));
  }

  if(SprKtoreWieksze(Polozenie[0],PunktySciezki[3][0])){
    do {
      Polozenie[1]+=temp2;
      if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    } while (!SprKtoreWieksze(Polozenie[1],PunktySciezki[3][1]));
  }

  if(!SprKtoreWieksze(Polozenie[1],PunktySciezki[3][1])){
    do {
      Polozenie[1]+=temp2;
      Polozenie[0] = (Polozenie[1] - wspolczynniki[1]) / wspolczynniki[0];
      if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();
    } while (!SprKtoreWieksze(Polozenie[1],PunktySciezki[3][1]));
  }

  if(!SprKtoreWieksze(Polozenie[0],PunktySciezki[3][0])){
    do {
    Polozenie[0]+=temp1;
    Polozenie[1] = wspolczynniki[0] * Polozenie[0] + wspolczynniki[1];
    if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
    } while (!SprKtoreWieksze(Polozenie[0],PunktySciezki[3][0]));
  }
  return true;
}

bool Dron::WykonajObrot(double KatSkretu_stopnie,PzG::LaczeDoGNUPlota &Lacze)
{
  KatOrientacji_stopnie = 5;

  cout << endl << "Dokonuje obrotu ... " << endl;
  for (;KatOrientacji_stopnie <= KatSkretu_stopnie; KatOrientacji_stopnie += 5) {
    if(!this->Oblicz_i_Zapisz_WspGlbDrona()) return false;
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }
  return true; 
}

bool Dron::WykonajPrzemieszczenie(double KatSkretu_stopnie,
                                  double DlugoscLotu,
                                  vector<Wektor3D> &PunktySciezki,
                                  PzG::LaczeDoGNUPlota &Lacze)
{
  this->PlanujPoczatkowaSciezke(KatSkretu_stopnie,DlugoscLotu,PunktySciezki);
  Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);

  cout << "Kliknij ENTER, aby wyznaczyc trase przelotu...";
  cin.ignore(10000,'\n');
  cin.ignore(10000,'\n');
  Lacze.Rysuj();
  
  cout << "Kliknij ENTER, aby rozpoczac lot...";
  cin.ignore(10000,'\n');
  if(!(this->WykonajPionowyLot(PunktySciezki,Lacze))) return false;
  if(!(this->WykonajPoziomyLot(PunktySciezki,Lacze))) return false;
  if(!(this->WykonajPionowyLot(PunktySciezki,Lacze))) return false;
  
  cout << "Kliknij ENTER, aby usunac trase przelotu...";
  cin.ignore(10000,'\n');
  Lacze.UsunNazwePliku(PLIK_TRASY_PRZELOTU);
  Lacze.Rysuj();

  return true;
}

bool Dron::Oblicz_i_Zapisz_WspGlbDrona()
{
  if(!(this->Oblicz_i_Zapisz_WspGlbKorpusu())) return false;
  for (int i=0; i<4; i++)
    if(!this->Oblicz_i_Zapisz_WspGlbRotora(RotorDrona[i])) return false;
  return true;
}




