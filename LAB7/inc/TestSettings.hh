#ifndef _TESTSETTINGS_HH_
#define _TESTSETTINGS_HH_


class TestSettings {

	public:
	 virtual const	unsigned int& ProblemSize() const  = 0;
	 virtual const unsigned int& NumberOfRealization() const = 0;	

};



#endif
