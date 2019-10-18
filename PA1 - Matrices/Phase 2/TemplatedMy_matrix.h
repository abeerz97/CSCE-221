/* TemplatedMy_matrix.h

Header file for the class TemplatedMy_matrix

Write your name and UIN here
Syed Abeer Hasan Zaidi 
325005243

*/

#include <iostream>
#include <exception>
#include <stdexcept>


using namespace std;
// Definitions of user defined type exceptions 
struct invalid_input : public exception {
  virtual const char* what() const throw()
  { return "Invalid matrix input"; }
};

struct incompatible_matrices : public exception {
  virtual const char* what() const throw()
  { return "Incompatible matrices"; }
};
template <typename T>
class TemplatedMy_matrix {
	
  //member variables
  int n, m;
  T **ptr;
  void allocate_memory();  // optional
  
public:	
  //member functions
  TemplatedMy_matrix();  // default constructor
  TemplatedMy_matrix(T n1, T m1); // parameter constructor
  ~TemplatedMy_matrix(); // destructor
  TemplatedMy_matrix(const TemplatedMy_matrix& mat); // copy constructor
  // TemplatedMy_matrix(TemplatedMy_matrix&& mat);  // move constructor (optional)
  TemplatedMy_matrix& operator=(const TemplatedMy_matrix& mat); //copy assignment operator
  // TemplatedMy_matrix& operator=(TemplatedMy_matrix&& mat); // move assignment operator (optional)
  int number_of_rows() const; 
  void clear();
  int number_of_columns() const;
  T* operator()(int i) const; // overloaded to access to ith row
  T& operator()(int i, int j); // overloaded to access (i,j) element
  T operator()(int i, int j) const; // overloaded to access (i,j) element
  T elem(int i, int j) const; // overloaded to access (i,j) element
  T& elem(int i, int j); // overloaded to access (i,j) element
};

// see the handout for the description of these operators
template <typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat);
template <typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat);
template <typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);
template <typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);

/* 
Implementation of the clas TemplatedMy_matrix
*/



template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix()
{
  // add your code here
  n = 0;
  m = 0;
  ptr = nullptr;

}

// void TemplatedMy_matrix::allocate_memory()
// {
//   // add your code here
// }
template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(T n1, T m1)
{
  // add your code here
  n = n1;
  m = m1;
  ptr = new T*[n];
  for(int a = 0; a < n; a++)
  {
    ptr[a] = new T[m];
  }
}
template <typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(const TemplatedMy_matrix<T>& mat)
{
  // add your code here
  this->n = mat.number_of_rows();
  this->m = mat.number_of_columns();
  ptr = new T*[n];
  for(int j = 0; j< n; j++)
  {
    ptr[j] = new T[m];
  }

  for(int i = 0; i < n; i++)
  {
    for(int b = 0; b < m; b++)
    {
      elem(i,b) = mat.elem(i,b);
    }
  }

}

// // move constructor (optional)
// template <typename T>
// TemplatedMy_matrix::TemplatedMy_matrix(TemplatedMy_matrix&& mat)
// {
//   // add your code here
// }
template <typename T>
TemplatedMy_matrix<T>::~TemplatedMy_matrix()
{
  // add your code here
  clear();
  
}
template <typename T>
void TemplatedMy_matrix<T>::clear()
{
  for(int i = 0; i< n; i++)
  {
    delete [] ptr[i];
  }
  delete [] ptr;
}

template <typename T>
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(const TemplatedMy_matrix<T>& mat)
{
  // add your code here
  this->n = mat.number_of_rows();
  this->m = mat.number_of_columns();
  this->ptr = new T*[n];
  for(int j = 0; j< n; j++)
  {
    ptr[j] = new T[m];
  }

  for (int i = 0; i < this->n; i++)
    {
      for (int j= 0; j < this->m; j++)
        {
          this->elem(i,j)= mat.elem(i,j);
      }
    }
    return *this;
}

// // move assignment operator (optional)
// TemplatedMy_matrix& TemplatedMy_matrix::operator=(TemplatedMy_matrix&& mat)
// {
//   // add your code here
// }
template <typename T>
int TemplatedMy_matrix<T>::number_of_rows() const
{
  // add your code here
  return n;
}
template <typename T>
int TemplatedMy_matrix<T>::number_of_columns() const
{
  // add your code here
  return m;
}
template <typename T>
T* TemplatedMy_matrix<T>::operator()(int i) const
{
  // add your code here
  if(i<0 || i>=n) throw out_of_range("Out of range");
  return ptr[i];
}
template <typename T>
T TemplatedMy_matrix<T>::operator()(int i, int j) const
{
  // add your code here
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  {
    if (j < 0 || j >= m) throw out_of_range("Out of range"); 
    {
      return elem(i,j);
    } 
  }
    
}
template <typename T>
T& TemplatedMy_matrix<T>::operator()(int i, int j)
{
  // add your code here
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  {
    if (j < 0 || j >= m) throw out_of_range("Out of range"); 
    {
      return elem(i,j);
    } 
  }
}
template <typename T>
T TemplatedMy_matrix<T>::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  // add your code here
  return ptr[i][j];
}
template <typename T>
T& TemplatedMy_matrix<T>::elem(int i, int j)
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  // add your code here
  return ptr[i][j];
}
template <typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat)
{
  // add your code here
  
  for(int i = 0; i< mat.number_of_rows(); i++)
  {
    for(int k = 0; k< mat.number_of_columns(); k++)
    {
      out<<mat.elem(i,k)<<"\t";
    }
    out<<"\n";
  }
  return out;
}
template <typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat)
{
  // add your code here
  int rows;
  int cols;
  in>>rows;
  in>>cols;
  TemplatedMy_matrix<T> mat1(rows,cols);
  mat = mat1;
  for(int i = 0; i< mat.number_of_rows(); i++)
  {
    for(int k = 0; k<mat.number_of_columns(); k++)
    {
      in>>mat.elem(i,k);
      if(!in)
      {
      throw invalid_input();
      }
    }
  }
  return in;
}
template <typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
  // add your code here
  if(mat1.number_of_rows() == mat2.number_of_rows())
  {
    if(mat1.number_of_columns() == mat2.number_of_columns())
    {
      TemplatedMy_matrix<T> add(mat1.number_of_rows(), mat1.number_of_columns());
      for(int c = 0; c< add.number_of_rows(); c++)
      {
        for(int d = 0; d< add.number_of_columns(); d++)
        {
          add.elem(c,d) = 0;
        }
      }
      for (int i=0; i<add.number_of_rows(); i++)
        {
          for (int j=0; j<add.number_of_columns(); j++)
            {
              add.elem(i,j)= mat1.elem(i,j) + mat2.elem(i,j);
          }
        }
        return add;
    }
    else
    {
      throw incompatible_matrices();
    }
  }
  else
  {
    throw incompatible_matrices();
  }
}
template <typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2){
  // add your code here
  if(mat1.number_of_rows() == mat2.number_of_columns())
  {
    TemplatedMy_matrix<T> mult(mat1.number_of_rows(), mat2.number_of_columns());
    for(int c = 0; c< mult.number_of_rows(); c++)
    {
      for(int d = 0; d< mult.number_of_columns(); d++)
      {
        mult.elem(c,d) = 0;
      }
    }
    for(int i = 0; i< mat1.number_of_rows(); i++)
    {
      for(int a = 0; a< mat2.number_of_columns(); a++)
      {
        for(int b = 0; b < mat1.number_of_columns(); b++)
        {
          mult.elem(i,a) += (mat1.elem(i,b) * mat2.elem(b,a));
        }
      }
    }
    return mult;
  }
  else
  {
    throw incompatible_matrices();
  }
}

