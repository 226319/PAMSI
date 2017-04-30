#ifndef _TABLICA_ASOC_HH
#define _TABLICA_ASOC_HH

#include "List.hh"
#include "Element.hh"

class HashArray {



	public:

	virtual Definition& operator[] ( const WatchWord& );
	virtual const Definition& operator[] ( const WatchWord&) const;


}





#endif
