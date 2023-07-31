main: main.o sorts.o
	g++ -std=c++11 -o main main.o sorts.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

sorts.o: sorts.cpp sorts.h
	g++ -std=c++11 -c sorts.cpp

clean:
	rm -rf main *.o