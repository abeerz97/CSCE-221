#include <iostream>
#include <fstream>
#include "graph.h"



int main()
{
	for(int i = 1; i<=10; i++)
	{
		string file;
		string c = to_string(i);
		file = "g" + c + ".txt";
		Graph g(5);
		ifstream inData(file);
		if(!inData.is_open())
		{
			cout<<"Unable to open file"<<endl;
			return 1;
		}  
		else
		{
			if(inData.good())
			{
				inData>>g;
			}
			else
			{
				cout<<"Filestream is not good"<<endl;
				return 1;
			}
		}
		inData.close();
		cout<<"Printing Adjacency List "<<file<<" : "<<endl<<g<<endl;
		cout<<endl;
		cout<<"Can graph be drawn in one stroke: ";
		if(g.oneStroke())
		{
			cout<<"yes"<<endl;
			g.PrintPath(cout);
		}
		else
		{
			cout<<"no"<<endl;
		}
	}
	return 0;
}