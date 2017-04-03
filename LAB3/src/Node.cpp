#include "Node.hh"


Node::Node( Element elem, Node& node ) {

	_Elem = elem;
	_PtrToNextNode = node;

}

Node::~Node() {

	if ( _PtrToNextNode != nullptr ) {
		Node* nptr_tmp = _PtrToNextNode;

		delete *nptr_tmp;
	}
	_Elem = 0;
	delete  _PtrToNextNode;

}

Node& Node::SetNext() {
	return _PtrToNextNode;
}

const Node& Node::Next() const {
	return _PtrToNextNode;
}

const Element& Node::GetElement() const {
	return _Elem;
}

Element& Node::SetElement() {
	return _Elem
}









