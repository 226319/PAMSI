#include "Node.hh"

/*--------------------------------| Constructors and destructor |----------------------------*/
Node::Node() {
	_Elem = 0;
	_PtrToNextNode = nullptr;
}

Node::Node( int elem, Node& node ) {

	_Elem = elem;
	_PtrToNextNode = &node;

}

Node::~Node() {

	if ( _PtrToNextNode != nullptr ) {
		_PtrToNextNode = nullptr;
		delete _PtrToNextNode;
		_Elem = 0;
	}
}

/*-------------------------------------| END |----------------------------*/



/*-----------------------------| Public methods |----------------------------*/

void Node::SetNext(Node* node) {
	_PtrToNextNode = node;
}

Node* Node::Next() const {
	return _PtrToNextNode;
}

const int& Node::GetElement() const {
	return _Elem;
}

int& Node::SetElement() {
	return _Elem;
}



/*--------------------------------| End |------------------------------------*/





