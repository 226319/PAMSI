#ifndef _Dictionary_HH
#define _Dictionary_HH

#include <cmath>
#include "HashTable.hh"
#include "Volume.hh"

typedef unsigned int NumberOfVolumes;
typedef unsigned int VolumeNumber;
typedef unsigned int Flag;
typedef double Key;
const double HashBase = 129;
const double HashConst = 0.6180339887;

class Dictionary: public HashTable {

	Volume* VolumeList;
	bool isFound;
	NumberOfVolumes DictionarySize;
	Flag HashFunctionType;


	const VolumeNumber MultiplicHash(const WatchWord&) const;
	const VolumeNumber ASCIISumHash(const WatchWord&) const;
	const VolumeNumber Hash(const WatchWord&) const;
	//void Rehash(const WatchWord&);
	Word& CreateNewWord(const WatchWord& );
	void Append(const Word&) ;
	inline void ExecuteException( const Exception& Exc ) const { std::cerr << Exc; } 

	Word* setWord(const WatchWord&);
	Word& Find( const WatchWord& ) const;
	Word& setAppendedWord( const WatchWord& );
	const Word* getWord(const WatchWord&) const ;
	inline NumberOfVolumes& Size() { return DictionarySize; }


	
	public:

	virtual ~Dictionary();
	Dictionary(const NumberOfVolumes& );

	const Definition& operator[]( const WatchWord& ) const;
	Definition& operator[]( const WatchWord& );
	inline const NumberOfVolumes& Size() const { return DictionarySize; }
	void Remove(const WatchWord&);
	void SetHashFunctionType(const Flag&);

	void Show();
};







#endif
