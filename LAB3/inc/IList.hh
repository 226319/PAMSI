#ifndef ILIST_HH
#define ILIST_HH

#include "TypeDefs.hh"


class IList {


	public:
		
		virtual ~IList();
		virtual bool Add( Element , Position );    // jesli sie powiodlo true 
		virtual bool Remove( Position );				// jesli sie powiodlo true
		virtual Element Get( Position ) const;
		virtual int Size() const;
		virtual Element Find( Element );

};

#endif
