#ifndef _DICTIONARY_TEST_SETTINGS_HH
#define _DICTIONARY_TEST_SETTINGS_HH

#include "TestSettings.hh"
#include "Dictionary.hh"

class DictionaryTestSettings: public virtual TestSettings {


	unsigned int _ProblemSize;
	unsigned int _NumberOfRealization;
	unsigned int _NumberOfWords;
	
	WatchWord _Term;
	Definition _TermDefinition;
	



	public:

	~DictionaryTestSettings() {}
	DictionaryTestSettings() { 
		_ProblemSize = 0; 
		_NumberOfRealization = 0; 
		_NumberOfWords = 0;
		_Term = "Term";
		_TermDefinition = "TermDefinition";
	
	}

	inline unsigned int& ProblemSize() { return _ProblemSize; }
	inline unsigned int& NumberOfRealization() { return _NumberOfRealization; }
	inline WatchWord& Term() { return _Term; }
	inline Definition& TermDefinition() { return _TermDefinition; }
	inline unsigned int& NumberOfWords() { return _NumberOfWords; }

	inline const unsigned int& ProblemSize() const { return _ProblemSize; }
	inline const unsigned int& NumberOfRealization() const { return _NumberOfRealization; }
	inline const WatchWord& Term() const  { return _Term; }
	inline const Definition& TermDefinition() const { return _TermDefinition; }
	inline const unsigned int& NumberOfWords() const { return _NumberOfWords; }






};











#endif
