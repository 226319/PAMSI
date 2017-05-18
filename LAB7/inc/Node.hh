#ifndef _NODE_HH
#define _NODE_HH

#include "Element.hh"


class Node {


	public:

		const Node&	getLeft() const = 0;
		Node& setLeft() = 0;

		const Node& getRight() const = 0;
		Node& setRight() = 0;

		const Node& getParent() = 0;
		Node& setParent() = 0;

		const Element& getElement() const  = 0;


};



#endif
