#include <boost/test/included/unit_test.hpp>
#include "DictionaryElement_Test.hh"
#include "Word_Test.hh"

using namespace boost::unit_test;



test_suite* init_unit_test_suite( int argc, char* argv[] ) {

	test_suite* FirstSuite = BOOST_TEST_SUITE( "Word_TestSuite" );
	FirstSuite->add( BOOST_TEST_CASE( &Constructor_Test ) ); 
	FirstSuite->add( BOOST_TEST_CASE( &getWatchWord_Test ) ); 
	FirstSuite->add( BOOST_TEST_CASE( &getDefinition_Test ) ); 
	FirstSuite->add( BOOST_TEST_CASE( &setWatchWord_Test ) ); 
	FirstSuite->add( BOOST_TEST_CASE( &setDefinition_Test ) ); 

	test_suite* SecondSuite = BOOST_TEST_SUITE( "DictionaryElement_TestSuite" );
	SecondSuite->add( BOOST_TEST_CASE( &getNext_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &setNext_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &getPrevious_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &setPrevious_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &getWord_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &setWord_Test) );
	SecondSuite->add( BOOST_TEST_CASE( &CopyConstructorAndCAssignment_Test) );

	framework::master_test_suite().add( FirstSuite );
	framework::master_test_suite().add( SecondSuite );

	return 0;

}








