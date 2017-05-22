#ifndef _CHILDNODE_HH
#define _CHILDNODE_HH

#include "Node.hh"
#include "Element.hh"

class ChildNode : public virtual Node {


	ChildNode* Parent;
	ChildNode* RightChild;
	ChildNode* LeftChild;
	Element* NodeElement;


	public:

		
		ChildNode();
		ChildNode(const ChildNode&);
		ChildNode(const Element&);
		ChildNode& operator = (const ChildNode&);
		virtual ~ChildNode();
		
		ChildNode* const getLeft() const;
		void setLeft(ChildNode*& ) ;

		ChildNode* const getRight() const;
		void setRight(ChildNode*& ) ;

		ChildNode* const getParent()  const;
		void setParent(ChildNode*& ) ;

		Element* const getElement()  const; 

		inline bool isEmpty() const {
			return ( NodeElement == nullptr );
		}
		



} ;






#endif
