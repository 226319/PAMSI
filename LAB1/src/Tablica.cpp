#include "Tablica.hh"

Tablica::Tablica() { _Rozmiar = 0; }

Tablica::Tablica( unsigned int NRozmiar ){
	int* tmp_tab = new int[NRozmiar];
	
	for ( int i = 0; i < NRozmiar; ++i){
		tmp_tab[i] = 0;
	}

	_Tablica = tmp_tab;
	_Rozmiar = NRozmiar;
}


Tablica::~Tablica() { 
	delete[] _Tablica;
}

Tablica& Tablica::operator=(const Tablica& tab) {
	if ( this != &tab ){

		delete[] _Tablica;
		_Tablica = new int[tab.Rozmiar()];
		_Rozmiar = tab.Rozmiar();
	}

	return *this;
}

bool Tablica::Powieksz( unsigned int liczba ) {

	int NowyRozmiar_tmp = _Rozmiar + liczba;
	int* tmp_tab = new(std::nothrow) int[NowyRozmiar_tmp];

	if ( tmp_tab == nullptr ) {
	
		std::string Wyjatek = " Nie mozna zaalokowac pamieci";
		throw Wyjatek;
	
	} else {

	for ( int i = 0; i < _Rozmiar; ++i ) {
		tmp_tab[i] = _Tablica[i];
	}
	
	delete [] _Tablica;
	_Rozmiar = NowyRozmiar_tmp;
	_Tablica = tmp_tab;
	
	}

	return true;
	
}


unsigned int& Tablica::Rozmiar() {
	return _Rozmiar;
}

int Tablica::OdczytajElement( unsigned int idx ) const { 
	return _Tablica[idx];
}

int& Tablica::ZmienElement( unsigned int idx ) {
	return _Tablica[idx];
}

const unsigned int& Tablica::Rozmiar() const {
	return _Rozmiar;
}

bool Tablica::DodajElement(const unsigned int Index, const int Wart) {
	/* dodajemy element jesli index ostatniego elementu jest 
	 * mniejszy od rozmiaru to powieksza tablice o 1
	 */

	if ( Index >= ( _Rozmiar - 1 ) ) {
		
		try {
	   this->Powieksz( Index - _Rozmiar + 1);
		} catch( std::string W ){ 
		std::cerr << "Wyjątek: " << W;
		}
	}
	
	this->ZmienElement(Index) = Wart;

 return true;	


}

bool Tablica::DodajElement2(const unsigned int Index, const int Wart) {

	if ( Index >= (_Rozmiar - 1) ) {
		
		try{
		this->Powieksz(_Rozmiar);
		} catch( std::string W) {
		std::cerr << "Wyjatek: " << W;
		}
	}
	
	this->ZmienElement(Index) = Wart;

 return true;	
}







