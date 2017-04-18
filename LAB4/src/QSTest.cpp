#include "QSTest.hh"



QSTest::QSTest(const unsigned int& Rozmiar) {
		
	_tab = Tablica(Rozmiar);

}

QSTest::~QSTest(){}




void QSTest::WczytajTablice() {

	std::ifstream plik("tmp/TestTab.tmp", std::ios::binary);

	if ( plik.fail() ) {
		std::string wyjatek = "\nNie znaleziono: tmp/TestTab.tmp";
		throw wyjatek;
	}

	for ( unsigned int idx = 0; idx < _tab.Size(); ++idx ) {
		plik >> _tab.ZmienElement(idx);
		if ( plik.fail() ) {
			std::string wyjatek = "\nBlad odczytu: tmp/TestTab.tmp";
			throw wyjatek;
		}
	}

	plik.close();

}


QSTest& QSTest::operator=(const QSTest& TmpQs) {

	if ( this != &TmpQs ) 
		_tab = Tablica(TmpQs.Rozmiar());

	return *this;

}

unsigned int QSTest::Rozmiar() const {
	return _tab.Size();
}


void QSTest::PrzygotujDoTestu( const unsigned int& WarPocz, const int& zm2) {
 
	WczytajTablice();

}

void QSTest::Testuj(const unsigned int& WarPocz, const unsigned int& zm1, const int& zm2 ) {

	QuickSort(_tab,WarPocz);
	
}







