#include "Element.hh"


//-----------------------| Constructors and Destructor |-------------------------

Element::Element() {

	PositionNumber = 0;
	ElementContent = "No Content";


}


Element::Element( const Key& NewPosNum, const Content& NewContent ) {

	PositionNumber = NewPosNum;
	ElementContent = NewContent;

}




Element::~Element() {}


//-----------------------------------| End |-----------------------------------



//-----------------------------| Public Methods |---------------------------------


const Key& Element::getKey() const {
	return PositionNumber;
}

Key& Element::setKey() {
	return PositionNumber;
}

const Content& Element::getContent() const {
	return ElementContent;
}

Content& Element::setContent() {
	return ElementContent;
}










