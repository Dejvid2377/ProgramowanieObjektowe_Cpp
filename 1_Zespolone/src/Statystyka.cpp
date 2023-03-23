#include <iostream>
#include "Statystyka.hh"
using namespace std;

Statystyka::Statystyka(double dobre, double zle)
  :dobre(dobre), zle(zle)
{
}

void Statystyka::rezultat()
{
    cout << " Ilosc dobrych odpowiedzi: " << dobre << endl;
    cout << " Ilosc zlych odpowiedzi: " << zle << endl;
    cout << " Wynik procentowy poprawnych odpowiedzi: " <<
       dobre / (dobre + zle) * 100 << "%\n";
}