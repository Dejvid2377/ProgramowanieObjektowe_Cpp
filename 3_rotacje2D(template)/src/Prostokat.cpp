#include "Prostokat.hh"

Prostokat::Prostokat(Wektor2D A, Wektor2D B, Wektor2D C, Wektor2D D)
{
    Wierzcholki[0] = A;
    Wierzcholki[1] = B;
    Wierzcholki[2] = C;
    Wierzcholki[3] = D;
}

Prostokat Prostokat::Translacja (const Wektor2D &W)
{
    for (int i=0; i<4; i++)
      Wierzcholki[i] = Wierzcholki[i] + W;
    return *this;
}

Prostokat Prostokat::Obrot (const Macierz2x2 &Mac)
{
    for (int i=0; i<4; i++)
        Wierzcholki[i] = Mac * Wierzcholki[i];
    return *this;
}

ostream & operator << (ostream& StrWyj, const Prostokat& Pr)
{
    for (int i=0; i<4; i++)
      StrWyj << Pr.Wierzcholki[i] << endl;
    return StrWyj;
}

void Prostokat::SprDlugosc (Prostokat &Pr) const
{
    Wektor2D krotki_1, krotki_2;
    Wektor2D dlugi_1, dlugi_2;
    Wektor2D temp1 = Pr[0] - Pr[1];
    Wektor2D temp2 = Pr[1] - Pr[2];
    
    if (temp1.DlugoscWek() < temp2.DlugoscWek())
    {
        krotki_1 = Pr[0] - Pr[1];
        krotki_2 = Pr[2] - Pr[3];
        dlugi_1  = Pr[1] - Pr[2];
        dlugi_2  = Pr[3] - Pr[0];
    }
    else
    {       
        dlugi_1  = Pr[0] - Pr[1];
        dlugi_2  = Pr[2] - Pr[3];
        krotki_1 = Pr[1] - Pr[2];
        krotki_2 = Pr[3] - Pr[0]; 
    }

    if (dlugi_1.DlugoscWek() == dlugi_2.DlugoscWek())
    {
        cout << ":) Dluzsze przeciwlegle boki sa sobie rowne.\n";
        cout << "Dlugosc pierwszego boku: " << 
            setw(16) << fixed << setprecision(20) << dlugi_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " << 
            setw(16) << fixed << setprecision(20) << dlugi_2.DlugoscWek() << endl;
    }
    else
    {
        cout << ":O Dluzsze przeciwlegle boki nie sa sobie rowne!!!\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << dlugi_2.DlugoscWek() << endl;
    }

    cout <<  endl;

    if (krotki_1.DlugoscWek() == krotki_2.DlugoscWek())
    {
        cout << ":) Krotsze przeciwlegle boki sa sobie rowne.\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_2.DlugoscWek() << endl;
    }
    else
    {
        cout << ":O Krotsze przeciwlegle boki nie sa sobie rowne!!!\n";
        cout << "Dlugosc pierwszego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_1.DlugoscWek() << endl;
        cout << "  Dlugosc drugiego boku: " <<
            setw(16) << fixed << setprecision(20) << krotki_2.DlugoscWek() << endl;
    }
    cout << endl;
}

Prostokat KilkaObrotow (Prostokat &Pr, Macierz2x2 &M)
{
    int liczba;

    if (!(cin>>liczba)) {
        cout << "Nieprawidlowa wartosc liczby\n";
        exit(0);
    }
    else {
        for (int i=0; i<liczba; i++)
            Pr = Pr.Obrot(M);
    }

    return Pr;
}
