OBJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

tests: tests.o BSTree.o Node.o 
	g++ -o tests tests.o BSTree.o Node.o 

tests.o: tests.cpp doctest.h Node.h BSTree.h 

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS) main tests tests.o