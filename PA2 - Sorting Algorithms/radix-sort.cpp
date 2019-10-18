//============================================================================
// Name        : radix-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of radix sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> RadixSort::sort(vector<int> A, int size)
{
    /*
     Complete this function with the implementation of radix sort
     algorithm.
     */
    int max;
    max = A.at(0);
    for(int i = 1; i< size; ++i)
    {
        if(A.at(i) > A.at(i-1))
        {
            max = A.at(i);
        }
    }
    int temp = max;
    int maxDigits = 0;
    while(temp !=0)
    {
        temp/=10;
        maxDigits++;
    }

    int digitPlace = 1;
    for(int a = 1; a<maxDigits+1; a++)
    {
        
        vector<int> B(10,0);
        vector<int> C(size);
    
        for(int j = 0; j<size; j++)
        {
            B.at(((A.at(j)/digitPlace)%10))+=1;
        }
        for(int p = 1; p<10; p++)
        {
            B.at(p) += B.at(p-1);
        }
        for(int k = size -1 ; k>= 0; k--)
        {
            C.at(B.at((A.at(k)/digitPlace)%10)-1) = A.at(k);
            B.at((A.at(k)/digitPlace)%10)--;
        }
        for(int c = 0; c< size; c++)
        {
            A.at(c) = C.at(c);
        }
        
        digitPlace = digitPlace*10;
    }
  
    return A;
}

