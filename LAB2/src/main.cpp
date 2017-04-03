#include <iostream>
#include "Tablica.hh"
#include "Tablica2.hh"
#include "Czasomierz.hh"
#include "Opcje.hh"

int main() {

	Tablica obiekt;
	Czasomierz timer(LICZBA_REALIZACJI);

	for ( int idx = 1; idx <= 3; ++idx ){ 
		timer.ZmierzCzas( obiekt,ROZMIAR_POCZATKOWY, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(std::cout);	
	}

	return 0;
}


