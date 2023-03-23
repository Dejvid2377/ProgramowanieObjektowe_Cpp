#include "Wektor2D.hh"

Wektor2D::Wektor2D (double x, double y)
{
    Wek[0] = x;
    Wek[1] = y;
}

Wektor2D Wektor2D::operator+ (const Wektor2D &W) const
{
    return { Wek[0] + W.Wek[0], Wek[1] + W.Wek[1] };
}

Wektor2D Wektor2D::operator- (const Wektor2D &W) const
{
    return { Wek[0] - W.Wek[0], Wek[1] - W.Wek[1] };
}

Wektor2D Wektor2D::operator= (const Wektor2D &W)
{
    return { Wek[0] =  W.Wek[0], Wek[1] = W.Wek[1] };
}

bool Wektor2D::operator== (const Wektor2D &W) const
{
    if ( (fabs(Wek[0]-W.Wek[0]) < EPSILON) && (fabs(Wek[1]-W.Wek[1]) < EPSILON) )
        return true;
    else
        return false;
}

bool Wektor2D::operator!= (const Wektor2D &W) const
{
    if ( (fabs(Wek[0]-W.Wek[0]) > EPSILON) && (fabs(Wek[1]-W.Wek[1]) > EPSILON) )
        return true;
    else
        return false;
}

double Wektor2D::DlugoscWek () const
{
    return { sqrt(Wek[0]*Wek[0]+Wek[1]*Wek[1]) };
}

istream& operator >> (istream &StrWej, Wektor2D &W)
{
    if (!(StrWej>>W.Wek[0])) {
        StrWej.setstate(ios::failbit);
        return StrWej;
    }

    if (!(StrWej>>W.Wek[1])) {
        StrWej.setstate(ios::failbit);
        return StrWej;
    }

    return StrWej;
}

ostream& operator << (ostream &StrWyj, const Wektor2D &W)
{
    return StrWyj <<
          setw(6) << fixed << setprecision(10) << W.Wek[0] 
                  << " " << 
          setw(6) << fixed << setprecision(10)<< W.Wek[1];
}