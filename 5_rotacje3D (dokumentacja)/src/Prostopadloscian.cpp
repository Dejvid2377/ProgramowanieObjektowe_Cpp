#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian()
{
  for (Wektor3D &Wierz_i : Wierzcholki)  Wierz_i = {0,0,0}; 
}


Prostopadloscian::Prostopadloscian(const std::initializer_list<Wektor3D> &rListaWierz):
                 Prostopadloscian() // Wywolujac ten konstruktor rowniez nie musimy podawac parametrow szablonu.
		          // Domyslnie jest to rozumiane jako: Macierz<T_Rozmiar>()
{
  assert(rListaWierz.size() <= 8);
  int Ind = -1;
  for (Wektor3D Wierz_val : rListaWierz) Wierzcholki[++Ind] = Wierz_val;
}

Prostopadloscian Prostopadloscian::operator=(const Prostopadloscian &Pr)
{
  for (int i=0; i<8; i++)
    Wierzcholki[i] = Pr[i];
  return *this;
}

Prostopadloscian Prostopadloscian::Translacja(const Wektor3D &W1)
{
  for (int i=0; i < 8; i++)
    Wierzcholki[i] = Wierzcholki[i] + W1;
  return *this;
}

void Prostopadloscian::SprDlugosc () const
{
    Wektor3D krotki_1, krotki_2, krotki_3, krotki_4;
    Wektor3D dlugi_1, dlugi_2, dlugi_3, dlugi_4;
    Wektor3D poprz_1, poprz_2, poprz_3, poprz_4;
    Wektor3D temp1 = Wierzcholki[0] - Wierzcholki[1];
    Wektor3D temp2 = Wierzcholki[0] - Wierzcholki[2];
    
    if (temp1.DlugoscWek() < temp2.DlugoscWek())
    {
        krotki_1 = Wierzcholki[0] - Wierzcholki[1];
        krotki_2 = Wierzcholki[2] - Wierzcholki[3];
        krotki_3 = Wierzcholki[6] - Wierzcholki[7];
        krotki_4 = Wierzcholki[4] - Wierzcholki[5];
        dlugi_1  = Wierzcholki[0] - Wierzcholki[2];
        dlugi_2  = Wierzcholki[1] - Wierzcholki[3];
        dlugi_3  = Wierzcholki[4] - Wierzcholki[6];
        dlugi_4  = Wierzcholki[5] - Wierzcholki[7];
        poprz_1  = Wierzcholki[1] - Wierzcholki[7];
        poprz_2  = Wierzcholki[3] - Wierzcholki[5];
        poprz_3  = Wierzcholki[2] - Wierzcholki[4];
        poprz_4  = Wierzcholki[0] - Wierzcholki[6]; 
    }
    else  {       
        dlugi_1  = Wierzcholki[0] - Wierzcholki[1];
        dlugi_2  = Wierzcholki[2] - Wierzcholki[3];
        dlugi_3  = Wierzcholki[6] - Wierzcholki[7];
        dlugi_4  = Wierzcholki[4] - Wierzcholki[5];
        krotki_1 = Wierzcholki[0] - Wierzcholki[2];
        krotki_2 = Wierzcholki[1] - Wierzcholki[3];
        krotki_3 = Wierzcholki[4] - Wierzcholki[6];
        krotki_4 = Wierzcholki[5] - Wierzcholki[7];
        poprz_1  = Wierzcholki[1] - Wierzcholki[7];
        poprz_2  = Wierzcholki[3] - Wierzcholki[5];
        poprz_3  = Wierzcholki[2] - Wierzcholki[4];
        poprz_4  = Wierzcholki[0] - Wierzcholki[6];  
    }

    if (Porownaj(dlugi_1.DlugoscWek(),dlugi_2.DlugoscWek(),dlugi_3.DlugoscWek(),dlugi_4.DlugoscWek()))
    {
        cout << ":) Dluzsze przeciwlegle boki sa sobie rowne.\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_4.DlugoscWek() << endl;
    }
    else
    {
        cout << ":O Dluzsze przeciwlegle boki nie sa sobie rowne!!!\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_4.DlugoscWek() << endl;
    }

    cout <<  endl;

    if (Porownaj(krotki_1.DlugoscWek(),krotki_2.DlugoscWek(),krotki_3.DlugoscWek(),krotki_4.DlugoscWek()))
    {
        cout << ":) Krotsze przeciwlegle boki sa sobie rowne.\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_4.DlugoscWek() << endl;
    }
    else
    {
        cout << ":O Krotsze przeciwlegle boki nie sa sobie rowne!!!\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_4.DlugoscWek() << endl;
    }
    
    cout << endl;

    if (Porownaj(poprz_1.DlugoscWek(),poprz_2.DlugoscWek(),poprz_3.DlugoscWek(),poprz_4.DlugoscWek()))
    {
        cout << ":) Poprzeczne przeciwlegle boki sa sobie rowne.\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_4.DlugoscWek() << endl;
    }
    else
    {
        cout << ":O Poprzeczne przeciwlegle boki nie sa sobie rowne!!!\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_2.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_3.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << poprz_4.DlugoscWek() << endl;
    }
}

std::ostream& operator << (ostream &StrWyj,const Prostopadloscian &Pr)
{
  for (int i=0; i<8; i++)
      StrWyj << Pr[i] << endl;
  return StrWyj;
}

bool Porownaj (double v1, double v2, double v3, double v4)
{
    if ((v1 == v2) && (v1==v3) && (v1==v4)) {
      if ((v2 == v3) && (v2==v4)) {
        if (v3 == v4)
          return true;
      }
    }
    else return false;

    return false;
}

