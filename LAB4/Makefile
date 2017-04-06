#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11 

__start__: lab4
	./lab4

lab4: obj/main.o obj/Tablica.o obj/Czasomierz.o obj/Testowalny.o obj/Tablica2.o obj/QuickSort.o
	g++ -Wall -pedantic -o lab4 obj/main.o obj/Testowalny.o obj/Tablica.o obj/Tablica2.o  obj/Czasomierz.o obj/QuickSort.o

obj/main.o: src/main.cpp inc/Opcje.hh    
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Tablica.o: src/Tablica.cpp inc/Tablica.hh inc/Testowalny.hh
	g++ ${CPPFLAGS} -o obj/Tablica.o src/Tablica.cpp

obj/Tablica2.o: src/Tablica2.cpp inc/Tablica2.hh inc/Testowalny.hh inc/Tablica.hh
	g++ ${CPPFLAGS} -o obj/Tablica2.o src/Tablica2.cpp

obj/QuickSort.o: src/QuickSort.cpp inc/QuickSort.hh 
	g++ ${CPPFLAGS} -o obj/QuickSort.o src/QuickSort.cpp

obj/Czasomierz.o: src/Czasomierz.cpp inc/Czasomierz.hh
	g++ ${CPPFLAGS} -o obj/Czasomierz.o src/Czasomierz.cpp

obj/Testowalny.o: src/Testowalny.cpp inc/Testowalny.hh
	g++ ${CPPFLAGS} -o obj/Testowalny.o src/Testowalny.cpp

clean:
	rm -f obj/*.o lab4
