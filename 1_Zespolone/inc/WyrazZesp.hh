#ifndef WYRAZENIE_HH
#define WYRAZENIE_HH
#include "LZespolona.hh"
#include <cmath>
using namespace std;

enum Operator { Op_Dodaj=0, Op_Odejmij, Op_Mnoz, Op_Dziel };

class WyrazZespol {
    public:
        WyrazZespol() { Arg1={0,0}; Arg2={0,0}; op=Op_Dodaj; }
        WyrazZespol(LZespolona Arg1, LZespolona Arg2, Operator op);
        bool WczytajWyraz (WyrazZespol &W1);
        void WyswietlWyraz(WyrazZespol W1) { cout << W1 << endl; }
        LZespolona ObliczWyraz (WyrazZespol W1);
        friend istream & operator >> (istream & StrWej, WyrazZespol &W1);
        friend ostream & operator << (ostream & StrmWy, WyrazZespol W1);
        friend istream & operator >> (istream & StrWej, Operator &op);
        friend ostream & operator << (ostream & StrWyj, Operator op);
    private:
        LZespolona Arg1, Arg2;
        Operator op;
};


#endif