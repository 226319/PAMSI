#include "ChildNode.hh"

//-----------------------| Constructors and Destructor |-----------------------


ChildNode::ChildNode() {
	
	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;

}

ChildNode::ChildNode( const ChildNode& Son) {

	Parent = Son.getParent();
	RightChild = Son.getRight();
	LeftChild = Son.getLeft();
	NodeElement = Son.getElement();

}

ChildNode::ChildNode( const Element& NewElement ) {
	
	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;
	
	NodeElement.setKey() = NewElement.getKey();
	NodeElement.setContent() = NewElement.getContent();



}

ChildNode& ChildNode::operator = ( const ChildNode& Son ) {

	Parent = Son.getParent();
	RightChild = Son.getRight();
	LeftChild = Son.getLeft();
	NodeElement = Son.getElement();
	
	return *this;

}

ChildNode::~ChildNode() {

	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;

}


//--------------------------------| End |-------------------------------------


//----------------------------| Public methods |-----------------------



ChildNode* const ChildNode::getLeft() const {
	return LeftChild;
}

void ChildNode::setLeft(ChildNode*& LeftSon )  {
	LeftChild = LeftSon;
}

ChildNode* const ChildNode::getRight() const {
	return RightChild;
}

void ChildNode::setRight(ChildNode*& RightSon)  {
	RightChild = RightSon;
}

ChildNode* const ChildNode::getParent() const {
	return Parent;
}

void ChildNode::setParent(ChildNode*& ParentNode)  {
	Parent = ParentNode;
}

const Element& ChildNode::getElement() const {
	return NodeElement;
}


//--------------------------------| End |-------------------------------------


