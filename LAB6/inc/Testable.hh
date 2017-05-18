#ifndef _TESTOWA_HH_
#define _TESTOWA_HH_

#include "DictionaryTestSettings.hh"

class Testable {
	
	public:
		virtual ~Testable() {} ;
		virtual void PrepareToTest(const DictionaryTestSettings&) {} ;
		virtual void Test(const DictionaryTestSettings&) {};

};

#endif

