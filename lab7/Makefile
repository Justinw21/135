main: main.o List.o Node.o Dictionary.o Person.o
	g++ -o main main.o List.o Node.o Dictionary.o Person.o

tests: tests.o List.o Node.o Dictionary.o Person.o
	g++ -o tests tests.o List.o Node.o Dictionary.o Person.o

main.o: main.cpp Dictionary.h List.h Node.h Person.h

tests.o: tests.cpp Dictionary.h List.h Node.h Person.h

List.o: List.cpp Node.h List.h Person.h

Node.o: Node.cpp Node.h Person.h

Dictionary.o: Dictionary.cpp Dictionary.h List.h Node.h Person.h

Person.o: Person.cpp Person.h

clean:
	rm -f *.o main tests