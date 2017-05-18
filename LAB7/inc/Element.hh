#ifndef ELEMENT_HH
#define ELEMENT_HH

typedef unsigned int Key;
typedef std::string Content;

class Element {


	public:	
		
		const Key& getKey() const = 0;
		Ket& setKey() = 0;
		
		const Content& getContent() const = 0;		
		Content& setContent() = 0;



}





#endif
