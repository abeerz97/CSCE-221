// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
#include "TemplatedMy_matrix.h"

int main(){
  
  // Some test cases are expected to throw an exception.
  // Add more try and catch blocks as necessary for your code
  // to finish execution.
    
  try{
    
    // Test 1
    // * Create an object of type My_matrix, called m1, using constructor
    TemplatedMy_matrix<double> m1(4,5);
    // // * Initialize m1 in main (by assigning numbers to matrix elements)
    for(int i = 0; i<m1.number_of_rows(); i++)
    {
        for(int k = 0; k < m1.number_of_columns(); k++)
        {
            m1.elem(i,k) = i*k;
        }
    }
    cout<<"m1"<<endl<<m1;
    // * Display m1 on the screen using the operator <<
    
    // Test 2
    // * Create an object of type My_matrix, called m2, using (default)
    //   constructor
    TemplatedMy_matrix<double> m2;
    ifstream inFS("infile.txt");
    if(!inFS.is_open())
    {
        cout<<"Unable to open file"<<endl;
        return 1;
    }
    inFS>>m2;
    cout<<"m2"<<endl<<m2;
    // // // * Open an input file containing a matrix (row by row)
    // // // * Initialize m2 by reading from the input file using
    // // //   the operator >>
    // // // * Open an output file (can be empty)
    ofstream oFs("outfile.txt");
    oFs << m1;
    // // // // // * Write m2 to the output file using the operator <<
    
    // // // // // Test 3
    // // // // // * Use the copy constructor to make a copy of m1 called m3
    TemplatedMy_matrix<double> m3(m1);
    // // // // * Apply the copy assignment to m1 called m4
    TemplatedMy_matrix<double> m4 = m1;
    // // // // * Display m3 and m4 on the screen using the operator <<
    cout<<"m3"<<endl<<m3;
    cout<<"m4"<<endl<<m4;

    // // // // // Test 4
    // // // // // * Test the matrix multiplication operator (operator*)
    // cout<< m3 * m2;
    TemplatedMy_matrix<double> m5(5,4);
    for(int i = 0; i<m5.number_of_rows(); i++)
    {
        for(int k = 0; k < m5.number_of_columns(); k++)
        {
           m5.elem(i,k) = (i*k) + 12.13;
        }
    }
    cout<<"m5"<<endl<<m5;
    
    cout<<"m1*m5"<<endl<<m1*m5;
    // // // // // * Apply the multiplication operator to valid and invalid cases
    // // // // // * Display the resulting matrix and its number of rows and columns
   
    // // // // // Test 5
    // // // // // * Test the matrix addition operator (operator+)
    cout<<"m1 + m3"<<endl <<m1 + m3;
    cout<<"m2 + m4, illegal matrix addition"<<endl<< m2 + m4;
    // // // // // * Apply the multiplication operator to valid and invalid cases
    // // // // // * Display the resulting matrix and its number of rows and columns
    
  } catch(exception &error){
    cerr << "Error: " << error.what() << endl;
  }
}