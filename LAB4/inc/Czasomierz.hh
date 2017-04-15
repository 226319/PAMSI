#ifndef _CZASOMIERZ_HH_
#define _CZASOMIERZ_HH_

#include "Opcje.hh"
#include "Testowalny.hh"

class Czasomierz {

	double *_wynik;
	unsigned int _licz_elem;
	clock_t _czas;
	unsigned int _liczba_realizacji;

	unsigned int& LiczbaElementow();
	unsigned int& LiczbaRealizacji();
	double& Wynik(const unsigned int&);
	clock_t& Czas();
	const unsigned int& LiczbaElementow() const;
	const unsigned int& LiczbaRealizacji() const;
	const double& Wynik(const unsigned int&) const;
	const clock_t& Czas() const;
	
	double Srednia() const;
	void CzasStart();
	void CzasStop(const unsigned int &);
	
	public:
	Czasomierz();
	Czasomierz( const unsigned int& LiczbaRealizacji );
	~Czasomierz();

	bool ZmierzCzas( Testowalny &, const unsigned int&, const unsigned int&);	
	void ZapiszDo(std::ostream & in) const;
	void SkrocZapiszDo(std::ostream & in) const;

};

#endif 

