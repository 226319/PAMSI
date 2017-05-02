#include "Word_Test.hh"

	void Constructor_Test () {
		Word NewWord;
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "WatchWord" );
	}

	void getWatchWord_Test () {
		Word NewWord("NewWord", "NewDefinition");
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "NewWord" );
	}

	void getDefinition_Test () {
		Word NewWord("NewWord", "NewDefinition");
		BOOST_CHECK_EQUAL( NewWord.getDefinition(), "NewDefinition" );
	}

	void setWatchWord_Test () {
		Word NewWord;
		
		NewWord.setWatchWord() = "NewWord";
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "NewWord" );
	}

	void setDefinition_Test () {
		Word NewWord;

		NewWord.setDefinition() = "NewDefinition";
		BOOST_CHECK_EQUAL( NewWord.getDefinition(), "NewDefinition" );
	}


