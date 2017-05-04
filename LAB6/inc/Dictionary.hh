#ifndef _Dictionary_HH
#define _Dictionary_HH

#include "HashTable.hh"
#include "List.hh"

typedef std::string Haslo;


class Slownik: public TablicaAsocjacyjna, private List {

	Tom* ListaTomow;


	Tom& ZnajdzTom( const& Haslo );


	public:

	const Definicja& operator[]( const& Haslo) const;
	Definicja& operator[]( const& Haslo);


}






#endif
