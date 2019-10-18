/* 
 *  main function
 */

#include "BTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

BTree read_file(string file_name)
{
  BTree tree;
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
  ifstream inData;
  inData.open(file_name);
  while(inData.good())
  {
  	inData>>tree;
  }  
  inData.close();
  return tree;
}


int main()
{
  /*
    write main function
  */
	// BTree tree;
	// for(int i = 0; i< 15; ++i)
	// {
	// 	cout<<"Value being inserted into tree: "<<tree.insert(rand()%40);
	// 	cout<<endl;
	// }
	// cout<<"Printing Tree: "<<endl<<tree<<endl;
	// cout<<"Printing tree in order: ";
	// tree.inorder(cout, tree.get_root());
	// cout<<endl;
	// cout<<"Updating search cost"<<endl;
	// tree.update_search_cost();
	// cout<<"Printing Tree after updating search cost: "<<endl<<tree<<endl;
	// cout<<"Printing tree in order: ";
	// tree.inorder(cout, tree.get_root());

	for(int i = 1; i<= 12; i++)
	{
		string f;
		string c = to_string(i);
		f= c+"p";
		BTree tree = read_file(f);
		if(i<5)
		{
			cout<<"Printing Tree "<<f<<" : "<<endl<<tree<<endl;
			cout<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(cout, tree.get_root());
			cout<<endl;
			cout<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;
		}
		else
		{
			string out = f+"_out.txt";
			ofstream Out(out);
			Out<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(Out, tree.get_root());
			Out<<endl;
			Out<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;

		}
	}
	for(int k = 1; k<= 12; k++)
	{
		
		string f;
		string c = to_string(k);
		f= c+"r";
		BTree tree = read_file(f);
		if(k<5)
		{
			cout<<"Printing Tree "<<f<<" : "<<endl<<tree<<endl;
			cout<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(cout, tree.get_root());
			cout<<endl;
			cout<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;
		}
		else
		{
			string out = f+"_out.txt";
			ofstream Out(out);
			Out<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(Out, tree.get_root());
			Out<<endl;
			Out<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;

		}
		
	}
	for(int j = 1; j<= 12; j++)
	{
		string f;
		string c = to_string(j);
		f= c+"l";
		BTree tree = read_file(f);
		
		if(j<5)
		{
			cout<<"Printing Tree "<<f<<" : "<<endl<<tree<<endl;
			cout<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(cout, tree.get_root());
			cout<<endl;
			cout<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;
		}
		else
		{
			string out = f+"_out.txt";
			ofstream Out(out);
			Out<<"Printing tree "<<f <<" in order: "<<endl;
			tree.inorder(Out, tree.get_root());
			Out<<endl;
			Out<<"Average search cost of tree: "<<tree.total_search_cost()/tree.get_size()<<endl;

		}
	}


}

