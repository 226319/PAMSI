#include "TestableDictionary.hh"


TestableDictionary::TestableDictionary() {

	DictionaryToTest = nullptr;

}

TestableDictionary::~TestableDictionary() {

	delete DictionaryToTest;
	DictionaryToTest = nullptr;


}


void TestableDictionary::PrepareToTest( const DictionaryTestSettings& Settings ) {

	delete DictionaryToTest;
	DictionaryToTest = new Dictionary(Settings.ProblemSize());
	FillDictionary(Settings);

}


void TestableDictionary::FillDictionary( const DictionaryTestSettings& Settings ) {


	for ( unsigned int I = 0; I < Settings.NumberOfWords(); ++I) { 
		WatchWord Term = "Word" + std::to_string(I);
		Definition TermDef = "Definition of Word" + std::to_string(I);
		
		(*DictionaryToTest)[Term] = TermDef;	
	}
	
	(*DictionaryToTest)[Settings.Term()] = Settings.TermDefinition();

}



void TestableDictionary::Test( const DictionaryTestSettings& Settings) {

(*DictionaryToTest)[Settings.Term()];

}




