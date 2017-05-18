#ifndef ELEMENT_HH
#define ELEMENT_HH

typedef unsigned int Key;
typedef std::string Content;

class Element {

	Key PositionNumber;
	Content ElementContent;


	public:

		~Element();
		
		Element();
		Element( const Key&, const Content& );
		
		const Key& getKey() const;
		Ket& setKey();
		
		const Content& getContent() const;		
		Content& setContent();



};





#endif
