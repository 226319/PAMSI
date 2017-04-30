#ifndef _DICT_ELEM_HH
#define _DICT_ELEM_HH

#include "Node.hh"
#include "Word.hh"


class DictionaryElement: public Node {

	DictionaryElement* NextElement;
	Word Term; 


	public:

	DictionaryElement();
	//DictionaryElement(const DictionaryElement& );
	
	virtual ~DictionaryElement();
	

	const DictionaryElement* const getNext() const;
	void setNext( DictionaryElement* );

	const Word& getWord() const;
	Word& setWord();

};



#endif
