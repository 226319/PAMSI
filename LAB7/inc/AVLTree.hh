#ifndef AVLTREE_HH
#define AVLTREE_HH

#include "Tree.hh"

typedef Element* Root;

class AVLTree : public Tree {


	Root TreeRoot;


	public:
	
		AVLTree();
		~AVLTree();
		
		void Add(const Element&);
		void Remove(const Key&);
		Element& Search(const Key&);
	


};








#endif
