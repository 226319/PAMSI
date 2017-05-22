#include "ChildNode.hh"

//-----------------------| Constructors and Destructor |-----------------------


ChildNode::ChildNode() {
	
	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;
	NodeElement = nullptr;

}

ChildNode::ChildNode( const ChildNode& ChildToCopy) {

	Parent = ChildToCopy.getParent();
	RightChild = ChildToCopy.getRight();
	LeftChild = ChildToCopy.getLeft();

	
	NodeElement = new Element;
	NodeElement->setKey() = ChildToCopy.getElement()->getKey();
	NodeElement->setContent() = ChildToCopy.getElement()->getContent();

}

ChildNode::ChildNode( const Element& NewElement ) {
	
	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;

	NodeElement = new Element;
	NodeElement->setKey() = NewElement.getKey();
	NodeElement->setContent() = NewElement.getContent();

}

ChildNode& ChildNode::operator = ( const ChildNode& ChildToCopy ) {

	Parent = ChildToCopy.getParent();
	RightChild = ChildToCopy.getRight();
	LeftChild = ChildToCopy.getLeft();
	
	NodeElement = new Element;
	NodeElement->setKey() = ChildToCopy.getElement()->getKey();
	NodeElement->setContent() = ChildToCopy.getElement()->getContent();
	
	return *this;

}

ChildNode::~ChildNode() {

	Parent = nullptr;
	RightChild = nullptr;
	LeftChild = nullptr;

	delete NodeElement;

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

Element* const ChildNode::getElement() const {
	return NodeElement;
}


//--------------------------------| End |-------------------------------------


