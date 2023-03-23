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
