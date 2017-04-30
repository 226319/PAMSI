#ifndef _NODE_HH
#define _NODE_HH

#include "Element.hh"


class Node {

	public:
	
	virtual ~Node() {};

	virtual const Node* const getNext() const = 0;
	virtual void setNext(Node*) = 0;

	virtual const Element& getWord() const = 0;
	virtual Element& setWord() = 0;


};





#endif
