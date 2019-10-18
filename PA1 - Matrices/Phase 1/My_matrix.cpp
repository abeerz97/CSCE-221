/* 
Implementation of the clas My_matrix
*/

#include "My_matrix.h"
#include <stdexcept>
#include <iostream>

My_matrix::My_matrix()
{
  // add your code here
	n = 0;
	m = 0;
	ptr = nullptr;

}

// void My_matrix::allocate_memory()
// {
//   // add your code here
// }

My_matrix::My_matrix(int n1, int m1)
{
  // add your code here
	n = n1;
	m = m1;
	ptr = new int*[n];
	for(int a = 0; a < n; a++)
	{
		ptr[a] = new int[m];
	}
}

My_matrix::My_matrix(const My_matrix& mat)
{
  // add your code here
	this->n = mat.number_of_rows();
	this->m = mat.number_of_columns();
	ptr = new int*[n];
	for(int j = 0; j< n; j++)
	{
		ptr[j] = new int[m];
	}

	for(int i = 0; i < n; i++)
	{
		for(int b = 0; b < m; b++)
		{
			elem(i,b) = mat.elem(i,b);
		}
	}

}

// // // move constructor (optional)
// My_matrix::My_matrix(My_matrix&& mat)
// {
//   // add your code here
// }

My_matrix::~My_matrix()
{
  // add your code here
	clear();
	
}
void My_matrix::clear()
{
	for(int i = 0; i< n; i++)
	{
		delete [] ptr[i];
	}
	delete [] ptr;
}

My_matrix& My_matrix::operator=(const My_matrix& mat)
{
  // add your code here
	this->n = mat.number_of_rows();
	this->m = mat.number_of_columns();
	this->ptr = new int*[n];
	for(int j = 0; j< n; j++)
	{
		ptr[j] = new int[m];
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
// My_matrix& My_matrix::operator=(My_matrix&& mat)
// {
//   // add your code here
// }

int My_matrix::number_of_rows() const
{
  // add your code here
	return n;
}

int My_matrix::number_of_columns() const
{
  // add your code here
	return m;
}

int* My_matrix::operator()(int i) const
{
  // add your code here
	if(i<0 || i>=n) throw out_of_range("Out of range");
	return ptr[i];
}
int My_matrix::operator()(int i, int j) const
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

int& My_matrix::operator()(int i, int j)
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

int My_matrix::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  // add your code here
  return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  // add your code here
  return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat)
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

istream& operator>>(istream& in, My_matrix& mat)
{
  // add your code here
	int rows;
	int cols;
	in>>rows;
	in>>cols;
	My_matrix mat1(rows,cols);
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

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
  // add your code here
	if(mat1.number_of_rows() == mat2.number_of_rows())
	{
		if(mat1.number_of_columns() == mat2.number_of_columns())
		{
			My_matrix add(mat1.number_of_rows(), mat1.number_of_columns());
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

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2){
  // add your code here
	if(mat1.number_of_rows() == mat2.number_of_columns())
	{
		My_matrix mult(mat1.number_of_rows(), mat2.number_of_columns());
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
