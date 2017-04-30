#ifndef _NODE_HH
#define _NODE_HH

#include "Element.hh"


class Node {

	public:

	const Node& getNext() const;
	Node& setNext();

	const Element& getElement() const;
	Element& setElement();



}





#endif
