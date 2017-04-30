#ifndef _SLOWNIK_HH
#define _SLOWNIK_HH

#include "TablicaAsocjacyjna.hh"

typedef std::string Haslo;


class Slownik: public TablicaAsocjacyjna {

	Tom* ListaTomow;


	Tom& ZnajdzTom( const& Haslo );


	public:

	const Definicja& operator[]( const& Haslo) const;
	Definicja& operator[]( const& Haslo);


}






#endif
