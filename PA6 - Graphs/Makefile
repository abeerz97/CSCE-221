all: Main

Main: Graph.o Main.o
	g++ -std=c++11 Graph.o Main.o -o run-graph

Graph.o: graph.cpp graph.h
	g++ -std=c++11 -c graph.cpp

Main.o: main.cpp graph.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o Main
