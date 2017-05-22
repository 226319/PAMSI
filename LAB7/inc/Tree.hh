#ifndef _TREE_HH
#define _TREE_HH

#include "Node.hh"
#include "Element.hh"


class Tree {


	public:
		virtual ~Tree() {};
		
		virtual void Add(const Component&) {};
//		virtual void Delete(const Component&) = 0;
//		virtual const Element& Search(const Key&) = 0;

};




#endif
