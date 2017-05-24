#include "Element_Test.hh"


void Constructor_Test () {

	Element NewElement;


	BOOST_CHECK_EQUAL( NewElement.getKey(), 0 );
	BOOST_CHECK_EQUAL( NewElement.getContent(), "No Content" );

}

void getMethods_Test () {


	Element NewElement( 32, "Content" );

	BOOST_CHECK_EQUAL( NewElement.getKey(), 32 );
	BOOST_CHECK_EQUAL( NewElement.getContent(), "Content" );


}

void setMethods_Test ()  {
	
	Element NewElement;

	NewElement.setKey() = 32;
	NewElement.setContent() = "Content";

	BOOST_CHECK_EQUAL( NewElement.getKey(), 32 );
	BOOST_CHECK_EQUAL( NewElement.getContent(), "Content" );


}

