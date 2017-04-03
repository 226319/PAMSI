#ifndef _FUNKCJE_HH_
#define _FUNKCJE_HH_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include "Tablica.hh"
#include "Pomiar.hh"
#include "Opcje.hh"

bool Algorytm(unsigned int);
void Zmierz( const unsigned int, Pomiar &, const unsigned int&);
void Strategia1( Tablica& , const unsigned int& );
void Strategia2( Tablica& , const unsigned int& );

#endif 
