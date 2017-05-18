#ifndef _TREE_HH
#define _TREE_HH

#include "Node.hh"



class Tree {


	public:

		void Add(const Element&) = 0;
		void Delete(const Element&) = 0;
		const Element& Search(const Key&) = 0;

};




#endif
