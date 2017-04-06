#ifndef QUEUE_HH
#define QUEUE_HH


#include "IQueue.hh"
#include "Testowalny.hh"
#include "Headers.hh"

class Queue: public IQueue, public Testowalny {


	int* _Queue;
	unsigned int _Size;
	unsigned int _FillLevel;
	unsigned int _Beginning;
	unsigned int _End;


	Queue& operator=(const Queue&);
	virtual bool IsOverflowed();

	
	public:

	Queue( const unsigned int& );
	~Queue();
	bool HideElement( const unsigned int&, const int& );

	// IQueue methods
	virtual unsigned int Size() const;
	virtual bool Enqueue(const int&);
	virtual int Dequeue();
	virtual bool IsEmpty();
	virtual int Find(const int&);
	
	// Testowalny methods	
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);

};


#endif
