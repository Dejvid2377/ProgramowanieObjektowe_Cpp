#ifndef BIBLOTEKA_HH
#define BIBLOTEKA_HH

#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <stdlib.h>
#include <cassert>
#include <cmath>
#include <list>
#include <iterator>
#include <unistd.h>
#include <vector>
#include <initializer_list>
using namespace std;
#define ROZMIAR 3
#define PI 3.14
#define EPSILON __DBL_EPSILON__

#define SKALA_ROTORA {8,8,2}
#define SKALA_KORPUSU {10,8,4}
#define TRANSLACJA_ROTOR_LEWY_PRZEDNI   {5,4,5}
#define TRANSLACJA_ROTOR_PRAWY_PRZEDNI  {5,-4,5}
#define TRANSLACJA_ROTOR_LEWY_TYLNY    {-5,4,5}
#define TRANSLACJA_ROTOR_PRAWY_TYLNY   {-5,-4,5} 
#define SKALA_JEDNOSTKOWA  {1,1,1}
#define ILOSC_WIERZ_LINII_TWORZACEJ   4
#define SKOK_OBROTU_ROTOROW_stopnie  10
#define PREDKOSC 1
#define WYSOKOSC 80

#define PLIK_WZORCOWEGO_SZESCIANU       "bryly_wzorcowe/szescian.dat"
#define PLIK_WZORCOWEGO_GRANIASTOSLUPA6 "bryly_wzorcowe/graniastoslup6.dat"
#define PLIK_ROBOCZY__DRON1_KORPUS  "dat/PlikRoboczy_Dron1_Korpus.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR1  "dat/PlikRoboczy_Dron1_Rotor1.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR2  "dat/PlikRoboczy_Dron1_Rotor2.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR3  "dat/PlikRoboczy_Dron1_Rotor3.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR4  "dat/PlikRoboczy_Dron1_Rotor4.dat"
#define PLIK_ROBOCZY__DRON2_KORPUS  "dat/PlikRoboczy_Dron2_Korpus.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR1  "dat/PlikRoboczy_Dron2_Rotor1.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR2  "dat/PlikRoboczy_Dron2_Rotor2.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR3  "dat/PlikRoboczy_Dron2_Rotor3.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR4  "dat/PlikRoboczy_Dron2_Rotor4.dat"
#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"
#define PLIK_TRASY_PRZELOTU "dat/trasa_przelotu.dat"

#define PLIK_WZORCOWY_KLIF "bryly_wzorcowe/gora_z_dluga_grania.dat"
#define PLIK_WZORCOWY_GORA "bryly_wzorcowe/gora_z_ostrym_szczytem.dat"
#define PLIK_WLASCIWY__GORA1 "dat/klif_"
#define PLIK_WLASCIWY__GORA2 "dat/gora_ostra_"
#define PLIK_WLASCIWY__PLASKOWYZ1 "dat/plaskowyz_"


#endif