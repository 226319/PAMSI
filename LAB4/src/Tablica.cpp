#include "Tablica.hh"

/*---------------------| Konstruktory i destruktor |------------------------*/

Tablica::Tablica() { 
	_Rozmiar = 0; 
	_Tablica = nullptr; }


Tablica::~Tablica() { 
 	if ( _Tablica != nullptr) {
	delete[] _Tablica;
	_Tablica = nullptr;
	}
}


Tablica::Tablica( unsigned int NRozmiar ){
	assert( NRozmiar != 0 );
	int* tmp_tab = new int[NRozmiar];
	
	for (unsigned int i = 0; i < NRozmiar; ++i){
		tmp_tab[i] = 0;
	}

	_Tablica = tmp_tab;
	_Rozmiar = NRozmiar;
}
/*-----------------------| KONIEC |-------------------------------------*/

/*-----------------------| Metody prywatne |---------------------------*/

Tablica& Tablica::operator=(const Tablica& tab) {
	if ( this != &tab ){

		delete[] _Tablica;
		_Tablica = new int[tab.Rozmiar()];
		_Rozmiar = tab.Rozmiar();
	}

	return *this;
}


bool Tablica::Powieksz( unsigned int liczba ) {

	unsigned int NowyRozmiar_tmp = _Rozmiar + liczba;
	
	int* tmp_tab = new int[NowyRozmiar_tmp];


	for ( unsigned int i = 0; i < _Rozmiar; ++i ) {
		tmp_tab[i] = _Tablica[i];
	}
	
	delete [] _Tablica;
	_Rozmiar = NowyRozmiar_tmp;
	_Tablica = tmp_tab;
	

	return true;
	
}


unsigned int& Tablica::Rozmiar() {
	return _Rozmiar;
}
/*------------------------------| Koniec |--------------------------*/



/*----------------------| Metody publiczne |-------------------------*/

const unsigned int& Tablica::Size() const {
	return _Rozmiar;
}


int Tablica::OdczytajElement( const unsigned int& idx ) const { 
	/* Metoda Get. Pozwala na odczytanie elementu o numerze idx
	 */
	assert ( (idx < _Rozmiar) && (idx >= 0) );
	int tmp = _Tablica[idx];

	return tmp;
}

int& Tablica::ZmienElement( const unsigned int& idx ) {
	/* Metoda Ser. Pozwala na odczytanie elementu o numerze idx 
	 * w razie przekroczenia zakresu zwraca zwraca blad */

	assert (idx < _Rozmiar);
	return _Tablica[idx];
}

const unsigned int& Tablica::Rozmiar() const {
	return _Rozmiar;
}

bool Tablica::DodajElement(const unsigned int& Index, const int& Wart) {
	/* Dopisuje do tablicy nowy element jesli jest to ostatni element to powieksza
	 * tablice o róznicę pomiędzy indeksem potencjalnej wywolanej komorki a
	 * rzeczywistym rozmiarem. Jesli nie udalo sie powiekszyc wypisuje
	 * Zwraca true jesli wszystko poszlo ok
	 * Zwraca false jesli zabraklo pamieci na zaalokowanie wiekszej tablicy
	 */

	if ( Index >= ( _Rozmiar - 1 ) ) {
		
		try {
	   this->Powieksz( Index - _Rozmiar + 1);
		} catch( std::string W ){ 
		std::cerr << "Wyjątek: " << W;
		return false;
		}
	}
	
	this->ZmienElement(Index) = Wart;

 return true;	


}

void Tablica::Testuj(const unsigned int& WarPocz, const unsigned int& LiczbaElem, const int& Wartosc) {
	/* Testuje algorytm powiekszania tablicy
	 */

	*this = Tablica(WarPocz);
	for ( unsigned int idx = 0; idx < LiczbaElem; ++idx){
		this->DodajElement(idx,Wartosc);
	}

}
/*------------------------------| Koniec |--------------------------*/


