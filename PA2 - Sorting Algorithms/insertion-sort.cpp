//============================================================================
// Name        : insertion-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"
#include <vector>

vector<int> InsertionSort::sort(vector<int> A, int size)				// main entry point
{
    int holdVar;
    for(int i = 1;i < size;i++)
    {
        for(int j = 0;j < i;j++)
        {
            this->num_cmps++;
            if(A[j] > A[i])
            {
                for(int k = j;k < i;k++)
                {
                    holdVar = A[k];
                    A[k] = A[i];
                    A[i] = holdVar;
                }
                break;
            }
        }
        
    }
    return A;
}
