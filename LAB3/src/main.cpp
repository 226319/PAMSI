#include "Headers.hh"
#include "Stack.hh"
#include "Queue.hh"


#define TEST 10
int main() {


	Queue mystack(TEST);


	mystack.Testuj(TEST,9,12);


	std::cout << ';';
	std::cout << std::endl << mystack.IsEmpty();
	std::cout << std::endl;



}
