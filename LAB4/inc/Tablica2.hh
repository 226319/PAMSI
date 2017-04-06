#ifndef _TABLICA2_HH
#define _TABLICA2_HH

#include "Tablica.hh"
#include "Opcje.hh"

class Tablica2 :public Tablica
{
	public:
		Tablica2();
		Tablica2(unsigned int);
		virtual ~Tablica2();
		virtual Tablica2& operator=(const Tablica2&);
		
		virtual bool DodajElement(const unsigned int& , const int& );
		virtual void Testuj(const unsigned int&, const unsigned int&, const int&);


};


#endif
