#ifndef QUICK_HH
#define QUICK_HH


#include <iostream>
#include "Tablica.hh"


void QuickSort( Tablica&, const unsigned int&);
int PodzielTablice(Tablica&, const unsigned int&, const unsigned int&);
int PodzielTabliceLosowo(Tablica&, const unsigned int& , const unsigned int&);
void QuickSort(Tablica&, const unsigned int&, const unsigned int&);
void  QuickSortLosowy(Tablica&, const unsigned int&, const unsigned int&);
void ZamienElementy(Tablica&, const unsigned int&, const unsigned int&);
int Losuj(const unsigned int&, const unsigned int&); 
int PodzielTabliceMedianaZTrzech(Tablica&, const unsigned int& , const unsigned int&);
void QuickSortMedianaZTrzech( Tablica&,const unsigned int&,const unsigned int&);
const unsigned int& Losuj2(const unsigned int&,const unsigned int&);

#endif
