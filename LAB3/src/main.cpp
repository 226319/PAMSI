#include "Headers.hh"
#include "Czasomierz.hh"
#include "Stack.hh"
#include "Queue.hh"
#include "Node.hh"
#include "List.hh"
#define LICZBA_POMIAROW 9



int main() {

	Czasomierz timer(LICZBA_REALIZACJI);
	const unsigned int Key = 44;
	const unsigned int Position = 0;

	std::ofstream file;
	file.open("Stack.txt");

	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		int LiczbaElem = pow(PODSTAWA, idx);
		Stack obiekt(LiczbaElem);
		std::cerr << "Iter: " << idx << std::endl;

		obiekt.HideElement(Position,Key);
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();

	file.open("Queue.txt");

	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		int LiczbaElem = pow(PODSTAWA, idx);
		Queue obiekt;
		std::cerr << "Iter: " << idx << std::endl;

		obiekt.HideElement(LiczbaElem,Key);
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();

	file.open("List.txt");

	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		int LiczbaElem = pow(PODSTAWA, idx);
		List obiekt;
		std::cerr << "Iter: " << idx << std::endl;

		obiekt.HideElement(LiczbaElem,Key);
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();

	return 0;
}

