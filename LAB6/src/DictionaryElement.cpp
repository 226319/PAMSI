#include "DictionaryElement.hh"

//--------------------| Constructors and destructor |----------------------

DictionaryElement::DictionaryElement() {

	NextElement = nullptr;
	PreviousElement = nullptr;

}

DictionaryElement::~DictionaryElement() {

		NextElement = nullptr;
		PreviousElement = nullptr;
	
}

DictionaryElement::DictionaryElement(DictionaryElement& ElementToCopy ) {
	Term = ElementToCopy.getWord();
	NextElement = ElementToCopy.getNext();
	PreviousElement = ElementToCopy.getPrevious();
}

DictionaryElement& DictionaryElement::operator= (const DictionaryElement& ElementToCopy) {

	if ( &ElementToCopy != this ) {
		Term = ElementToCopy.getWord();
		NextElement = ElementToCopy.getNext();
		PreviousElement = ElementToCopy.getPrevious();
	}
	
	return *this;
}


//------------------------------| End |-------------------------------------


//------------------------| Public Methods |-----------------------------

DictionaryElement* const DictionaryElement::getNext() const {
	return NextElement;
}

void DictionaryElement::setNext(DictionaryElement* anotherElement ) {
	NextElement =  anotherElement;
}

const Word& DictionaryElement::getWord() const {
	return Term;
}

Word& DictionaryElement::setWord() {
	return Term;
}

DictionaryElement* const DictionaryElement::getPrevious() const {
	return PreviousElement;
}

void DictionaryElement::setPrevious(DictionaryElement* anotherElement ) {
	PreviousElement = anotherElement;
}


//----------------------------------| End |---------------------------

std::ostream& operator<< ( std::ostream& stream, const DictionaryElement& Elem ) {

		stream << Elem.getWord();

}




