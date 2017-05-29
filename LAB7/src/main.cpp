#include "Timer.hh"
#include "TestableBSTree.hh"
#include "BSTreeTestSettings.hh"
#include <string>
#include <fstream>

typedef unsigned int Flag;
const unsigned int NUMBER_OF_REALIZATION = 20;
const unsigned int PROBLEM_SIZE = 9;
const Flag BalancedTree = 1;


void Execute(TestableBSTree& Object, BSTreeTestSettings& Settings,Timer& Clock, std::string& Output ) {

	std::fstream OutputStream(Output, std::ios::out);

	std::cout << Output << std::endl;

	for ( unsigned int idx = 1; idx < PROBLEM_SIZE; ++idx )	{
		Settings.ProblemSize() = pow(10,idx);; 
		Clock.Measure(Object,Settings);
		Clock.SaveSummarized(OutputStream);
		std::cout << idx << std::endl;
	}

	OutputStream.close();

}

int main() {

	TestableBSTree Object;
	BSTreeTestSettings Settings;
	Timer Clock(NUMBER_OF_REALIZATION);
	std::string Output;

	Settings.NumberOfRealization() = NUMBER_OF_REALIZATION;

	Settings.Balance() = BalancedTree ;
	Output = "BalancedTree";	
	Execute(Object,Settings,Clock,Output );

	

	return 0;


}



