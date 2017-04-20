#include <iostream>
#include "Tablica.hh"
#include "Tablica2.hh"
#include "Czasomierz.hh"
#include "Opcje.hh"
#include "QSTest.hh"
#include "Funkcje.hh"
#include "QuickSort.hh"


#define TRYB 3
#define ROZM_MAKS 8

int main() {

	
	Czasomierz timer(LICZBA_REALIZACJI);

	std::fstream plik;
	std::string TrybD = "plo123";



 for ( int Sort = 1; Sort <= TRYB ; ++Sort) {    
	 // Zmiana rodzaju pivota 1 - Pierwszy z lewej, 2- Losowy, 3- Mediana z trzech

	 for ( int Tryb = 1; Tryb <= TRYB; ++Tryb ) {  
		 // Zmiana rodzaju sanych 1 - rosnąco, 2- losowo, 3 - malejaco
		
		 std::string nazwa = "Sort/Sort";
		 nazwa += TrybD[Sort+2];
		 nazwa += TrybD[Tryb-1];
		 
		 plik.open(nazwa, std::ofstream::out );

		 std::cerr << std::endl << nazwa << std::endl;
	
			for ( int idx = 1; idx <= ROZM_MAKS; ++idx ){
				QSTest obiekt(pow( PODSTAWA, idx ));
			
				std::cerr << std::endl << idx << std::endl;
				PrzygotujDane(pow( PODSTAWA, idx ),Tryb);
		
				timer.ZmierzCzas( obiekt,Sort, pow( PODSTAWA, idx ) );
				timer.SkrocZapiszDo(plik);	
		}
	
		plik.close();
	}
 }	
	return 0;
}


