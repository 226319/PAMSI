#include "DictionaryElement_Test.hh"

void getNext_Test () {
	
	DictionaryElement NewDictElement;

	BOOST_CHECK( NewDictElement.getNext() == nullptr );

}

void setNext_Test () {
	
	DictionaryElement NewDictElement, AnotherOne;

	NewDictElement.setNext(&AnotherOne);

	BOOST_CHECK_EQUAL( NewDictElement.getNext(),&AnotherOne );

}
	
void getPrevious_Test () {
	
	DictionaryElement NewDictElement;

	BOOST_CHECK( NewDictElement.getPrevious() == nullptr );

}

void setPrevious_Test () {
	
	DictionaryElement NewDictElement, AnotherOne;

	NewDictElement.setPrevious(&AnotherOne);

	BOOST_CHECK_EQUAL( NewDictElement.getPrevious(),&AnotherOne );

}


void getWord_Test () {

	DictionaryElement NewDictElement;

	Word TmpWord = NewDictElement.getWord();

	BOOST_CHECK_EQUAL( TmpWord.getWatchWord(), "WatchWord" );
	BOOST_CHECK_EQUAL( TmpWord.getDefinition(), "Definition" );
}

void setWord_Test () {

	DictionaryElement NewDictElement;

	Word TmpWord1("Maslo", "Wyrob z mleka");
	NewDictElement.setWord() = TmpWord1;
	Word TmpWord = NewDictElement.getWord();


	BOOST_CHECK_EQUAL( TmpWord.getWatchWord(), "Maslo" );
	BOOST_CHECK_EQUAL( TmpWord.getDefinition(), "Wyrob z mleka" );
}

void CopyConstructorAndCAssignment_Test () {
	
	Word tmpWord("Maslo","Jedyne") ;
	DictionaryElement DictElemToCopy, NextDictElem, PreviousDictElem;
	
	DictElemToCopy.setNext(&NextDictElem);
	DictElemToCopy.setPrevious(&PreviousDictElem);
	DictElemToCopy.setWord() = tmpWord;

	DictionaryElement DictionElem(DictElemToCopy);
	
	BOOST_CHECK_EQUAL( DictionElem.getNext(),&NextDictElem );
	BOOST_CHECK_EQUAL( DictionElem.getPrevious(),&PreviousDictElem );
	
	Word CopiedWord(DictionElem.getWord());
	
	BOOST_CHECK_EQUAL( CopiedWord.getWatchWord(), "Maslo" );
	BOOST_CHECK_EQUAL( CopiedWord.getDefinition(), "Jedyne" );

	DictionaryElement DictElem;

	DictElem = DictElemToCopy;


	BOOST_CHECK_EQUAL( DictElem.getNext(),&NextDictElem );
	BOOST_CHECK_EQUAL( DictElem.getPrevious(),&PreviousDictElem );
	
	Word CopiedWord1(DictionElem.getWord());
	
	BOOST_CHECK_EQUAL( CopiedWord1.getWatchWord(), "Maslo" );
	BOOST_CHECK_EQUAL( CopiedWord1.getDefinition(), "Jedyne" );
	
}

