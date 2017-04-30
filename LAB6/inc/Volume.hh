#ifndef _VOLUME_HH
#define _VOLUME_HH

#include "DictionaryElement.hh"


class Volume {

	DictionaryElement* FirstWord;
	DictionaryElement* LastWord;



	public:
	
				
	const DictionaryElement& getWord( const Key& ) const;
	DictionaryElement& setWord( const Key&);

	DictionaryElement& FindWord( const Key& );



};


#endif
