//============================================================================
// Name        : bubble-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
vector<int>
BubbleSort::sort(vector<int> A, int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class Sort
  */
    bool swap = true;
    while(swap == true)
    {
        swap = false;
        for(int j = 1; j<size; ++j)
        {
            this->num_cmps++;
            if(A.at(j-1) > A.at(j))
            {
                int temp = A.at(j);
                A.at(j) = A.at(j-1);
                A.at(j-1) = temp;
                swap = true;
            }
            
        }
        
    }
    return A;
}
