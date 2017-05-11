#include "Volume_Test.hh"


void Size_Test() {
	
	Volume NewOne;
	Word newWord;
	const unsigned SIZE = 4;

	for ( unsigned int i = 0; i < SIZE; ++i) {
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
	NewOne.Append(First);
	NewOne.Append(Second);
	NewOne.Append(Third);


	BOOST_CHECK( NewOne.getWord(0) == First );
	BOOST_CHECK( NewOne.getWord(1) == Second);
	BOOST_CHECK( NewOne.getWord(2) == Third);
	BOOST_CHECK( NewOne.getWord(3) == First );
	BOOST_CHECK( NewOne.getWord(4) == Second);
	BOOST_CHECK( NewOne.getWord(5) == Third);
	
	BOOST_CHECK_THROW( NewOne.getWord(8), std::string);
	BOOST_CHECK_THROW( NewOne.getWord(-1), std::string);
}	

void Prepend_Test() {

	Volume NewOne;
	Word   First("FirstWord","First word definition");
	Word	 Second("Second Word", "Second word definition");
	Word	 Third("Third Worc", "Third word definition");
	
	NewOne.Prepend(Third);
	NewOne.Prepend(Second);
	NewOne.Prepend(First);

	BOOST_CHECK( NewOne.getWord(0) == First );
	BOOST_CHECK( NewOne.getWord(1) == Second);
	BOOST_CHECK( NewOne.getWord(2) == Third);

}

void Find_Test() {

	Volume NewOne;
	Word   First("FirstWord","First word definition");
	Word	 Third("Third Worc", "Third word definition");
	const unsigned int SIZE = 10;


	for ( unsigned int i = 0; i < SIZE; ++i  )
		NewOne.Append(First);
	
	NewOne.Append(Third);

	for ( unsigned int i = 0; i < SIZE; ++i  )
		NewOne.Append(First);

	BOOST_CHECK(NewOne.Find("Third Worc") == Third);
	BOOST_CHECK_THROW(NewOne.Find("something"), std::string);

}

void Remove_Test() {

	Volume NewOne;
	Word   First("FirstWord","First word definition");
	Word	 Third("Third Worc", "Third word definition");
	const unsigned int SIZE = 10;


	for ( unsigned int i = 0; i < SIZE; ++i  )
		NewOne.Append(First);
	
	NewOne.Append(Third);

	for ( unsigned int i = 0; i < SIZE; ++i  )
		NewOne.Append(First);

	NewOne.Remove("Third Worc");
	
	BOOST_CHECK_THROW(NewOne.Find("Third Worc"), std::string);

}

void Volume_setWord_Test() {

	Volume NewOne;
	Word   First("FirstWord","First word definition");
	Word	 Third("Third Worc", "Third word definition");
	const unsigned int SIZE = 10;


	for ( unsigned int i = 0; i < SIZE; ++i  )
		NewOne.Append(First);

	NewOne.setWord(4) = Third;	

	BOOST_CHECK(NewOne.Find("Third Worc") == Third);

}





