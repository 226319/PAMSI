#ifndef QSTEST_HH
#define QSTEST_HH

#include <iostream>
#include <fstream>
#include "Tablica.hh"
#include "Testowalny.hh"
#include "QuickSort.hh"

class QSTest : public Testowalny
{


	Tablica _tab;
	
	void WczytajTablice();

	public:

	QSTest(const unsigned int& Rozmiar);
	~QSTest();
	QSTest& operator=(const QSTest&);

	unsigned int Rozmiar() const;
	virtual void PrzygotujDoTestu(const unsigned int&, const int&);
	virtual void Testuj(const unsigned int&, const unsigned int&, const int&);

};











#endif
