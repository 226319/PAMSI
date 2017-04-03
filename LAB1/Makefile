#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11 

__start__: lab1
	./lab1

lab1: obj/main.o obj/funkcje.o  obj/Tablica.o obj/Pomiar.o 
	g++ -Wall -pedantic -o lab1 obj/main.o obj/Tablica.o obj/Pomiar.o obj/funkcje.o 

obj/main.o: src/main.cpp inc/funkcje.hh    
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp 

obj/Tablica.o: src/Tablica.cpp inc/Tablica.hh
	g++ ${CPPFLAGS} -o obj/Tablica.o src/Tablica.cpp

obj/funkcje.o: src/funkcje.cpp inc/funkcje.hh inc/Pomiar.hh inc/Tablica.hh
	g++ ${CPPFLAGS} -o obj/funkcje.o src/funkcje.cpp

obj/Pomiar.o: src/Pomiar.cpp inc/Pomiar.hh
	g++ ${CPPFLAGS} -o obj/Pomiar.o src/Pomiar.cpp

clean:
	rm -f obj/*.o lab1
