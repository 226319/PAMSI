#ifndef NODE_HH
#define NODE_HH

#include "TypeDefs.hh"
#include "Headers.hh"


class Node {


	Element _Elem;
	Node* _PtrToNextNode;


	public:

	Node( Element, Node& );
	~Node();
	Node& SetNext();
	const Node& Next() const;
	const Element& GetElement() const;
	Element& SetElement();


};

#endif

