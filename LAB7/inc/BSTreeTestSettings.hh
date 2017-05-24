#ifndef _BSTREE_TEST_SETTINGS_HH
#define _BSTREE_TEST_SETTINGS_HH

#include "TestSettings.hh"
#include "BSTree.hh"

class BSTreeTestSettings: public virtual TestSettings {


	unsigned int _ProblemSize;
	unsigned int _NumberOfRealization;
	unsigned int _Key;
	unsigned int _Balance;
	



	public:

	~BSTreeTestSettings() {}
	BSTreeTestSettings() { 
		_ProblemSize = 0; 
		_NumberOfRealization = 0; 
		_Balance = 0;

	
	}

	inline unsigned int& ProblemSize() { return _ProblemSize; }
	inline unsigned int& NumberOfRealization() { return _NumberOfRealization; }

	inline const unsigned int& ProblemSize() const { return _ProblemSize; }
	inline const unsigned int& NumberOfRealization() const { return _NumberOfRealization; }


	inline unsigned int& Balance() { return _Balance; }
	inline const unsigned int& Balance() const { return _Balance; }




};











#endif
