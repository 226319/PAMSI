#ifndef IQUEUE_HH
#define IQUEUE_HH

#include "TypeDefs.hh"

class IQueue {

	public:
		
		virtual ~IQueue() {};
		virtual unsigned int Size() const =0;
		virtual bool Enqueue( Element )=0; // jesli sie powiodlo true
		virtual Element Dequeue()=0;				// jesli sie powiodlo true
		virtual bool IsOverflowed()=0;
		virtual bool IsEmpty()=0;
		virtual int Find(const Element&)=0;
};


#endif
