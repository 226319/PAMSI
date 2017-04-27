#ifndef _TOM_HH
#define _TOM_HH

#include "Wyraz.hh"


class Tom {

	Wyraz* ListaWyrazow;


	public:

	const Wyraz& ZnajdzWyraz( const Klucz& ) const;
	Wyraz& ZnajdzWyraz( const Klucz&);



};


#endif
