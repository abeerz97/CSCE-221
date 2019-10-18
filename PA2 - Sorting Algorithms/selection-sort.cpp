//============================================================================
// Name        : selection-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort::sort(vector<int> A, int size)				// main entry point
{
  /* Complete this function with the implementation of selection sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */

	vector<int> B;
	int min;
	int minIndex;
	for(int i = 0; i < size - 1; ++i)
	{
		for(int k = 0; k< size - i - 1; ++k)
		{
			min = A.at(i);
			minIndex = i;
			this->num_cmps++;
			if(A.at(k) < A.at(i))
			{
				min = A.at(k);
				minIndex = k;
			}
		}
		B.at(i) = min;
		A.erase(k);
	}
	A.clear();
	for(int a = 0; a<size-1; ++a)
	{
		A.at(a) = B.at(a);
	}
	return A;
}
