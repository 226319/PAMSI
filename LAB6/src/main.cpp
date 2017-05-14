#include <iostream>
#include "TestableDictionary.hh"
#include "DictionaryTestSettings.hh"
#include "Timer.hh"

const unsigned int NUMBER_OF_REALIZATION = 20;
const unsigned int NUMBER_OF_WORDS = 10000;
const unsigned int PROBLEM_SIZE = 1000000;



int main() {

	TestableDictionary Object;
	DictionaryTestSettings Settings;
	Timer Clock(NUMBER_OF_REALIZATION);

	Settings.NumberOfWords() = NUMBER_OF_WORDS;
	Settings.NumberOfRealization() = NUMBER_OF_REALIZATION;

	for ( unsigned int idx = 2; idx < PROBLEM_SIZE; idx*=10 )	{
		Settings.ProblemSize() = idx; 
		Clock.Measure(Object,Settings);
		Clock.SaveSummarized(std::cerr);
	}



}
