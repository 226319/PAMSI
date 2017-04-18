#include <iostream>
#include "Tablica.hh"
#include "Tablica2.hh"
#include "Czasomierz.hh"
#include "Opcje.hh"
#include "QSTest.hh"
#include "Funkcje.hh"
#include "QuickSort.hh"


#define TRYB 3
#define ROZM_MAKS 9

int main() {

	
	Czasomierz timer(LICZBA_REALIZACJI);

	std::fstream plik;
	std::string TrybD = "plo123";


 for ( int Sort = 1; Sort <= TRYB ; ++Sort) {

	 for ( int Tryb = 1; Tryb <= TRYB; ++Tryb ) {
		 std::string nazwa = "Sort/Sort";
		 nazwa += TrybD[Sort+2];
		 nazwa += TrybD[Tryb-1];
		 
		 plik.open(nazwa, std::ofstream::out );
	
			for ( int idx = 1; idx <= ROZM_MAKS; ++idx ){
			QSTest obiekt(pow( PODSTAWA, idx ));
			
			PrzygotujDane(pow( PODSTAWA, idx ),2);
		
			timer.ZmierzCzas( obiekt,Sort, pow( PODSTAWA, idx ) );
			timer.SkrocZapiszDo(plik);	
		}
	
		plik.close();
	}
 }	

	return 0;
}


