#ifndef _ELEMENT_HH
#define _ELEMENT_HH

typedef std::string Definition;
typedef std::string WatchWord;

class Element {

	public:

		virtual ~Element();
		
		virtual const Definition getDefinition() const;
		virtual Definition& setDefinition();

		virtual const WatchWord& getWatchWord() const;
		virtual WatchWord& setWatchWord();



};


#endif
