#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Dictionary
#include <boost/test/unit_test.hpp>
#include "Word.hh"
#include "DictionaryElement.hh"

BOOST_AUTO_TEST_SUITE( Word_Test ) 

	BOOST_AUTO_TEST_CASE( Constructor_Test ) {
		Word NewWord;
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "WatchWord" );
	}

	BOOST_AUTO_TEST_CASE( getWatchWord_Test ) {
		Word NewWord("NewWord", "NewDefinition");
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "NewWord" );
	}

	BOOST_AUTO_TEST_CASE( getDefinition_Test ) {
		Word NewWord("NewWord", "NewDefinition");
		BOOST_CHECK_EQUAL( NewWord.getDefinition(), "NewDefinition" );
	}

	BOOST_AUTO_TEST_CASE( setWatchWord_Test ) {
		Word NewWord;
		
		NewWord.setWatchWord() = "NewWord";
		BOOST_CHECK_EQUAL( NewWord.getWatchWord(), "NewWord" );
	}

	BOOST_AUTO_TEST_CASE( setDefinition_Test ) {
		Word NewWord;

		NewWord.setDefinition() = "NewDefinition";
		BOOST_CHECK_EQUAL( NewWord.getDefinition(), "NewDefinition" );
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( DictionaryElement_Test )

	BOOST_AUTO_TEST_CASE( getNext_Test ) {
		
		DictionaryElement NewDictElement;

		BOOST_CHECK( NewDictElement.getNext() == nullptr );
	
	}
	
	BOOST_AUTO_TEST_CASE( setNext_Test ) {
		
		DictionaryElement NewDictElement, AnotherOne;

		NewDictElement.setNext(&AnotherOne);

		BOOST_CHECK( NewDictElement.getNext() == &AnotherOne );
	
	}

	BOOST_AUTO_TEST_CASE( getWord_Test ) {

		DictionaryElement NewDictElement;
	
		Word TmpWord = NewDictElement.getWord();

		BOOST_CHECK_EQUAL( TmpWord.getWatchWord(), "WatchWord" );
		BOOST_CHECK_EQUAL( TmpWord.getDefinition(), "Definition" );
	}
	
	BOOST_AUTO_TEST_CASE( setWord_Test ) {

		DictionaryElement NewDictElement;
	
		Word TmpWord1("Maslo", "Wyrob z mleka");
		NewDictElement.setWord() = TmpWord1;
		Word TmpWord = NewDictElement.getWord();


		BOOST_CHECK_EQUAL( TmpWord.getWatchWord(), "WatchWord" );
		BOOST_CHECK_EQUAL( TmpWord.getDefinition(), "Definition" );
	}

BOOST_AUTO_TEST_SUITE_END()


