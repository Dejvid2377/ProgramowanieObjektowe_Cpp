#ifndef SCENA_HH
#define SCENA_HH
#include "Dron.hh"
#include "bibloteki.hh"
#include "lacze_do_gnuplota.hh"

class Scena {
  Dron TabDronow[2];
  PzG::LaczeDoGNUPlota Lacze;
    public:
  Scena();
  void RysujScenerie();
  Scena(Dron TabDronow[2],PzG::LaczeDoGNUPlota Lacze);
  const Dron & WezAktywnegoDrona() const;
  Dron & UzyjAktywnegoDrona();
  void PolozenieAktywnegoDrona(const Dron &Apollo) const;
  void UruchomLacze ();
  PzG::LaczeDoGNUPlota& ZwrocLacze () { return this->Lacze;}
  void DodajPlik (const char* Plik);
};

#endif