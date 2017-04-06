#ifndef STACK_HH
#define STACK_HH

#include "Headers.hh"
#include "Testowalny.hh"
#include "IStack.hh"

#define EMPTY 0

class Stack: public Testowalny, public IStack
{ 

		int* _Stack;
		unsigned int _Size;
		unsigned int _FillLevel;

		bool IsOverflowed();
		Stack& operator=( const Stack&);
	
	public:
	
		Stack();
		Stack(const unsigned int&);
		bool HideElement(const unsigned int&, const int&);
		
		// IStack methods
		virtual ~Stack();
		virtual unsigned int Size() const;
		virtual bool Push(const int&);
		virtual int Pop();
		virtual bool IsEmpty();
		virtual int Find(const int&);
	
		// Testowalny methods
		virtual void Testuj( const unsigned int&, const unsigned int&, const int&);

};



#endif
