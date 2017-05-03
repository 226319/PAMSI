#include "Volume_Test.hh"


void Size_Test() {
	
	Volume NewOne;
	Word newWord;
	const unsigned SIZE = 4;

	for ( int i = 0; i < SIZE; ++i) {
		NewOne.Append(newWord);
	}
	
	BOOST_CHECK_EQUAL( NewOne.Size(), SIZE );



}

void Append_getWord_Test() {

	Volume NewOne;
	Word   First("FirstWord","First word definition");
	Word	 Second("Second Word", "Second word definition");
	Word	 Third("Third Worc", "Third word definition");
	
	NewOne.Append(First);
	NewOne.Append(Second);
	NewOne.Append(Third);


	BOOST_CHECK( NewOne.getWord(0) == First );
	BOOST_CHECK( NewOne.getWord(1) == Second);
	BOOST_CHECK( NewOne.getWord(2) == Third);
	BOOST_CHECK_THROW( NewOne.getWord(3), std::string);
	BOOST_CHECK_THROW( NewOne.getWord(-1), std::string);
}	





