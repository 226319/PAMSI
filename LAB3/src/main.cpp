#include "Headers.hh"
#include "Czasomierz.hh"
#include "Stack.hh"
#include "Queue.hh"
#include "Node.hh"
#include "List.hh"



int main() {

	Czasomierz timer(LICZBA_REALIZACJI);
	const unsigned int Key = 44;
	std::ofstream file;
	
	file.open("Stack.txt");


	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		Stack obiekt;
		std::cerr << "Iter: " << idx << std::endl;
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();

	file.open("Queue.txt");

	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		Queue obiekt;
		std::cerr << "Iter: " << idx << std::endl;
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();
	file.open("List.txt");

	for ( int idx = 1; idx <= LICZBA_POMIAROW; ++idx ){ 
		List obiekt;
		std::cerr << "Iter: " << idx << std::endl;
		timer.ZmierzCzas( obiekt,Key, pow( PODSTAWA, idx ) );
		timer.SkrocZapiszDo(file);	
	}

	file.close();

	return 0;
}
