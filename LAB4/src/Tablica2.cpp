#include "Tablica2.hh"

/*--------------------| Konstruktory i destruktor |---------------*/

Tablica2::Tablica2() { 
	_Rozmiar = 0; 
	_Tablica = nullptr;
}

Tablica2::~Tablica2() { 
}
		
Tablica2::Tablica2( unsigned int NRozmiar ){

	assert( NRozmiar != 0 );	
	int* tmp_tab = new int[NRozmiar];
	
	for ( unsigned int i = 0; i < NRozmiar; ++i){
		tmp_tab[i] = 0;
	}

	_Tablica = tmp_tab;
	_Rozmiar = NRozmiar;
}

/*--------------------------| Koniec |---------------------------*/

/*------------------------| Metody publiczne |------------------*/

Tablica2& Tablica2::operator=(const Tablica2& tab) {

	if ( this != &tab ){
		delete[] _Tablica;
		_Tablica = new int[tab.Rozmiar()];
		_Rozmiar = tab.Rozmiar();
	}

	return *this;
}

bool Tablica2::DodajElement(const unsigned int& Index, const int& Wart) {

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


void Tablica2::Testuj(const unsigned int& WarPocz, const unsigned int& LiczbaElem, const int& Wartosc) {
	*this = Tablica2(WarPocz);
	
	for ( unsigned int idx = 0; idx < LiczbaElem; ++idx){
		this->DodajElement(idx,Wartosc);
	}
}

/*--------------------------| Koniec |-----------------------*/



