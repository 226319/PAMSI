#ifndef _WORD_HH
#define _WORD_HH

#include <iostream>
#include "Element.hh"
#include <string>


class Word : public Element {

	WatchWord Name;
	Definition Meaning;

	public: 

	Word();
	Word(const WatchWord&, const Definition&);
	Word(const Word&);

	~Word();

	const Definition& getDefinition() const;
	Definition& setDefinition();

	const WatchWord& getWatchWord() const;
	WatchWord& setWatchWord();

	bool operator==(const Word&) const;
};

	std::ostream& operator<<( std::ostream& , const Word& );



#endif
