#ifndef AVLTREE_HH
#define AVLTREE_HH

#include "Tree.hh"
#include "ChildNode.hh"
#include "Element.hh"
#include <iostream>
#include <string>

class AVLTree : public Tree {


	ChildNode* TreeRoot;


	public:
	
		AVLTree();
		~AVLTree();
		
		void Add(const Element&);
		//	void Delete(const Key&);
		 Element& Search(const Key&);
		 void Show();
	
	private:
		void RemoveTree(ChildNode*);
		void CreateRoot(ChildNode*& , const Element& );
		void AppendToTree( ChildNode* , const Element& );
		void SearchPlaceForNewChildNode( ChildNode* ,const Element& );
		bool isSearched(ChildNode*& , const Key& );
		bool isInRightBranch(ChildNode*& , const Key& );
		ChildNode* SearchNode( ChildNode*, const Key&);
		void AppendToLeftBranch( ChildNode*, const Element& );
		void AppendToRightBranch( ChildNode*, const Element& );
		void Print(ChildNode*);
		void NotFoundException() const;
};








#endif
