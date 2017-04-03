#include "Queue.hh"

/*-----------------| Constructors and Destructors |-------------------*/


Queue::Queue( unsigned int QueSize ) {

	if ( QueSize <= 0 ){
		std::cerr << "Size must be greater than zero\n";
		exit(WrongSize);
	}
	
	Element* que_tmp = new Element[QueSize];

	if ( que_tmp != nullptr) {

	_Queue = que_tmp;
	_Size = QueSize;
	_Beginning = 0;
	_End = 0;
	que_tmp = nullptr;

	} else {
		std::cerr << "Not enough memory\n";
		exit(NotEnMem);
	}
	
}

Queue::~Queue() {

	if ( _Queue != nullptr ) {
		delete[] _Queue;
		_Size  = _Beginning = _End = 0;
	}

}

/******************************| End |****************************************/


/*-----------------------------| Private Methods |---------------------------*/

Queue& Queue::operator=(const Queue& que) {
	if ( this != &que ){

		delete[] _Queue;
		_Queue = new int[que.Size()];
		_Size = que.Size();
		_Beginning = 0; 
		_End = 0;
	}

	return *this;
}

bool Queue::HideElement( const Position& Posi, const Element& Key ) {

	if ( Posi < _Size) {
	
	for ( unsigned int i = 0; i < Posi; ++i) {
		Enqueue(Key-1);
	}

	Enqueue(Key);

	for ( unsigned int i = Posi+1; i < _Size; ++i) {
		Enqueue(Key-1);
	}
	
	} else {
		std::cerr << "Position can't be greater than Queue size\n";
		return false;
	}



return true; 
}





bool Queue::IsOverflowed() {
	return  (_Queue[_End] != 0)  ? true : false;
}




/*-----------------------------| End |---------------------------------------*/



/*-----------------------------| Public Methods |---------------------------*/

unsigned int Queue::Size() const {
	return _Size;
}

bool Queue::Enqueue( Element elem ) {
	
	bool state_var = true;

	if ( IsOverflowed() ) {

		state_var = false;
		std::cerr << "Queue is overflowed\n";
	
	}	else {
		
		_Queue[_End] = elem;
		_End = (_End+1) % _Size;
	
	}

	return state_var;
}

Element Queue::Dequeue() {

	Element tmp_var;

	if ( IsEmpty() ) {
		std::cerr << "\nQueue is empty can't dequeue an element\n";
		exit(EmptyQueue);
	}

	tmp_var = _Queue[_Beginning];
	_Queue[_Beginning] = 0;
	_Beginning = (_Beginning+1) % _Size;

	return tmp_var;
}

bool Queue::IsEmpty() {
	return ( (_Beginning==_End) && (_Queue[_End] == 0) )? true : false;
}

void Queue::Testuj( const unsigned int& initCond , const unsigned int& ElemPosition, const int& Key) {

	*this = Queue(initCond);
	HideElement(ElemPosition,Key);
	Find(Key);
}

int Queue::Find( const Element& Key ) {

	if ( IsEmpty() ) {
		std::cerr << "Queue is empty\n";
		exit(EmptyQueue);
	}
	
	Element tmp_elem;
	Position maxPosition;
	int tmp= -1;

	if ( _End <= _Beginning ) maxPosition = (_Size - _Beginning) + _End;
	else maxPosition = _End-_Beginning;
	
	for ( unsigned int i = 0; i < maxPosition ; ++i ) {
	
		tmp_elem = Dequeue();
		Enqueue(tmp_elem);
		if ( tmp_elem == Key ) {
				tmp = i;
			}
	}
	
	return tmp;
}




