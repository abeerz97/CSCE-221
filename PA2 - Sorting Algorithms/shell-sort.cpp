//============================================================================
// Name        : shell-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of shell sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

vector<int>
ShellSort::sort(vector<int> A, int size)
{
  /* Complete this function with the implementation of shell sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
    int minVal;
    int holdVar;
    for(int i = 2; i < size;i*=2)
    {
        for(int j = 0;j < size/i + 1;j++)
        {
            for(int k = 0 + j*i; k < j*i - 1 && k < size;k++)
            {
                for(int l = 0;l < k;l++)
                {
                    num_cmps++;
                    if(A[l] > A[k])
                    {
                        for(int m = l;m < k;m++)
                        {
                            holdVar = A[m];
                            A[m] = A[k];
                            A[k] = holdVar;
                        }
                        break;
                    }
                }
            }
            
        }
    }
    for(int i = 1;i < size;i++)
    {
        for(int j = 0;j < i;j++)
        {
            num_cmps++;
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
