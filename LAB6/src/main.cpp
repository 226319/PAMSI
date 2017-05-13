#include <iostream>
#include "TestableDictionary.hh"
#include "DictionaryTestSettings.hh"
#include "Timer.hh"

const unsigned int NUMBER_OF_REALIZATION = 20;
const unsigned int NUMBER_OF_WORDS = 1000;
const unsigned int PROBLEM_SIZE = 100;



int main() {

	TestableDictionary Object;
	DictionaryTestSettings Settings;
	Timer Clock(NUMBER_OF_REALIZATION);

	Settings.NumberOfWords() = NUMBER_OF_WORDS;
	Settings.NumberOfRealization() = NUMBER_OF_REALIZATION;
	Settings.ProblemSize() = PROBLEM_SIZE;
	




	Clock.Measure(Object,Settings);
	Clock.SaveSummarized(std::cerr);




}
