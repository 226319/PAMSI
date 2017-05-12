#include "Dictionary.hh"


//------------------------| Constructors and Destructor |------------------------

Dictionary::Dictionary( const NumberOfVolumes& _Size ) {

	VolumeList = new Volume[_Size];
	isFound = false;
	DictionarySize = _Size;

}

Dictionary::~Dictionary() {

	delete [] VolumeList;
	VolumeList = nullptr;

}

//-----------------------------------| END |------------------------------------

//---------------------------| Private Methods |---------------------------------

const VolumeNumber Dictionary::Hash(const WatchWord& Term) const {

	VolumeNumber HashedTerm = 0; 


	for ( unsigned int Idx = 0; Idx < Term.size(); ++Idx ) {

		HashedTerm += Term[Idx];

	}
	
	return HashedTerm % DictionarySize;

}


Word& Dictionary::Find( const WatchWord& Term ) const {

	return VolumeList[ Hash(Term) ].Find(Term);

}


const Word* Dictionary::getWord(const WatchWord& Term) const  {
	
	Word* Searched;

	try{	
		Searched = &Find(Term);
	} catch ( Exception Exc ) {
		ExecuteException(Exc);
	}
	
	return Searched; 

}

Word* Dictionary::setWord(const WatchWord& Term) {

	Word * Searched;

	try{	
		Searched = &Find(Term);
	} catch ( Exception Exc ) {
		Searched = &CreateNewWord(Term); 
	}

	return Searched;

}


Word& Dictionary::CreateNewWord( const WatchWord& Term ) {

	Word WordToAppend(Term, "");
	
	Append(WordToAppend);

	return setAppendedWord(Term);
}

void Dictionary::Append( const Word& WordToAppend ) {

	WatchWord tmp = WordToAppend.getWatchWord();
	VolumeList[ Hash(tmp) ].Append(WordToAppend);

}

Word& Dictionary::setAppendedWord( const WatchWord& Term ) {

	VolumeNumber Idx = Hash(Term);
return VolumeList[Idx].setWord(VolumeList[Idx].Size()-1);

}

//---------------------------------| END |------------------------------------


//---------------------------| Public Methods |---------------------------------


const Definition& Dictionary::operator[] ( const WatchWord& Term ) const {
	
	
	return getWord(Term)->getDefinition();
}

Definition& Dictionary::operator[] ( const WatchWord& Term ) {

	return setWord(Term)->setDefinition();

}

void Dictionary::Show() {

	for ( VolumeNumber Idx = 0; Idx < Size(); ++Idx ) {
	
		std::cout << std::endl << "Volume " << Idx << ':';
		std::cout << std::endl <<  VolumeList[Idx];
		
	}

}

void Dictionary::Remove( const WatchWord& Term ) {

	VolumeList[ Hash(Term) ].Remove(Term);

}

//---------------------------------| END |------------------------------------







