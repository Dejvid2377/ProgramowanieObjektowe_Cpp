#include "Scena.hh"

Scena::Scena()
{

}
Scena::Scena(Prostopadloscian Figura, Macierz3x3 MacObrotu)
    :Figura(Figura), MacObrotu(MacObrotu)
{

}
Scena Scena::operator=(const Scena &Sc)
{
   Figura    = Sc.Figura;
   MacObrotu = Sc.MacObrotu;
   return *this;
}

Scena Scena::WczytajSekwencje()
{
    Macierz3x3 M_temp;
    char znak;
    double kat;
    int poczatek = 1;
    int reset = 0;

    cout << "Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach" << endl;
    
    do {
      cin >> znak;
      switch (znak) {
         case 'x': if (cin >> kat) {
                     M_temp = TransformataX(kat);
                   }       
                   else {
                     cerr << "Niewlasciwa wartosc kata" << endl;
                     cin.clear();
                     cin.ignore(100000,'\n');
                   }
                   break;
         case 'y': if (cin >> kat) {
                     M_temp = TransformataY(kat);
                   }
                   else {
                     cerr << "Niewlasciwa wartosc kata" << endl;
                     cin.clear();
                     cin.ignore(100000,'\n');
                   }
                   break;
         case 'z': if (cin >> kat) {
                     M_temp = TransformataZ(kat);
                   }
                   else {
                     cerr << "Niewlasciwa wartosc kata" << endl;
                     cin.clear();
                     cin.ignore(100000,'\n');
                   }
                   break;
         case '.': reset = 1;
                   break;
         default : cout << " :( Bledne oznaczenie osi. Dopuszczalne znaki to: x y z .\n";
                   cout << " :( Sprobuj jeszcze raz.\n\n";
                   reset = 1;
                   poczatek = 1;
                   break;

        }
      if (!reset) {
        if (poczatek) {
          MacObrotu = M_temp;
          poczatek = 0;
        }
        else
          MacObrotu = M_temp * MacObrotu;
      } 
      else
        reset = 0;   
    } while (znak != '.');
    return *this;
}

Prostopadloscian Scena::ObrocFigure (const Scena &Sc, int liczba)
{
  for (int j=0; j<liczba; j++) {
    for (int i=0; i<8; i++)
        Figura[i] = Sc.MacObrotu * Sc.Figura[i];
  }  
  return Figura;
}

Macierz3x3 Scena::ZwrocMacierz (const Scena &Sc)
{
    return MacObrotu;
}

Prostopadloscian Scena::ZwrocFigure (const Scena &Sc)
{
    return Figura;
}