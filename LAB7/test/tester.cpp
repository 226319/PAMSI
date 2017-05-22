#include <boost/test/included/unit_test.hpp>
#include "Element_Test.hh"
#include "ChildNode_Test.hh"
#include "AVLTree_Test.hh"
//#include "Dictionary_Test.hh"

using namespace boost::unit_test;



test_suite* init_unit_test_suite( int argc, char* argv[] ) {

	test_suite* ElementSuite = BOOST_TEST_SUITE( "Element_TestSuite" );
	ElementSuite->add( BOOST_TEST_CASE( &Constructor_Test ) ); 
	ElementSuite->add( BOOST_TEST_CASE( &getMethods_Test ) ); 
	ElementSuite->add( BOOST_TEST_CASE( &setMethods_Test ) ); 

	test_suite* ChildNodeSuite = BOOST_TEST_SUITE( "ChildNode_TestSuite" );
	ChildNodeSuite->add( BOOST_TEST_CASE( &CN_Constructors_Test ) ); 
	ChildNodeSuite->add( BOOST_TEST_CASE( &CN_CpyConstructor_Test ) ); 

	test_suite* AVLTreeSuite = BOOST_TEST_SUITE( "AVLTree_TestSuite" );
	AVLTreeSuite->add( BOOST_TEST_CASE( &AVLT_AddnSearch_Test ) ); 
		

	framework::master_test_suite().add( ElementSuite );
	framework::master_test_suite().add( ChildNodeSuite );
	framework::master_test_suite().add( AVLTreeSuite );

	return 0;

}








