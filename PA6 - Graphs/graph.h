#include <iostream>
using namespace std;

class Graph
{
private:
	int numVertex;
	bool **matrix;
public:
	Graph(int num);//constructor
	~Graph();//destructor
	Graph(const Graph& old);//copy constructor
	Graph& operator=(const Graph& old);//copy assignment operator
	ostream& printGraph(ostream& out);//print as adjacency list
	void addEdge(int start, int end);
	void deleteEdge(int start, int end);
	bool isEdge(int start, int end);
	void clear();
	int get_numVertex() const {return numVertex;}
	bool* operator()(int start) const;
	bool& operator()(int start, int end); // overloaded to access (i,j) element
  	bool operator()(int start, int end) const; // overloaded to access (i,j) element
  	bool elem(int start, int end) const; // overloaded to access (i,j) element
  	bool& elem(int start, int end);
  	bool oneStroke();
  	void DFS(int v, vector<bool> visited);
  	bool isConnected();
  	ostream& PrintPath(ostream& out);



};
istream& operator>>(istream& in, Graph& g);
ostream& operator<<(ostream& out, Graph& g);
