#include <iostream>
#include "SkipList.h"
#include <fstream>
#include <string>
using namespace std;

SkipList read_file(string file_name)
{
  SkipList list;
  /*
    open the file and use the input operator (operator>>)
    to construct a new list
  */
  ifstream inData;
  inData.open(file_name);
  while(inData.good())
  {
  	inData>>list;
  }  
  inData.close();
  return list;
}

int main()
{
	for(int i = 1; i< 13; i++)
	{
		string f;
		string c = to_string(i);
		f= c+"p";
		SkipList list;
		list = read_file(f);
		cout<<"Printing list "<<f<<" : "<<endl<<list<<endl;
		cout<<endl;
	}
	for(int k = 1; k< 13; k++)
	{
		
		string f;
		string c = to_string(k);
		f= c+"r";
		SkipList list;
		list = read_file(f);
		cout<<"Printing list "<<f<<" : "<<endl<<list<<endl;
		cout<<endl;
		
	}
	for(int j = 1; j< 13; j++)
	{
		string f;
		string c = to_string(j);
		f= c+"l";
		SkipList list;
		list = read_file(f);
		cout<<"Printing list "<<f<<" : "<<endl<<list<<endl;
		cout<<endl;
	}
	// SkipList list;
	// list = read_file("input.txt");
	// cout<<"Printing List: "<<endl<<list<<endl;
	
	


	return 0;
}

