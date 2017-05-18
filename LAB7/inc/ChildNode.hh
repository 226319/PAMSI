#ifndef _CHILDNODE_HH
#define _CHILDNODE_HH

#include "Node.hh"

class ChildNode : public Node {


	ChildNode* Parent;
	ChildNode* RightChild;
	ChildNode* LeftChild;
	Element* NodeElement;


	public:

		const ChildNode*&	getLeft() const = 0;
		ChildNode*& setLeft() = 0;

		const ChildNode& getRight() const = 0;
		ChildNode*& setRight() = 0;

		const ChildNode& getParent() = 0 const;
		ChildNode*& setParent() = 0;

		const ChildNode*& getElement() = 0 const; 
		



}






#endif
