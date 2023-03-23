#include <iostream>
#include <iomanip>
#include <cmath>
#include "LZespolona.hh"
#define EPSILON __DBL_EPSILON__
using namespace std;

LZespolona::LZespolona(double re, double im)
  :re(re), im(im)
{

}

bool LZespolona::Wczytaj(LZespolona &L1)
{
  if (cin >> L1)
    return true;
  else  {
    cerr << "\n  Blad zapisu liczby zespolonej. ";
    cin.clear();
    cin.ignore(100,'\n');
    return false;
  }
}

LZespolona LZespolona::operator+(const LZespolona &L1)
{ 
  return {re + L1.re, im + L1.im};
}

LZespolona LZespolona::operator-(const LZespolona &L1)
{
  return {re - L1.re, im - L1.im};
}

LZespolona LZespolona::operator*(const LZespolona &L1)
{
  return {(re * L1.re) - (im * L1.im) , (L1.re * im) + (L1.im * re)};
}


LZespolona LZespolona::operator/(LZespolona &L1)
{
  LZespolona wynik;
  double modul { L1.Modul() };
  if (modul==0) {
    cerr << "Nie mozna dzielic przez 0!" << endl;
    exit(0);
  }
  else {
    wynik.re = (L1.re * re) + (im * L1.im);
    wynik.re /= (modul*modul);
    wynik.im = (im * L1.re) - (re * L1.im); 
    wynik.im /= (modul*modul);
  }
  return wynik;
}

const LZespolona LZespolona::operator=(const LZespolona &L1)
{
  return { re = L1.re, im = L1.im };
}

bool LZespolona::operator==(const LZespolona &L1)
{
  if ((fabs(re-L1.re)<EPSILON) && (fabs(im-L1.im)<EPSILON))
    return true;
  else
    return false;
}

bool LZespolona::operator!=(const LZespolona &L1)
{
  if ((fabs(re-L1.re)>EPSILON) && (fabs(im-L1.im)>EPSILON))
    return true;
  else
    return false;
}

istream & operator >> (istream & StrWej, LZespolona &L1)
{
    char znak;
    StrWej >> znak;
    if (znak!='(') {
      StrWej.setstate(ios::failbit);
      return StrWej; }
      
    StrWej >> setw(1) >> L1.re;
    StrWej >> setw(1) >> L1.im;

    StrWej >> znak;
    if (znak!='i') {
      StrWej.setstate(ios::failbit);
      return StrWej; }
    
    StrWej >> znak;
    if (znak!=')') {
      StrWej.setstate(ios::failbit);
      return StrWej; }

    return StrWej;
}

ostream & operator << (ostream & StrmWy, LZespolona L1)
{
    return StrmWy << "(" << L1.re << std::showpos << L1.im << std::noshowpos << 'i' <<")";
}

void error (string s){
    throw runtime_error(s);
}