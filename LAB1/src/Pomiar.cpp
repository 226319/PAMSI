#include "Pomiar.hh"
#include <iostream>

double& Pomiar::Wynik( const unsigned int index ) {
	return _wynik[index];
}

double Pomiar::Wynik( const unsigned int index ) const {
	return _wynik[index];
}

unsigned int& Pomiar::LiczbaElementow() {
	return _licz_elem;
}

unsigned int Pomiar::LiczbaElementow() const {
	return _licz_elem;
}

double Pomiar::Srednia() const {
	double srednia = 0;

	for ( int i = 0 ; i < LICZBA_POMIAROW; ++i ){
		srednia += _wynik[i];
	}

	return srednia/LICZBA_POMIAROW;
}

std::ostream& operator << (std::ostream & in, const Pomiar& pom) {
	
	in << pom.LiczbaElementow() << " ";
	in << std::setprecision(7) << std::fixed;
	in << pom.Srednia() << std::endl;

	return in;
}


