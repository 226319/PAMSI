#include "DictionaryElement.hh"

//--------------------| Constructors and destructor |----------------------

DictionaryElement::DictionaryElement() {

	NextElement = nullptr;

}

DictionaryElement::~DictionaryElement() {

	if ( NextElement != nullptr ){
		NextElement = nullptr;
	}
		delete NextElement;
}


//------------------------------| End |-------------------------------------


//------------------------| Public Methods |-----------------------------

const DictionaryElement* const DictionaryElement::getNext() const {
	return NextElement;
}

void DictionaryElement::setNext(DictionaryElement* next ) {
	NextElement = next;
}

const Word& DictionaryElement::getWord() const {
	return Term;
}

Word& DictionaryElement::setWord() {
	return Term;
}

//------------------------| Public Methods |---------------------------


