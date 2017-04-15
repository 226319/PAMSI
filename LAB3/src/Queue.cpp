#include "Queue.hh"

/*-----------------| Constructors and Destructors |-------------------*/



/******************************| End |****************************************/


/*-----------------------------| Private Methods |---------------------------*/

bool Queue::HideElement( const unsigned int& Posi, const int& Key ) {
	
	bool state_var;

		
		for ( unsigned int i = 1; i < Posi; ++i) {
			 state_var = Enqueue(Key-1);
		}
		state_var = Enqueue(Key);

	
	return state_var; 
}

/*-----------------------------| End |---------------------------------------*/



/*-----------------------------| Public Methods |---------------------------*/

unsigned int Queue::Size() const {
	return _Queue.Size();
}

bool Queue::Enqueue (const int& elem ) {
	
	bool state_var;
	
	state_var = _Queue.Add(elem,_Queue.Size());

	return state_var;
}


int Queue::Dequeue() {

	int tmp_var;

	if ( IsEmpty() ) {
		std::string Exception = "Queue is empty can't dequeue an element\n";
		throw Exception;
	}

	tmp_var = _Queue.Get(0);
	_Queue.Remove(0);

	return tmp_var;
}

bool Queue::IsEmpty() {
	return ( _Queue.Size() == 0 )? true : false;
}


void Queue::Testuj( const unsigned int& Key , const unsigned int& ElemPosition, const int& Nil) {

	Find(Key);
}

int Queue::Find( const int& Key ) {

	if ( IsEmpty() ) {
		std::string Exception = "Queue is empty can't dequeue an element\n";
		throw Exception;	
	}
	
	int tmp_elem;
	int tmp= -1;

	
	for ( unsigned int i = 0; i < _Queue.Size() ; ++i ) {
		
		tmp_elem = Dequeue();
		Enqueue(tmp_elem);
		if ( tmp_elem == Key ) {
				tmp = i;
			}
	}
	
	return tmp;
}

bool Queue::PrzygotujDoTestu(const unsigned int& NumOfElem, const unsigned int& Key) {
	
	return HideElement(NumOfElem,Key);
}


/*----------------------------------| End |------------------------------------------*/


