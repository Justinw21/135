main: main.o OList.o Node.o
	g++ -o main main.o OList.o Node.o

tests: tests.o OList.o Node.o 
	g++ -o tests tests.o OList.o Node.o

main.o: main.cpp OList.h Node.h

tests.o: tests.cpp OList.h Node.h

List.o: List.cpp Node.h List.h

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h Node.h

clean:
	rm -f main.o Node.o OList.o tests.o main tests