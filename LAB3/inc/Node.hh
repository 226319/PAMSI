#ifndef NODE_HH
#define NODE_HH

#include "Headers.hh"


class Node {


	int _Elem;
	Node* _PtrToNextNode;

	public:

	Node();
	Node(int,Node& );
	~Node();
	
	void  SetNext(Node*);
	Node* Next() const;
	const int& GetElement() const;
	int&  SetElement();


};

#endif

