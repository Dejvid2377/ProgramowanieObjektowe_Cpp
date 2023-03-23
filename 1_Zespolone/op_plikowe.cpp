#include <iostream>
#include <fstream>
#include <cstdlib>
#define ROZ 10
using namespace std;

bool Czy (ifstream &);

int main(int argc, char *argv[])
{
 if (argc < 2) {
    cout << "Brak danych wejsciowych programu." << endl;
    cout << endl;
    return 1;
  }
ifstream Otwieracz(argv[1], ios::in);
if (Czy(Otwieracz)==true)
{
    cout<<"plik otworzono poprawnie!"<<endl;
}
else
{
    cout<<"nie udalo sie otworzyc pliku"<<endl;
    exit(0);
};
int znak;
    int i=0;
    int *tab=new int[ROZ];
    while (Otwieracz>>znak)
    {
        tab[i]=znak;
        cout<<znak<<" ";
        i++;
    }
Otwieracz.close();
cout<<"bedzie cos napisane czy nie?"<<endl;
return 0;
}
bool Czy (ifstream &plik)
{
      if (plik.good()){ return true;}
    else{ return false;}
};
/*  FLAGI
    ************************************************************************************************************
    ios::in - INPUT - odczyt
    ios::out - OUTPUT - zapis; jesli nie ma pliku - stworz nowy plik; jesli plik jest - usun zawartosc
    ios::trunc - TRUNCATE -ucinanie, wymazywanie zawartosci
    ios::ate - AT THE END - ustaw poczatkowa pozycje na koncu pliku (dokladniej modyfikowalny wskaznik), mozna go zmienic, jest mozliwosc czytania i pisania
    ios::app - APPEND - dolacz zawartosc na koncu pliku
    ios::binary - tryb binarny (np. przy obsludze zdjec)
    *************************************************************************************************************
    funkcje .IS.OPEN i .GOOD są funkcjami typu BOOL ktore wykorzystujemy do sprawdzenia poprawnosci uchwytu pliku
    *************************************************************************************************************
    FLAGI BLEDOW STRUMIENI (i ich reprezentacja w pamieci)
    *************************************************************************************************************
    bad() - BADBIT(1) - zwraca TRUE jesli powstanie blad typu "zapisywania do pliku ktory byl jedynie do odczytu"
    fail() - FAILBIT(4) - zwraca TRUE jesli typy zmiennych nie beda sie zgadzac (np. przy probie zapisu string jako int) lub w przypadkach takich jak w BAD
    good() - GOODBIT(0) - zwraca TRUE gdy wszystko jest w porzadku
    eof() - EOFBIT(2) - zwraca TRUE jezeli otwarty plik do odczytu osiagnie koniec (zostal przeczytany)
    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    rdstate() - READ STATE - przeczytaj stan:
    kazdy z powyzszych "stanow" reprezentuje pewna wartosc (podana w nawiasie) ktora moze zostac przedstawiona jako:
    000 - 0
    001 - 1     Aby dostac informacje zwrotna jakie flagi zostaly wywolane w naszym programie mozemy odczytac wartosc
    010 - 2     stanu laczac wybrane flagi operatorami logicznymi | , &  lub
    100 - 4     ^ (tzw XOR  - roznica arytmetyczna 01 lub 10 daje TRUE)
    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
    if((file.rdstate() ^ ifstream::eofbit) == 0)  porownanie stanu z tym co zaplanowalismy zrobic
        file.clear();                             otrzymamy FALSE jezeli wartosc stanu bedzie rowna tej z naszych zalozen */
