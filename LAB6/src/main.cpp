#include <iostream>
#include "TestableDictionary.hh"
#include "DictionaryTestSettings.hh"
#include "Timer.hh"
#include <string>
#include <fstream>

const unsigned int NUMBER_OF_REALIZATION = 20;
const unsigned int NUMBER_OF_WORDS = 10000;
const unsigned int PROBLEM_SIZE = 20000;
const Flag ASCIISum = 1;


void Execute(TestableDictionary& Object, DictionaryTestSettings& Settings,Timer& Clock, std::string& Output ) {

	std::fstream OutputStream(Output, std::ios::out);

	std::cerr << std::endl << Output;

	for ( unsigned int idx = 1, var = 10; idx < PROBLEM_SIZE; idx+=var )	{
		Settings.ProblemSize() = idx; 
		Clock.Measure(Object,Settings);
		Clock.SaveSummarized(OutputStream);
		std::cerr << std::endl << idx;
		if ( idx > 1000)
			var = 1000;


	}

	OutputStream.close();

}

int main() {

	TestableDictionary Object;
	DictionaryTestSettings Settings;
	Timer Clock(NUMBER_OF_REALIZATION);
	std::string Output;

	Settings.NumberOfWords() = NUMBER_OF_WORDS;
	Settings.NumberOfRealization() = NUMBER_OF_REALIZATION;

	Output = "HashType_Multiplic";	
	Execute(Object,Settings,Clock,Output ) ;

	Settings.HashType() = ASCIISum ;
	Output = "HashType_ASCII";	
	Execute(Object,Settings,Clock,Output );

	

	return 0;


}
