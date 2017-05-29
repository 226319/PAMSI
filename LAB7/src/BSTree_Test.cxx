#include "BSTree_Test.hh"

void BST_AddnSearch_Test() {

	BSTree mytree;
	Element El(100, "Content1");

		mytree.Add(El);
	for ( int idx = 1; idx < 100 ; ++idx){
		Element ela(idx, "COnst");
		mytree.Add(ela);
		}

	Element lement = mytree.Search(54);
	
	BOOST_CHECK( lement.getKey() == 54 );
	BOOST_CHECK( lement.getContent() == "COnst" );
}



void  BST_Delete_Test() {

	BSTree mytree;

	for ( int idx = 1; idx < 10 ; ++idx){
		Element ela(idx, "COnst");
		mytree.Add(ela);
		}

	mytree.Delete(4);

	BOOST_CHECK_THROW(mytree.Search(4), std::string );

}	
	






