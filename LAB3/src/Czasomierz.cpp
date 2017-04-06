#include "Czasomierz.hh"
#include <iostream>


/*------------------| Konstruktory i destruktor |--------------------------*/

Czasomierz::Czasomierz() {
	_wynik = nullptr;
}

Czasomierz::Czasomierz( const unsigned int & LiczbaRealiz ) {

	assert( LiczbaRealiz != 0 ); 	 // sprawdza czy jest rozne od zera

	double * Wynik_tmp = new double[LiczbaRealiz];
	
	for ( unsigned int i = 0; i < LiczbaRealiz; ++i ) {
		Wynik_tmp[i] = 0;
	}

	_wynik = Wynik_tmp;
	this->LiczbaRealizacji() = LiczbaRealiz;
}

Czasomierz::~Czasomierz() {
	delete[] _wynik;
	_wynik = nullptr;
}

/*-----------------------| Koniec |----------------------------------------*/



/*--------------------------| Metody Get i Set |---------------------------*/

clock_t& Czasomierz::Czas() { return _czas;}
unsigned int& Czasomierz::LiczbaElementow() { return _licz_elem;}
unsigned int& Czasomierz::LiczbaRealizacji() { return _liczba_realizacji;}
double& Czasomierz::Wynik(const unsigned int& i) { return _wynik[i];}
const clock_t& Czasomierz::Czas() const { return _czas;}
const unsigned int& Czasomierz::LiczbaElementow() const { return _licz_elem;}
const unsigned int& Czasomierz::LiczbaRealizacji() const { return _liczba_realizacji;}
const double& Czasomierz::Wynik(const unsigned int& i) const { return _wynik[i];}
/*---------------------------|Koniec|--------------------------------------*/




/*------------------------| Metody prywatne |------------------------------*/

double Czasomierz::Srednia() const {
	/* Wylicza srednia z pomiaru */

	assert( this->LiczbaRealizacji() != 0 );          // Nie wykonuje jesli LiczbaRealizacji = 0

	double srednia = 0;
	for ( unsigned int i = 0 ; i < this->LiczbaRealizacji(); ++i ){
		srednia += _wynik[i];
	}
	
	return srednia/this->LiczbaRealizacji();
}

void Czasomierz::CzasStart() {
	this->Czas() = clock();
}

void Czasomierz::CzasStop( const unsigned int& NrRealizacji) {
	/* Konczy mierzenie czasu i zapisuje pomiar do tablicy
	 * zapobiega pisaniu poza tablica 
	 */

	assert( NrRealizacji < this->LiczbaRealizacji());  // sprawdza czy nie probujemy pisac po pamieci
	this->Czas() = clock() - this->Czas();
	this->Wynik(NrRealizacji) = (double)_czas/CLOCKS_PER_SEC ;  
}

/*---------------------------|Koniec|--------------------------------------*/




/*--------------------------|Metody publiczne|-----------------------------*/

bool Czasomierz::ZmierzCzas( Testowalny & Obiekt, const unsigned int & WarPocz, const unsigned int& LiczbaElementow) {

	if ( WarPocz ) {
		srand(time(NULL));
		this->LiczbaElementow() = LiczbaElementow;
		for ( unsigned int i = 0; i < this->LiczbaRealizacji(); ++i){
			 this->CzasStart();
			 Obiekt.Testuj(WarPocz, this->LiczbaElementow(), rand() % PRZEDZIAL);
			 this->CzasStop(i);
		}
		return true;

	} else return false;
}

void Czasomierz::ZapiszDo(std::ostream & in ) const  {
	
	in << this->LiczbaElementow() << ' ';
	in << std::setprecision(PRECYZJA) << std::fixed;
	for ( unsigned int i = 0; i < this->LiczbaRealizacji() ; ++i){
		in << this->Wynik(i);
		in << ' ';
	}
	in << this->Srednia() << std::endl;
}

void Czasomierz::SkrocZapiszDo(std::ostream & in ) const  {
	
	in << this->LiczbaElementow() << ' ';
	in << std::setprecision(PRECYZJA) << std::fixed;
	in << this->Srednia() << std::endl;
}

/*--------------------| Koniec |--------------------------*/
