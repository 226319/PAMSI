#include "QuickSort.hh"



int PodzielTablice( Tablica& array, const unsigned int& PoczatekPodzialu, const unsigned int& KoniecPodzialu) {


	int indeksPodzialu = PoczatekPodzialu;  //(KoniecPodzialu-PoczatekPodzialu-1)/2;
	int wartoscPodzialu = array.OdczytajElement(indeksPodzialu);
	int i = PoczatekPodzialu - 1;
	int k = KoniecPodzialu + 1;
	int tmp = 0;


   while ( true ) {

	 do {--k;} while( array.OdczytajElement(k) > wartoscPodzialu );
	 do {++i;} while( array.OdczytajElement(i) < wartoscPodzialu ); 
		 
		 if ( i < k ) {
			tmp = array.OdczytajElement(i);
			array.ZmienElement(i) =  array.OdczytajElement(k);
			array.ZmienElement(k) = tmp;
		
		 } else return k;
	 }	 
} 

void  QuickSort( Tablica& array, const unsigned int & PoczatekPodzialu, const unsigned int & KoniecPodzialu) {

	if (PoczatekPodzialu < KoniecPodzialu){
		int q = PodzielTablice(array,  PoczatekPodzialu, KoniecPodzialu);
			QuickSort(array,  PoczatekPodzialu, q);
			QuickSort(array,  q+1, KoniecPodzialu);

	}
}




