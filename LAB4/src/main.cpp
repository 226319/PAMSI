#include <iostream>
#include "Tablica.hh"
#include "Tablica2.hh"
#include "Czasomierz.hh"
#include "Opcje.hh"
#include "QuickSort.hh"

#define ROZMIAR 10

int main() {

	Tablica obiekt(ROZMIAR);

	std::cerr << obiekt.Size() <<  std::endl;
	srand(time(NULL));
	
	for ( unsigned int i = 0; i < obiekt.Size(); ++i) 
		obiekt.ZmienElement(i) = 5;//rand() % 100;
	
	for ( unsigned int i = 0; i < obiekt.Size(); ++i) {
		std::cerr << obiekt.OdczytajElement(i) << ' ';
	}

	std::cerr << std::endl;
	std::cerr << obiekt.Size() <<  std::endl;

	QuickSort(obiekt,0,obiekt.Size()-1);

	for ( unsigned int i = 0; i < obiekt.Size(); ++i) {
		std::cerr << obiekt.OdczytajElement(i) << ' ';
	}
	
	std::cerr << std::endl;

	std::cerr << obiekt.Size() <<  std::endl;


	return 0;
}


