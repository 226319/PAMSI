#ifndef LIST_HH
#define LIST_HH

#include "Element.hh"
#include "Node.hh"

class List {

	public:
		virtual ~List() {};

		virtual void Append(const Element&) {};
		virtual void Prepend(const Element&){};
		virtual void Remove(const WatchWord&){};

		virtual Element& setWord(const WatchWord&){};
		virtual Element& Find( const WatchWord& ){};
		virtual const Element& getWord(const WatchWord&) const {};

};







#endif
