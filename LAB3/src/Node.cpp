#include "Node.hh"

Node::Node() {
	_Elem = 0;
	_PtrToNextNode = nullptr;
}

Node::Node( Element elem, Node& node ) {

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

void Node::SetNext(Node* node) {
	_PtrToNextNode = node;
}

Node* Node::Next() const {
	return _PtrToNextNode;
}

const Element& Node::GetElement() const {
	return _Elem;
}

Element& Node::SetElement() {
	return _Elem;
}









