#ifndef LIST_HH
#define LIST_HH

#include "Element.hh"
#include "Node.hh"

class List {

	public:
	
		virtual ~List() {};

		virtual void Append(const Element&) = 0;
		virtual void Remove(const WatchWord&) = 0;

		virtual const Element& getElement(const WatchWord&) const = 0;
		virtual Element& setElement(const WatchWord&) = 0;


}







#endif
