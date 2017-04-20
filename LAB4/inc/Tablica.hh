#ifndef _TABLICA_HH_
#define _TABLICA_HH_

#include "Opcje.hh"
#include "Testowalny.hh"

class Tablica: public Testowalny
{

	protected:
		unsigned int _Rozmiar;
		int * _Tablica;

		virtual bool Powieksz( unsigned int ) ;
		unsigned int& Rozmiar();

	public:
		
		const unsigned int& Size() const;
		Tablica();
		Tablica(unsigned int);
   	virtual ~Tablica();
		int OdczytajElement( const unsigned int& ) const;
		int& ZmienElement(const unsigned int& );
		const unsigned int& Rozmiar() const;
		virtual Tablica& operator=(const Tablica&);
		virtual bool DodajElement(const unsigned int& , const int& );
		virtual void PrzygotujDoTestu(const unsigned int&, const int&);
		virtual void Testuj(const unsigned int&, const unsigned int&, const int&);

};



#endif 
