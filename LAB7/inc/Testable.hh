#ifndef _TESTABLE_HH_
#define _TESTABLE_HH_

#include "BSTreeTestSettings.hh"

class Testable {
	
	public:
		virtual ~Testable() {} ;
		virtual void PrepareToTest(const BSTreeTestSettings&) {} ;
		virtual void Test(const BSTreeTestSettings&) {};

};

#endif

