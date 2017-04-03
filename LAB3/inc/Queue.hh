#ifndef QUEUE_HH
#define QUEUE_HH


#include "IQueue.hh"
#include "Testowalny.hh"
#include "Headers.hh"

class Queue: public IQueue, public Testowalny {


	Element* _Queue;
	unsigned int _Size;
	unsigned int _Beginning;
	unsigned int _End;


	Queue& operator=(const Queue&);

	
	public:

	bool HideElement( const Position&, const Element& );
		Queue( unsigned int );
		~Queue();
		virtual unsigned int Size() const;
		virtual bool Enqueue( Element );
		virtual Element Dequeue();
		virtual bool IsOverflowed();
		virtual bool IsEmpty();
		virtual void Testuj(const unsigned int&, const unsigned int&, const int&);
		virtual int Find(const Element&);

};


#endif
