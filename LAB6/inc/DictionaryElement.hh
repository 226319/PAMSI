#ifndef _DICT_ELEM_HH
#define _DICT_ELEM_HH

#include "Node.hh"
#include "Word.hh"
#include <iostream>

class DictionaryElement: public Node {

	DictionaryElement* NextElement;
	DictionaryElement* PreviousElement;
	Word Term; 


	public:

	DictionaryElement();
	DictionaryElement(DictionaryElement& );
	DictionaryElement& operator= (const DictionaryElement&);
	
	virtual ~DictionaryElement();
	

	DictionaryElement* const getNext() const;
	void setNext(DictionaryElement*);

	const Word& getWord() const;
	Word& setWord();

	DictionaryElement* const getPrevious() const;
	void setPrevious(DictionaryElement*);

};




#endif
