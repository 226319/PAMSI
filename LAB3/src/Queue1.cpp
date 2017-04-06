#include "Queue.hh"

/*-----------------| Constructors and Destructors |-------------------*/


Queue::Queue( const unsigned int& QueSize ) {

	if ( QueSize <= 0 ){
		std::cerr << "Size must be greater than zero\n";
		exit(WrongSize);
	}
	
	int* que_tmp = new int[QueSize];

	if ( que_tmp != nullptr) {

	_Queue = que_tmp;
	_Size = QueSize;
	_Beginning = _FillLevel = _End = 0;
	que_tmp = nullptr;

	} else {
		std::cerr << "Not enough memory\n";
		exit(NotEnMem);
	}
	
}

Queue::~Queue() {

	if ( _Queue != nullptr ) {
		delete[] _Queue;
		_Size  = _FillLevel = _Beginning = _End = 0;
	}

}

/******************************| End |****************************************/


/*-----------------------------| Private Methods |---------------------------*/

Queue& Queue::operator=(const Queue& que) {
	if ( this != &que ){

		delete[] _Queue;
		_Queue = new int[que.Size()];
		_Size = que.Size();
		_Beginning = _FillLevel = _End = 0;
	}

	return *this;
}

bool Queue::HideElement( const unsigned int& Posi, const int& Key ) {

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
	return  (_FillLevel == _Size )  ? true : false;
}




/*-----------------------------| End |---------------------------------------*/



/*-----------------------------| Public Methods |---------------------------*/

unsigned int Queue::Size() const {
	return _Size;
}

bool Queue::Enqueue( const int& elem ) {
	
	bool state_var = true;

	if ( IsOverflowed() ) {

		state_var = false;
		std::cerr << "Queue is overflowed\n";
	
	}	else {
		
		_Queue[_End] = elem;
		_End = (_End+1) % _Size;
		++_FillLevel;
	
	}

	return state_var;
}


int Queue::Dequeue() {

	int tmp_var;

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
	return ( _FillLevel == 0 )? true : false;
}


void Queue::Testuj( const unsigned int& Key , const unsigned int& ElemPosition, const int& Nil) {

	Find(Key);
}

int Queue::Find( const int& Key ) {

	if ( IsEmpty() ) {
		std::cerr << "Queue is empty\n";
		exit(EmptyQueue);
	}
	
	int tmp_elem;
	unsigned int maxPosition;
	int tmp= -1;

	
	for ( unsigned int i = 0; i < _FillLevel ; ++i ) {
	
		tmp_elem = Dequeue();
		Enqueue(tmp_elem);
		if ( tmp_elem == Key ) {
				tmp = i;
			}
	}
	
	return tmp;
}


/*----------------------------------| End |------------------------------------------*/


