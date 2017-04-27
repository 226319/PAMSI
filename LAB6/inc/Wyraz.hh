#ifndef _WYRAZ_HH
#define _WYRAZ_HH

typedef std::string Definicja;
typedef unsigned int Klucz;



class Wyraz {

	Klucz	Slowo; 
	Definicja DefinicjaSlowa;


	public:
	
	const Definicja& Definicja() const;
	Definicja& ZmienDefinicje();
	

}






#endif
