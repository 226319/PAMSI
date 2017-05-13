#include "Timer.hh"


/*------------------| Konstruktory i destruktor |--------------------------*/

Timer::Timer() {
	_Results = nullptr;
	_ProblemSize = 0;
	_NumberOfRealization = 0;
}

Timer::Timer( const unsigned int & RealizationNumber ) {


	double * Result_tmp = new double[RealizationNumber];
	
	for ( unsigned int i = 0; i < RealizationNumber; ++i ) {
		Result_tmp[i] = 0;
	}

	_Results = Result_tmp;
	_NumberOfRealization = RealizationNumber;

}

Timer::~Timer() {
	delete[] _Results;
	_Results = nullptr;
}

/*-----------------------| Koniec |----------------------------------------*/



/*--------------------------| Metody Get i Set |---------------------------*/

clock_t& Timer::TestTime() { return _TestTime;}
unsigned int& Timer::ProblemSize() { return _ProblemSize;}
unsigned int& Timer::NumberOfRealization() { return _NumberOfRealization;}
double& Timer::Result(const unsigned int& i) { return _Results[i];}
const clock_t& Timer::TestTime() const { return _TestTime;}
const unsigned int& Timer::ProblemSize() const { return _ProblemSize;}
const unsigned int& Timer::NumberOfRealization() const { return _NumberOfRealization;}
const double& Timer::Result(const unsigned int& i) const { return _Results[i];}
/*---------------------------|Koniec|--------------------------------------*/




/*------------------------| Metody prywatne |------------------------------*/

double Timer::SumOfResults() const {

	double Mean = 0;

	for ( unsigned int i = 0 ; i < NumberOfRealization(); ++i ){
		Mean += _Results[i];
	}
		
	return Mean;
}

double Timer::Average() const {

	 if ( isSomethingWasRealized() )
		 return SumOfResults()/NumberOfRealization();
	 else 
		 return ZERO;

}

void Timer::SaveResult( const unsigned int& RealizationNumber) {

	_TestTime = clock() - _TestTime;
	Result(RealizationNumber) = (double)_TestTime/CLOCKS_PER_SEC ;  

}

void Timer::Start() {
	TestTime() = clock();
}

void Timer::Stop( const unsigned int& RealizationNumber) {

	if ( RealizationNumber < NumberOfRealization() ) {
		SaveResult(RealizationNumber);  
	} else MemoryViolenceException();
}

void  Timer::MemoryViolenceException() {

	Exception Exc = "\nOver the range\n";
	throw Exc;
}

/*---------------------------|Koniec|--------------------------------------*/




/*--------------------------|Metody publiczne|-----------------------------*/
void Timer::Measure( Testable & Object, const DictionaryTestSettings& Settings ) {

		ProblemSize() = Settings.ProblemSize();
		Object.PrepareToTest(Settings);
	
		for ( unsigned int i = 0; i < NumberOfRealization(); ++i){
			 Start();
			 Object.Test(Settings);
			 Stop(i);
		}
}

void Timer::Save(std::ostream & in ) const  {
	
	in << ProblemSize() << ' ';
	in << std::setprecision(PRECISION) << std::fixed;

	for ( unsigned int i = 0; i < NumberOfRealization() ; ++i){
		in << Result(i);
		in << ' ';
	}
	
	in << Average() << std::endl;
}

void Timer::SaveSummarized(std::ostream & in ) const  {
	
	in << ProblemSize() << ' ';
	in << std::setprecision(PRECISION) << std::fixed;
	in << Average() << std::endl;
}

/*--------------------| Koniec |--------------------------*/
