#include "TestableBSTree.hh"


//------------------------| Constructor and Destructor |------------------------------

TestableBSTree::TestableBSTree() {

	BSTreeToTest = new BSTree;

}

TestableBSTree::~TestableBSTree() {

	delete BSTreeToTest;

}

//----------------------------| End |------------------------------------

//----------------------------| Public Methods |------------------------------------

void TestableBSTree::FillBSTree( const BSTreeTestSettings& Settings ) {


	for ( unsigned int I = 0; I < Settings.ProblemSize(); ++I) 
	{ 
		Element ElemToAdd( rand()%(Settings.ProblemSize()-2), "Content" );
		BSTreeToTest->Add(ElemToAdd);	
	}

	Element ElemToAdd( Settings.ProblemSize(), "Content" );
	BSTreeToTest->Add(ElemToAdd);	

}
//----------------------------| End |------------------------------------

//----------------------------| Public Methods |------------------------------------

void TestableBSTree::PrepareToTest( const BSTreeTestSettings& Settings ) {

	delete BSTreeToTest;
	BSTreeToTest = new BSTree;

	FillBSTree(Settings);
	
	if ( Settings.Balance() ) {
		BSTreeToTest->Balance();
	}

}

void TestableBSTree::Test( const BSTreeTestSettings& Settings) {

	BSTreeToTest->Search( Settings.ProblemSize() );

}


//----------------------------| End |------------------------------------




