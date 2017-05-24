#ifndef COMPONENT_HH
#define COMPONENT_HH

#include <string>

typedef unsigned int Key;
typedef std::string Content;

class Component {


	public:

		virtual ~Component() {} ;
		
		virtual const Key& getKey() const = 0;
		virtual Key& setKey() = 0;
		
		virtual const Content& getContent() const = 0;		
		virtual Content& setContent() = 0;



};





#endif
