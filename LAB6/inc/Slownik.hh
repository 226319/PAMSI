#ifndef _SLOWNIK_HH
#define _SLOWNIK_HH

typedef std::string Haslo;

class Slownik {

	Tom* ListaTomow;


	void ZmienHasloNaKlucz();


	public:

	const Wyraz& operator[]( const& Haslo) const;
	Wyraz& operator[]( const& Haslo);


}






#endif
