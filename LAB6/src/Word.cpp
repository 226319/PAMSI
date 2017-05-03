#include "Word.hh"



//------------------| Constructors and destructor |-----------------


Word::Word() {
	Name = "WatchWord";
	Meaning = "Definition";
}

Word::Word( const WatchWord& wordName, const Definition& wordDef ) {
	Name = wordName;
	Meaning = wordDef;
}

Word::Word( const Word& WordToCopy ) {

	Name = WordToCopy.getWatchWord();
	Meaning = WordToCopy.getDefinition();
}

Word::~Word() {

}

//-------------------------| End |-----------------------------


//--------------------| Public Methods |-----------------------


const Definition& Word::getDefinition() const {
	return Meaning;
}

Definition& Word::setDefinition() {
	return Meaning;
}

const WatchWord& Word::getWatchWord() const {
	return Name;
}

WatchWord& Word::setWatchWord() {
	return Name;
}

bool Word::operator==( const Word& WordToCheck ) const {

if ( ( Name == WordToCheck.getWatchWord() ) && ( Meaning == WordToCheck.getDefinition() ) ) 
	return true;
else return false;


}


//--------------------------| End |------------------------------



