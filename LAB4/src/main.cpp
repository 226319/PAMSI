#include <iostream>
#include "Tablica.hh"
#include "Tablica2.hh"
#include "Czasomierz.hh"
#include "Opcje.hh"
#include "QuickSort.hh"

#define ROZMIAR 10

int main() {

	Tablica obiekt(ROZMIAR);

	srand(time(NULL));
	
	for ( unsigned int i = 0; i < obiekt.Size(); ++i) 
		obiekt.ZmienElement(i) = rand() % 100;
	
	for ( unsigned int i = 0; i < obiekt.Size(); ++i) {
		std::cerr << obiekt.OdczytajElement(i) << ' ';
	}

	std::cerr << std::endl;

	QuickSort(obiekt,0,obiekt.Size());

	for ( unsigned int i = 0; i < obiekt.Size(); ++i) {
		std::cerr << obiekt.OdczytajElement(i) << ' ';
	}
	
	std::cerr << std::endl;



	return 0;
}


