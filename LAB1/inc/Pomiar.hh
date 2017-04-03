#ifndef _POMIAR_HH_
#define _POMIAR_HH_

#include <iostream>
#include <iomanip>
#include "Opcje.hh"

class Pomiar {

	double _wynik[LICZBA_POMIAROW];
	unsigned int _licz_elem;

	public:
	
	double& Wynik( const unsigned int );
	double Wynik( const unsigned int ) const;
	unsigned int& LiczbaElementow();
	unsigned int LiczbaElementow() const;
	double Srednia() const;
	friend std::ostream& operator << (std::ostream & in, const Pomiar& pom );

};

#endif 

