#include "Stack.hh"

/*---------------------| Constructors and Destructors |------------------*/

Stack::Stack() {

	_Stack = nullptr;
	_Size = 0;
	_FillLevel = 0;

}


Stack::Stack(const unsigned int& StackSize ) {

	if ( StackSize <= 0 ) {
		std::string Exception = "Stack size must be greather than 0\n";
		throw Exception;
	}


	int* stack_tmp = new int[StackSize];

	_Stack = stack_tmp;
	_Size = StackSize;
	_FillLevel = 0;
	stack_tmp = nullptr;

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



bool Stack::HideElement(const unsigned int& Posit, const int& Key) {


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

bool Stack::Push( const int& Elem ) {

	bool state_var = true;

	if ( IsOverflowed() ) {
		state_var = false;
		std::string Exception = "Stack is overflowed\n";
		throw Exception;
	} else {
	this->_Stack[_FillLevel++] = Elem;
	}

	return state_var;

}

int Stack::Pop() {
	 
	if ( IsEmpty() ) 
	 {
		 std::string Exception = "Stack is empty. Can't pop next element\n";
		 throw Exception;
	 } 

	return _Stack[--_FillLevel];
}

int Stack::Find( const int& Key ) {

	Stack stack_tmp(_Size);
	
	int tmp_pos = -1;
	unsigned int maxPosition = _FillLevel-1;  

	for ( unsigned int i = 0  ; i <_Size ; ++i ) {
		int elem	= Pop();	
		stack_tmp.Push(elem);
		if ( Key == elem ){
			tmp_pos = maxPosition - i ;
			break;
		}
	}

	for ( int i = maxPosition-tmp_pos; i >= 0 ; --i ) {
		Push(stack_tmp.Pop());
	}

	return tmp_pos;
}




void Stack::Testuj( const unsigned int& Key, const unsigned int& ElemPosition , const int& Nil) {

	Find(Key);

}

/*---------------------------------| End |--------------------------------*/

