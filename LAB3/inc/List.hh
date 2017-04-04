#ifndef LIST_HH
#define LIST_HH

#include "Headers.hh"
#include "Testowalny.hh"
#include "IList.hh"
#include "Node.hh"


class List: public IList, public Testowalny
{

	Node* _ptrToFirstNode;
	Node* _ptrToLastNode;
	unsigned int _NumbOfNodes;

	public:

	List();
	virtual ~List();

	virtual bool Add(Element, Position);
	virtual bool Remove(Position);
	virtual Element Get(Position) const;
	virtual int Size() const;
	virtual Element Find(Element);
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);

};


#endif

	

