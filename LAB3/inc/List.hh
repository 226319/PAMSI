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

	void InsertNode(Node*, Node*);
	void InsertToBeginning(Node*);
	void InsertToEnd(Node*);
	
	void RemoveNode(Node*, Node*);
	void RemoveFromBeginning();
	void RemoveFromEnd(Node*);
	Node* GoToNode(const unsigned int&);
	
	public:

	bool HideElement(const unsigned int&, const int&);
	List();

	// IList methods
	virtual ~List();
	virtual bool Add( const int&,const unsigned int&);
	virtual bool Remove(const unsigned int&);
	virtual int Get(const unsigned int&) const;
	virtual unsigned int Size() const;
	virtual int Find(const int&);
	
	// Testowalny methods	
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);
	virtual bool PrzygotujDoTestu(const unsigned int&, const unsigned int&);

};


#endif

	

