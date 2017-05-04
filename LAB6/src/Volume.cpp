#include "Volume.hh"


//-------------------------| Constructors and destructor |-----------------------


Volume::Volume() {

	FirstWord = nullptr;
	LastWord = nullptr;
	WordCounter = 0;

}

Volume::Volume( const Volume& VolumeToCopy ) {

	for ( unsigned int Idx = 0; Idx < VolumeToCopy.Size(); ++Idx) {
		Append(VolumeToCopy.getWord(Idx));
	}
			
}

Volume& Volume::operator=(const Volume& VolumeToCopy) {

	for ( unsigned int Idx = 0; Idx < VolumeToCopy.Size(); ++Idx) {
		Append(VolumeToCopy.getWord(Idx));
	}

	return *this;
}

Volume::~Volume() {

	if ( isNotEmpty() ) {
		RemoveAllElements();
		setToNull(FirstWord);
		setToNull(LastWord);
	
	
	}
}


//------------------------------------| End |------------------------------------


//--------------------------------| Private Methods |----------------------------

bool Volume::isOneElement() const {

	if ( WordCounter == 1 ) return true;
	else return false;

}

bool Volume::isMoreThanOneElement() const {
	if ( WordCounter > 1 ) return true;
	else return false;
}

bool Volume::isEmpty() const {
	if ( WordCounter ) return false;
	else return true;
}

bool Volume::isNotEmpty() const {
	if ( WordCounter ) return true;
	else return false;
}

bool Volume::isFirstWord() const {
	if ( WordCounter ) return false;
	else return true;
}

bool Volume::isSizeIsGreaterThan( const ElementNumber& IndexOfNumber ) const {
	if ( Size() > IndexOfNumber ) return true;
	else return false;
}

bool Volume::isSearchedElement(DictionaryElement*& Element, const WatchWord& Word ) const {

	return ( Element->getWord().getWatchWord() == Word );

}


void Volume::RemoveAllElements() {

	DictionaryElement* ElementHolder = FirstWord;

	for ( unsigned int Idx = 0; Idx < Size(); ++Idx) {
		DictionaryElement* ElementToRemove;
		
		getElementToRemove(ElementToRemove, ElementHolder);
		GoToTheNext( ElementHolder );
		
		RemoveElement(ElementToRemove);

	}

}

void Volume::RemoveElement( DictionaryElement*& ElementToRemove ) {

	delete ElementToRemove;

}

void Volume::getElementToRemove(DictionaryElement*& ElementToRemove, DictionaryElement*& ElementHolder) {

	ElementToRemove = ElementHolder;
}

void Volume::GoToTheNext(DictionaryElement*& ElementHolder) {
	
	ElementHolder = ElementHolder->getNext();

}

void Volume::AppendFirstWord( const Word& WordToAppend ) {

	DictionaryElement* NewWord = new DictionaryElement;

	NewWord->setWord() = WordToAppend;
	
	FirstWord = NewWord;
	LastWord = NewWord;
	++WordCounter;

}

void Volume::AppendWord( const Word& WordToAppend ) {

	DictionaryElement* NewWord = new DictionaryElement;

	NewWord->setWord() = WordToAppend;
	NewWord->setPrevious(LastWord);
	LastWord->setNext(NewWord); 

	LastWord = NewWord; 
	++WordCounter;

}


DictionaryElement* const Volume::getElement( const ElementNumber& IndexOfElement ) const {


	if ( IndexOfElement == IndexOfLastElement() ) {
		return LastWord;
	
	} else if ( IndexOfElement < HalfOfVolumeSize() ){
		return SearchFromBeginning(IndexOfElement);
	
	} else 
		return SearchFromEnd(IndexOfElement);
	


}

void Volume::setToNull( DictionaryElement*  ElementToSet ) {

	ElementToSet = nullptr;

}
		
DictionaryElement* Volume::SearchFromBeginning(const ElementNumber& IndexOfElement) const { 
		DictionaryElement* SearchedElement = FirstWord;
		
		for ( unsigned int idx = 0; idx < IndexOfElement; ++idx ) {
			SearchedElement = SearchedElement->getNext();
		}

		return SearchedElement;
}


DictionaryElement* Volume::SearchFromEnd(const ElementNumber& IndexOfElement) const { 
	DictionaryElement* SearchedElement = LastWord;
		
	for ( unsigned int idx = IndexOfLastElement(); idx > IndexOfElement; --idx ) {
			SearchedElement = SearchedElement->getPrevious();
	}
	
	return SearchedElement;
}



void Volume::RangeException() const {
	Exception Message = "Range is exceeded\n";
	throw Message;
}

void Volume::NotFoundException() const {
	Exception Message = "Not found\n";
	throw Message;
}


void Volume::PrependFirst( const Word& ToPrepend ) {

	DictionaryElement* newWord = new DictionaryElement;

	newWord->setWord() = ToPrepend;

	FirstWord = newWord;
	LastWord = newWord;

	setToNull(newWord);
	++WordCounter;

}

void Volume::PrependOther( const Word& ToPrepend )  {

	DictionaryElement* newWord = new DictionaryElement;

	newWord->setWord() = ToPrepend;

	newWord->setNext(FirstWord);
	FirstWord->setPrevious(newWord);
	FirstWord = newWord;
	
	setToNull(newWord);
	++WordCounter;
}


//-------------------------------------| End |----------------------------------


//---------------------------| Public Methods |----------------------------------

void Volume::Append( const Word& WordToAppend ) {

	if ( isFirstWord() ) {
		
	AppendFirstWord( WordToAppend );

	} else {

	AppendWord( WordToAppend );

	}
}

const Word& Volume::getWord( const ElementNumber& IndexOfElement ) const {

	if ( isSizeIsGreaterThan(IndexOfElement) ) {
		
		DictionaryElement* WantedItem = getElement(IndexOfElement);
		return WantedItem->getWord();

	} else RangeException();	

}

void Volume::Prepend( const Word& ToPrepend ) {

	if ( isFirstWord() ) {
		PrependFirst(ToPrepend);
	} else {
		PrependOther(ToPrepend);
	}

}

const Word& Volume::Find( const WatchWord& phrase ) {

	DictionaryElement* ElementHolder = FirstWord;

	for ( unsigned int Idx = 0 ; Idx < Size() ; ++Idx ) {
		if ( isSearchedElement(ElementHolder, phrase)	) 
			return ElementHolder->getWord();
		else GoToTheNext(ElementHolder);
	}
	
	NotFoundException();	

}

void Volume::Remove( const WatchWord& phrase ) {




}



const NumberOfWords& Volume::Size() const {
	return WordCounter;
}


//-------------------------------------| End |----------------------------------
