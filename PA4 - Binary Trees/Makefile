all: Main

Main: BTree.o Main.o
	g++ -std=c++11 BTree.o Main.o -o run-tree

BTree.o: BTree.cpp BTree.h
	g++ -std=c++11 -c BTree.cpp

Main.o: Main.cpp BTree.h
	g++ -std=c++11 -c Main.cpp

clean:
	rm *.o Main
