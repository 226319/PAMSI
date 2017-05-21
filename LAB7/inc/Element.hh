#ifndef ELEMENT_HH
#define ELEMENT_HH

#include "Component.hh"

class Element : public Component {

	Key PositionNumber;
	Content ElementContent;


	public:

		~Element();
		
		Element();
		Element( const Key&, const Content& );
		
		const Key& getKey() const;
		Key& setKey();
		
		const Content& getContent() const;		
		Content& setContent();



};





#endif
