#ifndef BSTREE_HH
#define BSTREE_HH

#include "Tree.hh"
#include "ChildNode.hh"
#include "Element.hh"
#include <iostream>
#include <cmath>
#include <string>

typedef unsigned int TreeSize;

class BSTree : public Tree {


	ChildNode* TreeRoot;
	TreeSize NumberOfNodes;


	public:
	
		BSTree();
		~BSTree();
		
		void Add(const Element&);
		void Delete(const Key&);
		Element& Search(const Key&);
		void InorderTreeWalk();	
		void Balance();
	
	 private:
		
		void CreateBackBone();
		void RemoveTree(ChildNode*);
		void CreateBalancedTree();
		void Insert( ChildNode* Son );
		ChildNode* TreeSuccessor( ChildNode* Son );
		ChildNode* TreePredecessor( ChildNode* Son );
		ChildNode* Minimum( ChildNode* ) ;
		ChildNode* Maximum( ChildNode* ) ;
		ChildNode* LeftRotate( ChildNode* ) ;
		ChildNode* RightRotate( ChildNode* ) ;
		ChildNode* DeleteNode(ChildNode*) ;

		bool isSearched(ChildNode*& , const Key& );
		bool isInRightBranch(ChildNode*& , const Key& );
		ChildNode* SearchNode( ChildNode*, const Key&);
		unsigned int RotNum();
		void NotFoundException() const;
		void InorderWalk(ChildNode*);

		const TreeSize& Size() const;
		TreeSize& Size();

};








#endif
