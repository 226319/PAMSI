#ifndef _ELEMENT_HH
#define _ELEMENT_HH

#include <string>

typedef std::string Definition;
typedef std::string WatchWord;

class Element {

	public:

		virtual ~Element() {};
		
		virtual const Definition& getDefinition() const =0;
		virtual Definition& setDefinition() = 0;

		virtual const WatchWord& getWatchWord() const = 0;
		virtual WatchWord& setWatchWord() = 0;



};


#endif
