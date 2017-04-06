#ifndef ISTACK_HH
#define ISTACK_HH

class IStack {


	public:
		virtual ~IStack() {} ;
		virtual unsigned int Size() const =0;
		virtual bool Push( const int& ) =0;
		virtual int Pop() =0;
		virtual bool IsEmpty()=0 ;
		virtual int Find(const int&)=0;

};

#endif
