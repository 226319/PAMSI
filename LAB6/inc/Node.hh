#ifndef _NODE_HH
#define _NODE_HH

#include "Element.hh"


class Node {

	public:
	
	virtual ~Node() {};

	virtual Node* const getNext() const = 0;
	virtual void setNext(Node*) {};

	virtual const Element& getWord() const = 0;
	virtual Element& setWord() = 0;

	virtual Node* const getPrevious() const = 0;
	virtual void setPrevious(Node*) {};

};





#endif
