#ifndef _TESTABLE_DICTIONARY_HH
#define _TESTABLE_DICTIONARY_HH

#include "Dictionary.hh"
#include "Testable.hh"
#include "DictionaryTestSettings.hh"
#include "TestSettings.hh"

class TestableDictionary: public Testable {


	Dictionary* DictionaryToTest;

	void FillDictionary(const DictionaryTestSettings&);

	public:

		TestableDictionary();
		~TestableDictionary();

		void PrepareToTest(const DictionaryTestSettings&);
		void Test(const DictionaryTestSettings&);




};








#endif
