#ifndef _HashTable_HH
#define _HashTable_HH

#include "List.hh"
#include "Element.hh"

class HashTable {



	public:

	virtual Definition& operator[] ( const WatchWord& ) = 0;
	virtual const Definition& operator[] ( const WatchWord&) const = 0;


};





#endif
