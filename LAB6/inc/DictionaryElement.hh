#ifndef _WYRAZ_HH
#define _WYRAZ_HH


class DictionaryElement: public Element {

	Key	Word; 
	Definition WordDefinition;


	public:

	~DictionaryElement();
	
	const Definition& getDefinition() const;
	Definition& setDefinition();
	
	const Key& getKey() const;
	Key& setKey(); 
	

}






#endif
