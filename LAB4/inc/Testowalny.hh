#ifndef _TESTOWA_HH_
#define _TESTOWA_HH_

class Testowalny {
	
	public:
//		virtual void PrzygotujDoTestu(const unsigned int&, const int&) = 0;
		virtual void Testuj(const unsigned int&, const unsigned int&, const int&)=0;
		virtual ~Testowalny(){ };

};

#endif

