#ifndef IQUEUE_HH
#define IQUEUE_HH

class IQueue {

	public:
		
		virtual ~IQueue() {};
		virtual unsigned int Size() const =0;
		virtual bool Enqueue(const int& )=0; // jesli sie powiodlo true
		virtual int Dequeue()=0;				// jesli sie powiodlo true
		virtual bool IsEmpty()=0;
		virtual int Find(const int&)=0;
};


#endif
