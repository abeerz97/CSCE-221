all: Main

Main: SkipList.o Main.o
	g++ -std=c++11 SkipList.o Main.o -o run-slist

SkipList.o: SkipList.cpp SkipList.h
	g++ -std=c++11 -c SkipList.cpp

Main.o: Main.cpp SkipList.h
	g++ -std=c++11 -c Main.cpp

clean:
	rm *.o Main
