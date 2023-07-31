main: main.o stack.o Node.o queue.o
	g++ -std=c++11 -o main main.o stack.o queue.o Node.o

tests: tests.o stack.o Node.o queue.o doctest.h
	g++ -std=c++11 -o tests tests.o stack.o Node.o queue.o

main.o: main.cpp stack.h queue.h Node.h
	g++ -std=c++11 -c main.cpp

tests.o: tests.cpp stack.h queue.h Node.h doctest.h

stack.o: stack.cpp stack.h Node.h
	g++ -std=c++11 -c stack.cpp

queue.o: queue.cpp queue.h Node.h
	g++ -std=c++11 -c queue.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp

clean:
	rm -f *.o main tests a.out