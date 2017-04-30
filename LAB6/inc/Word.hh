#ifndef _WORD_HH
#define _WORD_HH

#include "Element.hh"
#include <iostream>



class Word : public Element {

	WatchWord Name;
	Definition Meaning;

	public: 

	Word();
	~Word();

	const Definition getDefinition() const;
	Definition& setDefinition();

	const WatchWord& getWatchWord() const;
	WatchWord& setWatchWord();

};



#endif
