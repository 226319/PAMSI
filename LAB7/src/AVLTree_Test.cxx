#include "AVLTree_Test.hh"

void AVLT_AddnSearch_Test() {

	AVLTree mytree;
	Element El(100, "Content1");

		mytree.Add(El);
	for ( int idx = 1; idx < 100 ; ++idx){
		Element ela(idx, "COnst");
		mytree.Add(ela);
		}

	Element elem = mytree.Search(54);

	BOOST_CHECK_EQUAL( elem.getKey(), 54);
	BOOST_CHECK_EQUAL( elem.getContent(), "COnst");


}
	
	






