#ifndef _TIMER_HH
#define _TIMER_HH

#define PRECISION 8
#define ZERO 0

#include <iostream>
#include <iomanip>
#include "Testable.hh"
#include "TimeController.hh"
#include "DictionaryTestSettings.hh"

typedef double* ResultsTable;
typedef std::string Exception;

class Timer: public TimeController {

	ResultsTable _Results;
	unsigned int _ProblemSize;
	clock_t _TestTime;
	unsigned int _NumberOfRealization;
	
	public:
	
	Timer();
	Timer( const unsigned int& );
	~Timer();

	void Measure( Testable &, const DictionaryTestSettings& );	
	void Save(std::ostream & ) const;
	void SaveSummarized(std::ostream & ) const;

	private:

	unsigned int& ProblemSize();
	unsigned int& NumberOfRealization();
	double& Result(const unsigned int&);
	clock_t& TestTime();
	
	const unsigned int& ProblemSize() const;
	const unsigned int& NumberOfRealization() const;
	const double& Result(const unsigned int&) const;
	const clock_t& TestTime() const;
	

	inline unsigned int isSomethingWasRealized() const 
	{ return _NumberOfRealization; };	

	void SaveResult( const unsigned int&);
	void MemoryViolenceException();
	double SumOfResults() const; 
	double Average() const;
	
	void Start();
	void Stop(const unsigned int &);
};

#endif 

