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

void Prostopadloscian::SprDlugosc (Prostopadloscian &Pr) const
{
    Wektor3D krotki_1, krotki_2, krotki_3, krotki_4;
    Wektor3D dlugi_1, dlugi_2, dlugi_3, dlugi_4;
    Wektor3D poprz_1, poprz_2, poprz_3, poprz_4;
    Wektor3D temp1 = Pr[0] - Pr[1];
    Wektor3D temp2 = Pr[0] - Pr[2];
    
    if (temp1.DlugoscWek() < temp2.DlugoscWek())
    {
        krotki_1 = Pr[0] - Pr[1];
        krotki_2 = Pr[2] - Pr[3];
        krotki_3 = Pr[6] - Pr[7];
        krotki_4 = Pr[4] - Pr[5];
        dlugi_1  = Pr[0] - Pr[2];
        dlugi_2  = Pr[1] - Pr[3];
        dlugi_3  = Pr[4] - Pr[6];
        dlugi_4  = Pr[5] - Pr[7];
        poprz_1  = Pr[1] - Pr[7];
        poprz_2  = Pr[3] - Pr[5];
        poprz_3  = Pr[2] - Pr[4];
        poprz_4  = Pr[0] - Pr[6]; 
    }
    else  {       
        dlugi_1  = Pr[0] - Pr[1];
        dlugi_2  = Pr[2] - Pr[3];
        dlugi_3  = Pr[6] - Pr[7];
        dlugi_4  = Pr[4] - Pr[5];
        krotki_1 = Pr[0] - Pr[2];
        krotki_2 = Pr[1] - Pr[3];
        krotki_3 = Pr[4] - Pr[6];
        krotki_4 = Pr[5] - Pr[7];
        poprz_1  = Pr[1] - Pr[7];
        poprz_2  = Pr[3] - Pr[5];
        poprz_3  = Pr[2] - Pr[4];
        poprz_4  = Pr[0] - Pr[6]; 
    }

    if (((dlugi_1.DlugoscWek() == dlugi_2.DlugoscWek()) == dlugi_3.DlugoscWek()) == dlugi_4.DlugoscWek())
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

    if (((krotki_1.DlugoscWek() == krotki_2.DlugoscWek()) == krotki_3.DlugoscWek()) == krotki_4.DlugoscWek())
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

    if (((poprz_1.DlugoscWek() == poprz_2.DlugoscWek()) == poprz_3.DlugoscWek()) == poprz_4.DlugoscWek())
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
