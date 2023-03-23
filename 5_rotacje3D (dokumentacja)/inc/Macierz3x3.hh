#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH
#include "bibloteki.hh"
#include "Macierz.hh"

/*!
 * \brief Klasa Macierz3x3 ma być instancją szablonu Macierz<>
 *
 *  Tutaj trzeba opisac instancję szablonu. Jakie pojecie ona modeluje 
 *  i jakie ma glowne cechy.
 */
typedef Macierz<3>  Macierz3x3;
Macierz3x3 TransformataX (double kat);
Macierz3x3 TransformataY (double kat);
Macierz3x3 TransformataZ (double kat);

#endif