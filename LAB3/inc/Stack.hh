#ifndef STACK_HH
#define STACK_HH

#include "Headers.hh"
#include "Testowalny.hh"
#include "IStack.hh"

#define EMPTY 0

class Stack: public Testowalny, public IStack
{ 

		Element* _Stack;
		unsigned int _Size;
		unsigned int _FillLevel;

		bool IsOverflowed();
		Stack& operator=( const Stack&);
	
	public:
	
		bool HideElement( unsigned int, Element);
		Stack();
		Stack( unsigned int );
		virtual ~Stack();
		
		// IStack methods
		virtual unsigned int Size() const;
		virtual bool Push(const Element&);
		virtual Element Pop();
		virtual bool IsEmpty();
		virtual int Find(const Element&);
	
		// Testowalny methods
		virtual void Testuj( const unsigned int&, const unsigned int&, const int&);

};



#endif
