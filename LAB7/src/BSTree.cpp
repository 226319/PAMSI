#include "BSTree.hh"

//----------------------------| Constructor n destructor |------------------------

BSTree::BSTree() {

	TreeRoot = nullptr;
	NumberOfNodes = 0;

}

BSTree::~BSTree() {

	RemoveTree(TreeRoot);


}


//---------------------------------| Private Methods |----------------------------

void BSTree::RemoveTree( ChildNode* Son ) {

	if ( Son != nullptr )  {

		RemoveTree( Son->getLeft() );
		RemoveTree( Son->getRight() );

		delete Son;	
	}

}

bool BSTree::isSearched(ChildNode*& Son , const Key& searchKey ) {
	return (Son->getElement()->getKey() == searchKey);
}

bool BSTree::isInRightBranch( ChildNode*& Son , const Key& searchKey ) {
	return (Son->getElement()->getKey() < searchKey); 
}

void BSTree::NotFoundException() const {

	std::string Exception = "\nNot found";
	throw Exception;

}

ChildNode* BSTree::SearchNode( ChildNode* Son , const Key& searchKey ) {

	if ( Son != nullptr ) {
	
		if ( isSearched(Son,searchKey) )  
			return Son;
		
		if ( isInRightBranch(Son,searchKey) ) 
			return SearchNode(Son->getRight(), searchKey) ;
		else 
			return SearchNode(Son->getLeft(), searchKey) ;
	
	} 

}

void BSTree::InorderWalk( ChildNode* Son) {

	if ( Son != nullptr ) {
		InorderWalk(Son->getLeft());
		std::cout << Son->getElement()->getKey();
		std::cout << ' ' << Son->getElement()->getContent() << std::endl ;

		InorderWalk(Son->getRight());
	}
}


void BSTree::Insert( ChildNode* Son ) {

	ChildNode* SonNode = nullptr, *TemporaryNode = TreeRoot;

	while ( TemporaryNode != nullptr )  {
		SonNode = TemporaryNode;
		if ( Son->getElement()->getKey() < TemporaryNode->getElement()->getKey() ) {
			TemporaryNode = TemporaryNode->getLeft();
		} else {
			TemporaryNode = TemporaryNode->getRight();
		}
	}
	
	Son->setParent( SonNode );

	if ( SonNode == nullptr ) {
		TreeRoot = Son;
	} else if ( Son->getElement()->getKey() < SonNode->getElement()->getKey() )  {
		SonNode->setLeft( Son );
	} else {
		SonNode->setRight( Son );
	}

}

ChildNode* BSTree::TreeSuccessor( ChildNode* Son ) {
	

	if ( Son->getRight() != nullptr ) {
		return Minimum(Son->getRight()) ; 
	}
	
	ChildNode* TemporaryNode = Son->getParent();
	
	while ( (TemporaryNode != nullptr) && (TemporaryNode->getRight() == Son) ) {
		Son = TemporaryNode;
		TemporaryNode = TemporaryNode->getParent();
	}

	return TemporaryNode;

}

ChildNode* BSTree::TreePredecessor( ChildNode* Son ) {
	

	if ( Son->getLeft() != nullptr ) {
		return Minimum(Son->getLeft()) ; 
	}
	
	ChildNode* TemporaryNode = Son->getParent();
	
	while ( (TemporaryNode != nullptr) && (TemporaryNode->getLeft() == Son) ) {
		Son = TemporaryNode;
		TemporaryNode = TemporaryNode->getParent();
	}

	return TemporaryNode;

}


ChildNode* BSTree::Minimum( ChildNode* Son ) {

	while ( Son->getLeft() != nullptr ) {
		ChildNode* ptr = Son->getLeft();
		Son->setLeft( ptr );
	}

	return Son;

}

ChildNode* BSTree::Maximum( ChildNode* Son ) {

	while ( Son->getRight() != nullptr ) {
		ChildNode* ptr = Son->getRight();
		Son->setRight( ptr );
	}

	return Son;

}

ChildNode* BSTree::LeftRotate( ChildNode* Son ) {
	
	if ( Son->getRight() != nullptr ) {
		ChildNode* MoveChild = Son->getRight();
		ChildNode* helpNode = MoveChild->getLeft();
		Son->setRight( helpNode );

		if ( MoveChild->getLeft() != nullptr ) {
			MoveChild->getLeft()->setParent(Son);
		}
		
		helpNode = Son->getParent();	
		MoveChild->setParent( helpNode );

		if ( Son->getParent() == nullptr ) {
			TreeRoot = MoveChild;
		} else {

			if ( Son == Son->getParent()->getLeft() ) {
				Son->getParent()->setLeft(MoveChild);
			} else {
				Son->getParent()->setRight(MoveChild);
			}
		}

		MoveChild->setLeft(Son);
		Son->setParent(MoveChild);
	}
	return Son;
}


ChildNode* BSTree::RightRotate( ChildNode* Son ) {
	
	if ( Son->getLeft() != nullptr ) {
		ChildNode* MoveChild = Son->getLeft();
		ChildNode* helpNode = MoveChild->getRight();
		Son->setLeft( helpNode );

		if ( MoveChild->getRight() != nullptr ) {
			MoveChild->getRight()->setParent(Son);
		}
		
		helpNode = Son->getParent();	
		MoveChild->setParent( helpNode );

		if ( Son->getParent() == nullptr ) {
			TreeRoot = MoveChild;
		} 
		else {
		
			if ( Son == Son->getParent()->getRight() ) {
				Son->getParent()->setRight(MoveChild);
			} else {
				Son->getParent()->setLeft(MoveChild);
			}
		
		}

		MoveChild->setRight(Son);
		Son->setParent(MoveChild);
	}
	return Son;
}
	

ChildNode* BSTree::DeleteNode(ChildNode* Son) {

	ChildNode* TemporaryNode = nullptr, *Leaf = nullptr;

	if ( (Son->getLeft() == nullptr) || (Son->getRight() == nullptr) ) {
		TemporaryNode = Son;
	} else {
		TemporaryNode = TreeSuccessor( Son );
	}

	if ( TemporaryNode->getLeft() != nullptr ) {
		Leaf = TemporaryNode->getLeft();
	} else {
		Leaf = TemporaryNode->getRight();
	}

	if ( Leaf != nullptr )  {
		ChildNode * ptr = TemporaryNode->getParent();
		Leaf->setParent( ptr );
	}

	if ( TemporaryNode->getParent() == nullptr ) {
		TreeRoot = Leaf;
	} else if ( TemporaryNode == TemporaryNode->getParent()->getLeft() )  {
		ChildNode* ptr = TemporaryNode->getParent();
		ptr->setLeft( Leaf );
	} else {
		ChildNode* ptr = TemporaryNode->getParent();
		ptr->setRight( Leaf );
	}

	if ( TemporaryNode != Son ) {
		Son->setElement( TemporaryNode->getElement() );
	}

	return TemporaryNode;

}


void BSTree::CreateBackBone() {

	ChildNode * TempNode = TreeRoot;

	while ( TempNode != nullptr ) {

		if ( TempNode->getLeft() != nullptr ) {
			TempNode = RightRotate(TempNode);
		} else {
			TempNode = TempNode->getRight();
		}
	}

	TempNode = nullptr;
}

const TreeSize& BSTree::Size() const {
	return NumberOfNodes;
}

TreeSize& BSTree::Size() { 
	return NumberOfNodes;
}

void BSTree::CreateBalancedTree() {

	unsigned int m = RotNum();
	ChildNode* TempNode = TreeRoot;


	for ( unsigned int Idx = 0; Idx < Size()-m; ++Idx) {
		TempNode = LeftRotate( TempNode );
		TempNode = TempNode->getParent()->getRight();
	}

	while ( m > 1 ) {

		m = m/2;
	
		TempNode = TreeRoot;
		for ( unsigned int Idx = 0; Idx < m; ++Idx) {
			TempNode = LeftRotate( TempNode );
			TempNode = TempNode->getParent()->getRight();
		}
	}

}

unsigned int BSTree::RotNum() {
	return (pow(2,log(Size()+1)/log(2) ) -1);

}


//---------------------------------| Public Methods |----------------------------

void BSTree::Add(const Element& elem) {

	ChildNode* NewNode = new ChildNode(elem);
	Insert(NewNode);
	Size() = Size() + 1;	

	NewNode = nullptr;


}

void BSTree::Delete( const Key& deleteKey ) { 

	ChildNode* NodeToDelete ;
	
	try{
	NodeToDelete = SearchNode(TreeRoot,deleteKey);
	} catch( std::string Exc ) {
	
		std::string exception = "Deleting not existing node...\n";
		throw exception;
	}

	DeleteNode( NodeToDelete );
	Size() = Size() - 1;	



}
void BSTree::Balance() {

	if ( TreeRoot != nullptr ) {
		CreateBackBone();
		CreateBalancedTree();
	}


}


Element& BSTree::Search( const Key& searchKey ) {

	ChildNode* Child = TreeRoot;
	Child = SearchNode( Child, searchKey );

   if ( Child == nullptr ) {
		NotFoundException();
	}

	return *( Child->getElement() );

}

void BSTree::InorderTreeWalk() {

	InorderWalk(TreeRoot);

}

