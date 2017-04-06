#include "List.hh"


/*-----------------------| Constructor and Destructor |------------------------*/

List::List() {
	_ptrToFirstNode = nullptr;
	_ptrToLastNode  = nullptr;
	_NumbOfNodes = 0;
}


List::~List() {

		
		for ( Node* nptr_tmp = _ptrToFirstNode ; nptr_tmp != nullptr ; ) {
			
			nptr_tmp = _ptrToFirstNode->Next();
			delete _ptrToFirstNode;
			_ptrToFirstNode = nptr_tmp;
			
		}
		
		delete _ptrToFirstNode;	
		_ptrToLastNode = nullptr;
		_NumbOfNodes = 0;

}

/*------------------------------| End |---------------------------------*/




/*----------------------------| Public Methods |------------------------------*/

bool List::Add ( const int& elem, const unsigned int& posNum ) {

	bool state_var = true;

	if ( posNum <=_NumbOfNodes ) {

			Node* newNode = new Node;
			
			newNode->SetElement()=elem;
			
			if ( !_NumbOfNodes ) {  // jezeli lista jest pusta
			
				newNode->SetNext(_ptrToFirstNode);
					_ptrToFirstNode = newNode;
					_ptrToLastNode = newNode;
			
			} else if ( posNum == _NumbOfNodes){  // jezeli dodajemy na koniec
				
				_ptrToLastNode->SetNext(newNode);
				newNode->SetNext(nullptr);
				_ptrToLastNode=newNode;
			
			} else if ( posNum == 0 ) {   // jezeli dodajemy na poczatek
				
				newNode->SetNext(_ptrToFirstNode);
				_ptrToFirstNode = newNode;

			} else {  // jezeli dodajemy posrodku

				Node* nptr = _ptrToFirstNode;

				for ( unsigned int i = 1; i < posNum; ++i ) {
					nptr = nptr->Next();
				}

				newNode->SetNext(nptr);
				nptr->SetNext(newNode);
			}

				++_NumbOfNodes;
		
	}	else {
		state_var = false;
		std::string Exception = "Wrong position number\n";
		throw Exception;
	}

	return state_var;
}

bool List::Remove(const unsigned int& posNum) {

	bool state_var = true;


	if ( _NumbOfNodes == 0 ) { 

		state_var = false;
		std::string Exception = "List is empty\n";
		throw Exception;
   
	} else if ( posNum < _NumbOfNodes ) {

			Node* nptr = _ptrToFirstNode;
			
			if ( posNum == _NumbOfNodes-1 ){  // jezeli usuwamy z konca
				
				for ( unsigned int i = 1; i < posNum; ++i ) { 
					//idziemy do przed ostatniego wezla 
					nptr = nptr->Next();
				}
				
				nptr->SetNext(nullptr);
				delete _ptrToLastNode;
				_ptrToLastNode = nptr;

				if ( _NumbOfNodes == 1 ) {   // w przypadku jedynego elementu
					_ptrToFirstNode = nullptr;
				}

			} else if ( posNum == 0 ) {   // jezeli usuwamy z poczatku
				
				_ptrToFirstNode = _ptrToFirstNode->Next();
				delete nptr;	

			} else {  // jezeli usuwamy posrodku

				Node* nptr2 = _ptrToFirstNode;

				for ( unsigned int i = 1; i < posNum; ++i ) {
					nptr = nptr->Next();
				}
				
				nptr2 = nptr->Next();
				nptr->SetNext( nptr2->Next() );

				nptr2->SetNext( nullptr );
				delete nptr2;
			}

				--_NumbOfNodes;
		
	}	else {
	
		state_var = false;
		std::string Exception = "Wrong position number\n";
		throw Exception;
	
	}

	return state_var;
	
}


int List::Get(const unsigned int& posNum) const {

	Node* nptr = _ptrToFirstNode;
	
	
	if ( posNum < _NumbOfNodes ) {
		if ( posNum == _NumbOfNodes-1 ) nptr = _ptrToLastNode;
		else if ( posNum != 0 ) {
		
			for ( unsigned int i = 0; i < posNum; ++i ) {
				nptr = nptr->Next();
			}
		}

	} else {
		std::string Exception = "Wrong position number\n";
		throw Exception;
	}
	return nptr->GetElement();
}
		

unsigned int List::Size() const {
	return _NumbOfNodes;
}

int List::Find(const int& Key) {
	
	int posi = 0;
	Node* nptr = _ptrToFirstNode;

	for ( unsigned int i = 0; i < _NumbOfNodes; ++i ) {
			if ( nptr->GetElement() == Key ) {
				posi = i;
				break;
			}
			nptr=nptr->Next();
	}
		
	return posi;
}


bool List::HideElement( const unsigned int& position, const int& Key) {
	bool state_var = Add(Key,0);


	if ( state_var ) {

		for ( unsigned int i = 1; i < position; ++i ) {
			state_var = Add(Key-1, 0);
			if ( !state_var ) break;
		}
		
	}

	return state_var;
}



void List::Testuj(const unsigned int& Key, const unsigned int& NuOfElem, const int& Nil ) {
	Find(Key);
}

/*------------------------------| End |---------------------------------*/

