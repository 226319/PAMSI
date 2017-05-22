#include "AVLTree.hh"

//----------------------------| Constructor n destructor |------------------------

AVLTree::AVLTree() {

	TreeRoot = nullptr;

}

AVLTree::~AVLTree() {

	RemoveTree(TreeRoot);


}


//---------------------------------| Private Methods |----------------------------

void AVLTree::RemoveTree( ChildNode* Son ) {

	if ( Son != nullptr )  {

		RemoveTree( Son->getLeft() );
		RemoveTree( Son->getRight() );

		delete Son;	
	}

}

void AVLTree::CreateRoot(ChildNode*& child, const Element& newElement) {
	child = new ChildNode(newElement);
}

void AVLTree::AppendToLeftBranch( ChildNode* child, const Element& newElement) {

	if ( child->getLeft() == nullptr )  {
		ChildNode* ptr = new ChildNode(newElement);
		child->setLeft( ptr );
		ptr = nullptr;

	} else  {
		AppendToTree(child->getLeft(), newElement);
	}
}

void AVLTree::AppendToRightBranch( ChildNode* child, const Element& newElement) {

	if ( child->getRight() == nullptr )  {
		ChildNode* ptr = new ChildNode(newElement);
		child->setRight( ptr );
		ptr = nullptr;
	} else  {
		AppendToTree(child->getRight(), newElement);
	}
}

void AVLTree::AppendToTree( ChildNode* child,const Element& NewElement) {

	if ( child->getElement()->getKey() > NewElement.getKey() ) {
		AppendToLeftBranch( child, NewElement );	
	} else {
		AppendToRightBranch( child, NewElement );
	}

}

bool AVLTree::isSearched(ChildNode*& Son , const Key& searchKey ) {
	return (Son->getElement()->getKey() == searchKey);
}

bool AVLTree::isInRightBranch( ChildNode*& Son , const Key& searchKey ) {
	return (Son->getElement()->getKey() < searchKey); 
}

void AVLTree::NotFoundException() const {

	std::string Exception = "\nNot found";
	throw Exception;

}

ChildNode* AVLTree::SearchNode( ChildNode* Son , const Key& searchKey ) {

	if ( Son != nullptr ) {
	
		if ( isSearched(Son,searchKey) )  
			return Son;
		
		if ( isInRightBranch(Son,searchKey) ) 
			return SearchNode(Son->getRight(), searchKey) ;
		else 
			return SearchNode(Son->getLeft(), searchKey) ;
	
	} 

}

//---------------------------------| Public Methods |----------------------------

void AVLTree::Add( const Element& NewElement ) {

	if ( TreeRoot == nullptr ) {
		CreateRoot(TreeRoot, NewElement);
	} else {
		AppendToTree(TreeRoot,NewElement);
	}

}

Element& AVLTree::Search( const Key& searchKey ) {

	ChildNode* Child = TreeRoot;
	Child = SearchNode( Child, searchKey );

   if ( Child == nullptr ) {
		NotFoundException();
	}

	return *( Child->getElement() );


}

void AVLTree::Show() {

	Print(TreeRoot);

}

void AVLTree::Print( ChildNode* Son) {

	if ( Son != nullptr ) {
		std::cout << std::endl << Son->getElement()->getKey();
		std::cout << ' ' << Son->getElement()->getContent();
		Print(Son->getLeft());
		Print(Son->getRight());
	}
}


