#
#  To sa opcje dla kompilacji
#

CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11 

__start__: lab3
	./lab3

lab3: obj/main.o obj/Queue.o obj/Stack.o  obj/Node.o obj/List.o obj/Czasomierz.o
	g++ -Wall -pedantic -o lab3 obj/main.o obj/Stack.o obj/Queue.o  obj/Node.o obj/List.o obj/Czasomierz.o

obj/main.o: src/main.cpp     
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp 

obj/Czasomierz.o: src/Czasomierz.cpp inc/Czasomierz.hh
	g++ ${CPPFLAGS} -o obj/Czasomierz.o src/Czasomierz.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/Queue.o src/Queue.cpp

obj/Node.o: src/Node.cpp inc/Node.hh
	g++ ${CPPFLAGS} -o obj/Node.o src/Node.cpp

obj/List.o: src/List.cpp inc/List.hh
	g++ ${CPPFLAGS} -o obj/List.o src/List.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp

clean:
	rm -f obj/*.o lab3
