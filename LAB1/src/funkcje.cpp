#include "funkcje.hh"



bool Algorytm(unsigned int Tryb) {
	Pomiar Pom;
	
	std::string NazwaPliku = "./Sprawozdanie/pliki/Alg_strat_";

	if ( ( Tryb == O1 ) || Tryb == RAZY2 )	{
		NazwaPliku += std::to_string(Tryb) + ".txt";
		std::ofstream Plik(NazwaPliku, std::ofstream::out );
	
		for ( int idx = 1; idx <= N ; ++idx ){
			Zmierz( pow(ROZM_PACZKI,idx), Pom, Tryb);
			Plik << Pom;
		}
		Plik.close();

	} else {
		return false;
	}

	return true;
}


void Strategia1 ( Tablica& tabl, const unsigned int& LiczbaElem) {
		for ( int idx = 0; idx < LiczbaElem ; ++idx) {
			tabl.DodajElement(idx,rand() % PRZEDZIAL);
		}
}

void Strategia2( Tablica& tabl, const unsigned int& LiczbaElem) {

	for ( int idx = 0; idx < LiczbaElem ; ++idx) {
			tabl.DodajElement2(idx,rand() % PRZEDZIAL);
	}
}


void Zmierz ( const unsigned int LiczbElem, Pomiar & pom,const unsigned int& Tryb ) {
	
	pom.LiczbaElementow() = LiczbElem;	

	for ( int idx = 0; idx < LICZBA_POMIAROW; ++idx) { // wykonaj pomiary dla LiczbyElementow
		Tablica Tab(ROZM_TABLICY);
		clock_t czas;
		srand(time(NULL));

		std::cerr << std::endl;
		std::cerr << "Iter: " << idx << " Elem: "<< LiczbElem;
		std::cerr << std::endl;

		if ( Tryb == O1) {
			czas = clock();   // zacznij mierzyc czas
			Strategia1(Tab, LiczbElem); // zwieksz rozmiar o 1 element
			czas = clock() - czas;  // koniec mierzenia czasu
			pom.Wynik(idx) = (double)czas/CLOCKS_PER_SEC ; // zapisz czas
	
		}	else if ( Tryb == RAZY2) {
			czas = clock();   // zacznij mierzyc czas
			Strategia2(Tab, LiczbElem); // zwieksz rozmiar dwukrotnie
			czas = clock() - czas;  // koniec mierzenia czasu
			pom.Wynik(idx) = (double)czas/CLOCKS_PER_SEC ; // zapisz czas
		}	
	
	}
 
}
