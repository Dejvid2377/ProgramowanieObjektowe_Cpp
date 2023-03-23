#include <GoraOstra.hh>

GoraOstra::GoraOstra()
{ 
  NazwaPliku_BrylaWzorcowa = PLIK_WZORCOWEGO_SZESCIANU;
  NazwaPliku_BrylaFinalna = PLIK_WLASCIWY__GORA2 + this->ZwrocNumerObiektu() + ".dat";
  Polozenie={0,0,0};
  KatOrientacji_stopnie=0;
  nr_obj_gora++;
}

GoraOstra::GoraOstra(Wektor3D Wsp, double kat)
  :Polozenie(Wsp), KatOrientacji_stopnie(kat)
{
    
}

Wektor3D GoraOstra::TransfDoUklWspRodzica(const Wektor3D &Wsp) const
{
  return Polozenie + Wsp; 
}

void GoraOstra::UstalPolozeniePoczatkowe(const Wektor3D &Wsp)
{
  Polozenie = Wsp;
}