#ifndef ILIST_HH
#define ILIST_HH

#include "TypeDefs.hh"


class IList {


	public:
		
		virtual ~IList() {};
		virtual bool Add( Element , Position ) =0;    // jesli sie powiodlo true 
		virtual bool Remove( Position )=0;				// jesli sie powiodlo true
		virtual Element Get( Position ) const =0;
		virtual int Size() const =0;
		virtual Element Find( Element )=0;

};

#endif
