#ifndef _TESTABLE_BSTREE_HH
#define _TESTABLE_BSTREE_HH

#include "BSTree.hh"
#include "Testable.hh"
#include "BSTreeTestSettings.hh"
#include "TestSettings.hh"

class TestableBSTree: public Testable {


	BSTree *BSTreeToTest;

	void FillBSTree(const BSTreeTestSettings&);

	public:

		TestableBSTree();
		~TestableBSTree();

		void PrepareToTest(const BSTreeTestSettings&);
		void Test(const BSTreeTestSettings&);




};








#endif
