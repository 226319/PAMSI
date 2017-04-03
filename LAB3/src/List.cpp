#include "List.hh"


List::List() {
	_ptrToFirstNode = nullptr;
	_ptrToLastNode  = nullptr;
	_NumbOfNodes = 0;
}


List::~List() {
	delete _ptrToFirstNode;
	_ptrToLastNode = nullptr;
	_NumbOfNodes;
}

bool List::Add ( Element elem, Position posNum ) {

	bool state_var = true;
	if ( posNum <=_NumbOfNodes ) {
		
		Node* nptr = _ptrToFirstNode;
		Node* newNode = new Node;

		for ( unsigned int i = 0; i < (posNum-1); ++i ) {
		   nptr = nptr.Next();
		}

		newNode.SetNext = nptr.Next();
		newNode.SetElement = elem;

		nptr.SetNext()=newNode;
	
	} else {
		// exception
		state_var = false;
	}

	return state_var
}


