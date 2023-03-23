#include <Klif.hh>

Klif::Klif()
{ 
  NazwaPliku_BrylaWzorcowa = PLIK_WZORCOWEGO_SZESCIANU;
  NazwaPliku_BrylaFinalna = PLIK_WLASCIWY__GORA1 + this->ZwrocNumerObiektu() + ".dat";
  Polozenie={0,0,0};
  KatOrientacji_stopnie=0;
  nr_obj_klif++;
}

Klif::Klif(Wektor3D Wsp, double kat)
  :Polozenie(Wsp), KatOrientacji_stopnie(kat)
{
    
}

Wektor3D Klif::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
  return Polozenie + Wsp; 
}

void Klif::UstalPolozeniePoczatkowe(const Wektor3D &Wsp)
{
  Polozenie = Wsp;
}