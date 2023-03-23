#ifndef LICZBA_HH
#define LICZBA_HH
#include <cmath>

using namespace std;

class LZespolona {
    public:
        LZespolona() { re=0.0; im=0.0; }
        LZespolona (double re, double im);
        bool Wczytaj (LZespolona &L1);
        void WyswietlLiczbe(LZespolona L1) { cout << L1 <<endl; }
        double Modul() { return sqrt(re*re+im*im); }
        LZespolona Sprzezenie() { return {re,-im}; }
        LZespolona operator+(const LZespolona &L1);
        LZespolona operator-(const LZespolona &L1);
        LZespolona operator*(const LZespolona &L1);
        LZespolona operator/(LZespolona &L1);
        const LZespolona operator=(const LZespolona &L1); 
        bool operator==(const LZespolona &L1);
        bool operator!=(const LZespolona &L1);
        friend ostream & operator << (ostream & StrmWy, LZespolona L1);
        friend istream & operator >> (istream & StrWej, LZespolona &L1);
    private:
        double re, im;
};

#endif
