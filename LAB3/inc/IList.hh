#ifndef ILIST_HH
#define ILIST_HH

#include "TypeDefs.hh"


class IList {


	public:
		
		virtual ~IList() {};
		virtual bool Add(const int&, const unsigned int& )=0;    // jesli sie powiodlo true 
		virtual bool Remove(const unsigned int&)=0;				// jesli sie powiodlo true
		virtual int Get( const unsigned int& ) const =0;
		virtual unsigned int Size() const =0;
		virtual int Find( const int& )=0;

};

#endif
