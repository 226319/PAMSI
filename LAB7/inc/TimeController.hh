#ifndef _TIME_CONTROLLER_HH
#define _TIME_CONTROLLER_HH

#include "BSTreeTestSettings.hh"
#include "Testable.hh"
#include <iostream>

class TimeController {

	public:
		virtual ~TimeController() {};
		virtual void Measure( Testable&, const BSTreeTestSettings& ) = 0;
		virtual void Save( std::ostream& ) const =0;
		virtual void SaveSummarized( std::ostream & ) const =0;


};










#endif
