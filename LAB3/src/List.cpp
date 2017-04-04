#include "List.hh"


List::List() {
	_ptrToFirstNode = nullptr;
	_ptrToLastNode  = nullptr;
	_NumbOfNodes = 0;
}


List::~List() {
	Node* nptr_tmp =  _ptrToFirstNode;
		
	for ( unsigned int i = 0; nptr_tmp != nullptr ; ++i) {
		std::cerr << nptr_tmp << std::endl;
			nptr_tmp = nptr_tmp->Next();
			delete nptr_tmp;
	}
}

bool List::Add ( Element elem, Position posNum ) {

	bool state_var = true;

	if ( (posNum <=_NumbOfNodes ) {

			Node* nptr = _ptrToFirstNode;
			Node* newNode = new Node;
			
			newNode->SetElement(elem);

			if ( nptr == nullptr ) {
			
				_ptrToFirstNode = newNode;
				newNode->SetNext(nullptr);
			
			} else if ( nptr->Next() == nullptr ) {

				


/*
	if ( posNum <=_NumbOfNodes ) {
		
		Node* nptr = _ptrToFirstNode;
		Node* newNode = new Node;

		for ( unsigned int i = 0; i < posNum; ++i ) {
		   nptr = nptr->Next();
		}

		if ( nptr != nullptr ) {
			newNode->SetNext(nptr->Next());
			newNode->SetElement() = elem;
			nptr->SetNext(newNode);
		} else {
			_ptrToFirstNode = newNode;
		}
		
		++_NumbOfNodes;
	
	} else {
		// exception
		state_var = false;
	}

	return state_var; 
	*/
}

bool List::Remove(Position) {
	return false;
}


Element List::Get(Position) const {
	return 4;
}

int List::Size() const {
	return _NumbOfNodes;
}

Element List::Find(Element) {
	return 44;
}

void List::Testuj(const unsigned int&, const unsigned int&, const int&) {
	int malso;
}



