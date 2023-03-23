#include <iostream>
#include <cmath>
#include "WyrazZesp.hh"
using namespace std;

WyrazZespol::WyrazZespol(LZespolona Arg1, LZespolona Arg2, Operator op)
    :Arg1(Arg1), Arg2(Arg2), op(op)
{

}

bool WyrazZespol::WczytajWyraz (WyrazZespol &W1)
{
    if (cin >> W1)
        return true;
    else  {
        cout << "Blad zapisu wyrazenia zespolonego.\n";
        return false;
    }
}

LZespolona WyrazZespol::ObliczWyraz (WyrazZespol W1)
{
    LZespolona wynik;
    switch (W1.op) {
        case Op_Dodaj:   wynik = W1.Arg1 + W1.Arg2;
                         break;
        case Op_Odejmij: wynik = W1.Arg1 - W1.Arg2;
                         break;
        case Op_Mnoz:    wynik = W1.Arg1 * W1.Arg2;
                         break;
        case Op_Dziel:   wynik = W1.Arg1 / W1.Arg2;
                         break;
        default:         cout << "Nie mozna obliczyc wyrazenia";
                         break;
    }
    return wynik;
}

istream & operator >> (istream & StrWej, Operator &op)
{
    char znak;
    StrWej >> znak;

    switch (znak)   {
        case '+':   op = Op_Dodaj;
                    break;
        case '-':   op = Op_Odejmij;
                    break;
        case '*':   op = Op_Mnoz;
                    break;
        case '/':   op = Op_Dziel;
                    break;
        default :   cout << "Nieprawidłowy operator.\n";
                    StrWej.setstate(ios::failbit);
                    break;
    }
    return StrWej;
}

ostream & operator << (ostream & StrWyj, Operator op)
{
    char znak;
    switch (op) {
        case Op_Dodaj:    znak = '+';
                          break;
        case Op_Odejmij:  znak = '-';
                          break;
        case Op_Mnoz:     znak = '*';
                          break;
        case Op_Dziel:    znak = '/';
                          break;
    }
    return StrWyj << znak;
}

istream & operator >> (istream & StrWej, WyrazZespol &W1)
{
    StrWej >> W1.Arg1;
    if (!StrWej) {
      StrWej.setstate(ios::failbit);
      return StrWej; }
    
    StrWej >> W1.op;
    if (!StrWej) {
      StrWej.setstate(ios::failbit);
      return StrWej; }
    
    StrWej >> W1.Arg2;
    if (!StrWej) {
      StrWej.setstate(ios::failbit);
      return StrWej; }

    return StrWej;
}

ostream & operator << (ostream & StrmWy, WyrazZespol W1)
{
    return StrmWy << W1.Arg1 << W1.op << W1.Arg2;
}