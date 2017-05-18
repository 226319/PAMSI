#include "TestableDictionary.hh"


//------------------------| Constructor and Destructor |-------------------------------

TestableDictionary::TestableDictionary() {

	DictionaryToTest = nullptr;

}

TestableDictionary::~TestableDictionary() {

	delete DictionaryToTest;
	DictionaryToTest = nullptr;


}

//----------------------------| End |------------------------------------

//----------------------------| Public Methods |------------------------------------

void TestableDictionary::FillDictionary( const DictionaryTestSettings& Settings ) {


	for ( unsigned int I = 0; I < Settings.NumberOfWords(); ++I) { 
		WatchWord Term = "Word" + std::to_string(I);
		Definition TermDef = "Definition of Word" + std::to_string(I);
		
		(*DictionaryToTest)[Term] = TermDef;	
	}
	
	(*DictionaryToTest)[Settings.Term()] = Settings.TermDefinition();

}
//----------------------------| End |------------------------------------

//----------------------------| Public Methods |------------------------------------

void TestableDictionary::PrepareToTest( const DictionaryTestSettings& Settings ) {

	delete DictionaryToTest;
	DictionaryToTest = new Dictionary(Settings.ProblemSize());
	(*DictionaryToTest).SetHashFunctionType(Settings.HashType());
	FillDictionary(Settings);

}

void TestableDictionary::Test( const DictionaryTestSettings& Settings) {

 if ( (*DictionaryToTest)[Settings.Term()] != Settings.TermDefinition() ) 
		 abort();

}


//----------------------------| End |------------------------------------




