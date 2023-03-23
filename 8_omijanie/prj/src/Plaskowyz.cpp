#include <Plaskowyz.hh>

Plaskowyz::Plaskowyz()
{ 
  NazwaPliku_BrylaWzorcowa = PLIK_WZORCOWEGO_SZESCIANU;
  NazwaPliku_BrylaFinalna = PLIK_WLASCIWY__PLASKOWYZ1 + this->ZwrocNumerObiektu() + ".dat";
  Polozenie={0,0,0};
  KatOrientacji_stopnie=0;
  nr_obj_plaskowyz++;
}

Plaskowyz::Plaskowyz(Wektor3D Wsp, double kat)
  :Polozenie(Wsp), KatOrientacji_stopnie(kat)
{
    nr_obj_plaskowyz++;
}

Wektor3D Plaskowyz::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
  return Polozenie + Wsp; 
}

void Plaskowyz::UstalPolozeniePoczatkowe(const Wektor3D &Wsp)
{
  Polozenie = Wsp;
}

bool Plaskowyz::UstalObrys ()
{
  ifstream Plik_WspWierz(this->WezNazwePliku_BrylaFinalna());
  Wektor3D Wierz;
  double min_x, min_y, max_x, max_y;

  if (!Plik_WspWierz.is_open()) {
    cerr << endl << " Blad otwarcia do odczytu pliku: " 
         << this->WezNazwePliku_BrylaFinalna() << endl << endl;
    return false;
  }

  assert(Plik_WspWierz.good());
  Plik_WspWierz >> Wierz;

  min_x = max_x = Wierz[0];
  min_y = max_y = Wierz[1];
  
  while(!Plik_WspWierz.fail()) {
    if(Wierz[0] > max_x)
      max_x = Wierz[0];  
    if(Wierz[0] < min_x)
      min_x = Wierz[0];
    if(Wierz[1] > max_y)
      max_y = Wierz[1];
    if(Wierz[1] < min_y)
      min_y = Wierz[1];
    
    Plik_WspWierz >> Wierz[0] >> Wierz[1] >> Wierz[2];
  }

  this->WspObrysu.push_back(min_x);
  this->WspObrysu.push_back(max_x);
  this->WspObrysu.push_back(min_y);
  this->WspObrysu.push_back(max_y);
  this->WspObrysu.push_back(1);
  this->WspObrysu.push_back(999);

  return !Plik_WspWierz.fail();
}