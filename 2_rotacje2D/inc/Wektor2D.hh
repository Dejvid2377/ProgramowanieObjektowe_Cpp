#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH
#include <bibloteki.hh>

class Wektor2D {
    double Wek[ROZMIAR];
  public:
    Wektor2D(): Wek {0,0} {}
    Wektor2D(double x, double y);
    double operator[] (int i) const { return Wek[i]; }
    double& operator[] (int i) { return Wek[i]; }
    Wektor2D operator + (const Wektor2D &W) const;   
    Wektor2D operator - (const Wektor2D &W) const; 
    Wektor2D operator = (const Wektor2D &W); 
    bool operator == (const Wektor2D &W) const; 
    bool operator != (const Wektor2D &W) const;
    double DlugoscWek() const;
    friend istream& operator >> (istream &, Wektor2D &);
    friend ostream& operator << (ostream &, const Wektor2D &);
};

#endif