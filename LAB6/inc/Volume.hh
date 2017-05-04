#ifndef _VOLUME_HH
#define _VOLUME_HH

#include "DictionaryElement.hh"
#include "Word.hh"
#include "List.hh"

#include <iostream>

typedef unsigned int NumberOfWords;
typedef unsigned int ElementNumber;
typedef std::string  Exception;

class Volume: public List {

	DictionaryElement* FirstWord;
	DictionaryElement* LastWord;
	NumberOfWords WordCounter;

	bool isOneElement() const;
	bool isMoreThanOneElement() const;
	bool isEmpty() const;
	bool isNotEmpty() const;
	bool isFirstWord() const;
	bool isSizeIsGreaterThan( const ElementNumber& ) const;
	bool isSearchedElement(DictionaryElement*&, const WatchWord& ) const;

	void RemoveAllElements();
	void RemoveElement(DictionaryElement*&);


	void AppendFirstWord( const Word& WordToAppend );
	void AppendWord( const Word& WordToAppend );
	
	void getElementToRemove(DictionaryElement*&, DictionaryElement*&);
	DictionaryElement* const getElement( const ElementNumber& ) const;
	DictionaryElement* SearchFromEnd(const ElementNumber& IndexOfElement) const;
	DictionaryElement* SearchFromBeginning(const ElementNumber& IndexOfElement) const; 

	void GoToTheNext(DictionaryElement*&);
	void setToNull(DictionaryElement*);

	void RangeException() const;
	void NotFoundException() const;
	inline ElementNumber HalfOfVolumeSize() const { return WordCounter/2; }
	inline ElementNumber IndexOfLastElement() const { return (WordCounter-1); }

	void PrependFirst( const Word& );
	void PrependOther( const Word& );

	public:

	Volume();
	Volume(const Volume&);
	Volume& operator=(const Volume&);

	virtual ~Volume();
	
	void Append(const Word&);

	const Word& getWord( const ElementNumber& ) const;
	/*
	void Remove( const WatchWord& );
	Word& setWord( const ElementNumber& );
*/
	const Word& Find( const WatchWord& );
	void Prepend( const Word&);

	const NumberOfWords& Size() const;





};


#endif
