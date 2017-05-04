#ifndef LIST_HH
#define LIST_HH

#include "Element.hh"
#include "Node.hh"

class List {

	public:
		virtual ~List() {};

		virtual void Append(const Element&) {};
/*	
		virtual void Prepend(const Element&) =0;
		virtual void Remove(const WatchWord&) = 0;

		virtual Element& setWord(const WatchWord&) = 0;
*/
		virtual const Element& getWord(const WatchWord&) const {};

};







#endif
