#ifndef LIST_HH
#define LIST_HH

#include "Element.hh"
#include "Node.hh"

class List {

	public:

		virtual void Append(const Element&);
		virtual void Remove(const WatchWord&);

		virtual const Element& getElement(const WatchWord&) const;
		virtual Element& setElement(const WatchWord&);


}







#endif
