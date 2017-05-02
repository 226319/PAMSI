#ifndef _VOLUME_HH
#define _VOLUME_HH

#include "DictionaryElement.hh"
#include "List.hh"

typedef unsigned int WordCounter;

class Volume: public List {

	DictionaryElement* FirstWord;
	DictionaryElement* LastWord;
	WordCounter NumberOfWords;
	
	
	public:

	Volume();
	Volume(const Volume&);
	Volume& operator=(const Volume&);

	virtual ~Volume();
	
	void Append( const Word& );
	void Remove( const WatchWord& );

	const DictionaryElement& getElement( const WatchWord& ) const;
	DictionaryElement& setElement( const WatchWord&);




};


#endif
