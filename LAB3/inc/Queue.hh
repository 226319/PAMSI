#ifndef QUEUE_HH
#define QUEUE_HH


#include "IQueue.hh"
#include "Testowalny.hh"
#include "Headers.hh"
#include "List.hh"

class Queue: public IQueue, public Testowalny {


	List _Queue;

	bool HideElement( const unsigned int&, const int& );
	public:


	// IQueue methods
	virtual unsigned int Size() const;
	virtual bool Enqueue(const int&);
	virtual int Dequeue();
	virtual bool IsEmpty();
	virtual int Find(const int&);
	
	// Testowalny methods	
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);
	virtual bool PrzygotujDoTestu(const unsigned int&, const unsigned int&);
};


#endif
