#include <boost/test/included/unit_test.hpp>
#include "DictionaryElement_Test.hh"
#include "Word_Test.hh"
#include "Volume_Test.hh"

using namespace boost::unit_test;



test_suite* init_unit_test_suite( int argc, char* argv[] ) {

	test_suite* WordSuite = BOOST_TEST_SUITE( "Word_TestSuite" );
	WordSuite->add( BOOST_TEST_CASE( &Constructor_Test ) ); 
	WordSuite->add( BOOST_TEST_CASE( &getWatchWord_Test ) ); 
	WordSuite->add( BOOST_TEST_CASE( &getDefinition_Test ) ); 
	WordSuite->add( BOOST_TEST_CASE( &setWatchWord_Test ) ); 
	WordSuite->add( BOOST_TEST_CASE( &setDefinition_Test ) ); 

	test_suite* DictionaryElementSuite = BOOST_TEST_SUITE( "DictionaryElement_TestSuite" );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &getNext_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &setNext_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &getPrevious_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &setPrevious_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &getWord_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &setWord_Test) );
	DictionaryElementSuite->add( BOOST_TEST_CASE( &CopyConstructorAndCAssignment_Test) );


	test_suite* VolumeSuite = BOOST_TEST_SUITE( "Volume_TestSuite" );
	VolumeSuite->add( BOOST_TEST_CASE( &Append_getWord_Test ) );
	VolumeSuite->add( BOOST_TEST_CASE( &Size_Test ) );
	

	framework::master_test_suite().add( WordSuite );
	framework::master_test_suite().add( DictionaryElementSuite );
	framework::master_test_suite().add( VolumeSuite );

	return 0;

}








