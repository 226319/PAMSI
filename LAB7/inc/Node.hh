#ifndef _NODE_HH
#define _NODE_HH

#include "Component.hh"

enum Color { RED , BLACK };

class Node {


	public:

		virtual ~Node(){} ;

		virtual Node* const getLeft() const {} ;
		virtual void setLeft(Node*&) {};

		virtual Node* const getRight() const {};
		virtual void setRight(Node*&){}; 

		virtual Node* const getParent() {};
		virtual void setParent(Node*&) {};

		virtual Component* const getElement() const {};
		
		virtual const Color& getColor() const = 0;
		virtual Color& setColor() = 0;

};



#endif
