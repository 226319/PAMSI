#include "Dictionary_Test.hh"



void wordAccess_Test() {


	Dictionary NewOne(7);
	const unsigned int NUM_OF_WORDS = 100;


	for ( unsigned int Idx = 0; Idx < NUM_OF_WORDS; ++Idx ) {
		WatchWord Term = "Word" + std::to_string(Idx);
		Definition DefOfTerm = "Definition of Word" + std::to_string(Idx);
		
		NewOne[Term] = DefOfTerm;
	}


	BOOST_CHECK_EQUAL( NewOne["Word45"], "Definition of Word45" );

	NewOne.Show();

}




