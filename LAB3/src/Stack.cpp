#include "Stack.hh"

/*---------------------| Constructors and Destructors |------------------*/

Stack::Stack() {

	_Stack = nullptr;
	_Size = 0;
	_FillLevel = 0;

}


Stack::Stack(unsigned int StackSize ) {

	if ( StackSize <= 0 ) {
		std::cerr << "Stack size must be greather than 0\n";
		exit(WrongSize);
	}


	Element* stack_tmp = new Element[StackSize];

	if ( stack_tmp != nullptr ) {

		_Stack = stack_tmp;
		_Size = StackSize;
		_FillLevel = 0;
		stack_tmp = nullptr;

	} else {

		std::cerr << "Not enough memory\n";
		exit(NotEnMem);
	}


}


Stack::~Stack() {
	
		delete[] _Stack;
		_Size = 0;
		_FillLevel = 0;

}

/*---------------------------------| End |--------------------------------*/

/*------------------------| Private methods |----------------------------*/

Stack& Stack::operator=(const Stack& stack) {
	if ( this != &stack ){

		delete[] _Stack;
		_Stack = new int[stack.Size()];
		_Size = stack.Size();
	}

	return *this;
}



bool Stack::HideElement(Position Posit, Element Key) {


	if ( Posit >= _Size ) return false; 


	for ( unsigned int i = 0; i < Posit ; ++i ){
		Push( Key-1 );
	}

	Push(Key);

	for ( unsigned int i = _FillLevel; i < _Size; ++i ){
		Push(Key-1 );
	}

	return true;
}


bool Stack::IsOverflowed() {
	return  (_Size==_FillLevel)&&(_Size!=EMPTY) ? true : false ;
}

/*---------------------------------| End |--------------------------------*/


/*------------------------| Public methods |----------------------------*/

unsigned int Stack::Size() const {
	return _Size;
}

bool Stack::IsEmpty() {
	return  (_FillLevel==EMPTY) ? true : false ;
}

bool Stack::Push( const Element& Elem ) {

	bool state_var = true;

	if ( IsOverflowed() ) {
		std::cerr << "Stack is overflowed\n";
		state_var = false;
	} else {
	this->_Stack[_FillLevel++] = Elem;
	}

	return state_var;

}

Element Stack::Pop() {
	 if ( IsEmpty() ) {
		std::cerr << "Stack is empty. Can't pop next element\n";
		exit(EmptyStack);
	} 

	return _Stack[--_FillLevel];
}

int Stack::Find( const Element& Key ) {

	Element ElemArr[_Size];
	
	Position tmp_pos = -1;
	unsigned int maxPosition = _FillLevel-1;  

	for ( unsigned int i = 0  ; !IsEmpty() ; ++i ) {
		
		ElemArr[i] = Pop();
		if ( Key == ElemArr[i] ){
			tmp_pos = maxPosition - i ;
			break;
		}
	}

	for ( int i = maxPosition-tmp_pos; i >= 0 ; --i ) {
		Push(ElemArr[i]);
	}

	return tmp_pos;
}




void Stack::Testuj( const unsigned int& initCond, const Position& ElemPosition , const Element& Key) {

	*this = Stack(initCond);
	HideElement( ElemPosition, Key);
	Find(Key);

}

/*---------------------------------| End |--------------------------------*/

