//============================================================================
// Name        : sort.h
// Author      : Teresa Leyk
// Date        :
// Copyright   : 
// Description : Sort interface and various sorting algorithms in C++
//============================================================================

#ifndef SORT_H_
#define SORT_H_

#include <string>
#include <vector>
using namespace std;

class Sort {
protected:
    unsigned long num_cmps; // number of comparisons performed in sort function      
public:
  virtual vector<int> sort(vector<int> A, int size) = 0;    // main entry point
  virtual string sortName() { return "Not determined yet"; }
  bool testIfSorted(vector<int> A, int size);        // returns false if not sorted
    
  unsigned long getNumCmps() { return num_cmps; }  // returns # of comparisons
  void resetNumCmps() { num_cmps = 0; }
};

class SelectionSort:public Sort {	// SelectionSort class
public:
  vector<int> sort(vector<int> A, int size);		// main entry point
  string sortName() { return "SelectionSort"; }
};

class InsertionSort:public Sort {	// InsertionSort class
public:
  vector<int> sort(vector<int> A, int size);		// main entry point
  string sortName() { return "InsertionSort"; }
};

class BubbleSort:public Sort {		// BubbleSort class
public:
  vector<int> sort(vector<int> A, int size);		// main entry point
  string sortName() { return "BubbleSort"; }
};

class ShellSort:public Sort {		// ShellSort class
public:
  vector<int> sort(vector<int> A, int size);		// main entry point
  string sortName() { return "ShellSort"; }
};

class RadixSort:public Sort {		// RadixSort class
public:
  vector<int> sort(vector<int> A, int size);		// main entry point
  string sortName() { return "RadixSort"; }
};

#endif //SORT_H_
