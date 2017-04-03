#ifndef _TABLICA_HH_
#define _TABLICA_HH_
#include <iostream>
#include "Opcje.hh"

class Tablica {

	private:
		unsigned int _Rozmiar;
		int * _Tablica;

		bool Powieksz( unsigned int ) ;
		bool Pomniejsz( unsigned int ) ;

	public:
		unsigned int& Rozmiar();
		Tablica();
		~Tablica();
		Tablica(unsigned int);
		Tablica& operator=(const Tablica&);
		int OdczytajElement( unsigned int ) const;
		int& ZmienElement( unsigned int );
		const unsigned int& Rozmiar() const;
		bool DodajElement(const unsigned int , const int );
		bool DodajElement2(const unsigned int , const int );

};

#endif 
