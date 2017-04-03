#
#  To sa opcje dla kompilacji
#

CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11 

__start__: lab3
	./lab3

lab3: obj/main.o obj/Queue.o obj/Stack.o
	g++ -Wall -pedantic -o lab3 obj/main.o obj/Stack.o obj/Queue.o 

obj/main.o: src/main.cpp     
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp 

obj/Queue.o: src/Queue.cpp inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/Queue.o src/Queue.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp

clean:
	rm -f obj/*.o lab3
