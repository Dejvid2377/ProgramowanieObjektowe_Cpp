#include "Macierz3x3.hh"

Macierz3x3 TransformataZ (double kat)
{
    Macierz3x3 M1;
    kat = kat * PI / 180;
    M1(1,1) = cos(kat);
    M1(1,2) = -sin(kat);
    M1(1,3) = 0;
    M1(2,1) = sin(kat);
    M1(2,2) = cos(kat);
    M1(2,3) = 0;
    M1(3,1) = 0;
    M1(3,2) = 0;
    M1(3,3) = 1;

    return M1;
}

Macierz3x3 TransformataX (double kat)
{   
    Macierz3x3 M1;
    kat = kat * PI / 180;
    M1(1,1) = cos(kat);
    M1(1,2) = 0;
    M1(1,3) = sin(kat);
    M1(2,1) = 0;
    M1(2,2) = 1;
    M1(2,3) = 0;
    M1(3,1) = -sin(kat);
    M1(3,2) = 0;
    M1(3,3) = cos(kat);

    return M1;
}

Macierz3x3 TransformataY (double kat)
{   
    Macierz3x3 M1;
    kat = kat * PI / 180;
    M1(1,1) = 1;
    M1(1,2) = 0;
    M1(1,3) = 0;
    M1(2,1) = 0;
    M1(2,2) = cos(kat);
    M1(2,3) = -sin(kat);
    M1(3,1) = 0;
    M1(3,2) = sin(kat);
    M1(3,3) = cos(kat);

    return M1;
}