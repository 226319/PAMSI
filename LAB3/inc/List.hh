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
	virtual bool HideElement(const unsigned int&, const int&);

	// IList methods
	virtual ~List();
	virtual bool Add( const int&,const unsigned int&);
	virtual bool Remove(const unsigned int&);
	virtual int Get(const unsigned int&) const;
	virtual unsigned int Size() const;
	virtual int Find(const int&);
	
	// Testowalny methods	
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);

};


#endif

	

