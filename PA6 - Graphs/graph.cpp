#include <iostream>
#include "graph.h"
#include <vector>
#include <stack>

Graph::Graph(int num)
{
	numVertex = num;
	matrix = new bool*[numVertex+1];
	for(int a = 0; a <= numVertex; a++)
	{
		matrix[a] = new bool[numVertex+1];
		for(int b = 0; b<=numVertex; b++)
		{
			matrix[a][b]= false;
		}
	}
}

Graph::~Graph()
{
	clear();
}

void Graph::clear()
{
	for(int i = 0; i<= numVertex; i++)
	{
		delete [] matrix[i];
	}
	delete [] matrix;
}

Graph& Graph::operator=(const Graph& old)
{
	clear();
	this->numVertex = old.numVertex;
	matrix = new bool*[numVertex+1];
	for(int a = 0; a<= numVertex; a++)
	{
		matrix[a] = new bool[numVertex+1];

    	for (int b = 0; b <= numVertex; b++)
      	{
        	elem(a,b)= old.elem(a,b);
   		}
    }
    return *this;
}

Graph::Graph(const Graph& old)
{
	this->numVertex = old.numVertex;
	matrix = new bool*[numVertex+1];
	for(int a = 0; a<= numVertex; a++)
	{
		matrix[a] = new bool[numVertex+1];
		for(int b = 0; b <= numVertex; b++)
		{
			elem(a,b) = old.elem(a,b);
		}
	}	
}

void Graph::addEdge(int start, int end)
{
	matrix[start][end] = true;
    matrix[end][start] = true;
}
void Graph::deleteEdge(int start, int end)
{
	matrix[start][end] = false;
    matrix[end][start] = false;
}
bool Graph::isEdge(int start, int end)
{
	return matrix[start][end];
}

ostream& Graph::printGraph(ostream& out)
{
	for(int i = 1; i<=numVertex; i++)
	{
		out<<i;
		for(int k = 1; k<=numVertex; k++)
		{
			if(isEdge(i,k))
			{
				out<<" -> "<<k;
			}
		}
		out<<endl;
	}
	return out;
}

bool* Graph::operator()(int start) const
{
  
	if(start<0 || start>numVertex) throw out_of_range("Out of range");
	return matrix[start];
}
bool Graph::operator()(int start, int end) const
{
  
	if (start < 0 || start > numVertex) throw out_of_range("Out of range");
	{
		if (end < 0 || end > numVertex) throw out_of_range("Out of range"); 
		{
			return elem(start,end);
		}	
	}
}

bool& Graph::operator()(int start, int end)
{
  
	if (start < 0 || start > numVertex) throw out_of_range("Out of range");
	{
		if (end < 0 || end > numVertex) throw out_of_range("Out of range"); 
		{
			return elem(start,end);
		}	
	}
}

bool Graph::elem(int start, int end) const
{
  if (start < 0 || start > numVertex) throw out_of_range("Out of range");
  if (end < 0 || end > numVertex) throw out_of_range("Out of range");
  return matrix[start][end];
}

bool& Graph::elem(int start, int end)
{
  if (start < 0 || start > numVertex) cout<<"Out of range"<<endl;
  if (end < 0 || end > numVertex) cout<<"Out of range"<<endl;
  return matrix[start][end];
}


istream& operator>>(istream& in, Graph& g)
{
	int numV;
	int numE;
	in>>numV;
	in>>numE;
	Graph g1(numV);
	g = g1;
	for(int i = 0; i< numE; i++)
	{
		int start;
		int end;
		in>>start;
		in>>end;
		g.addEdge(start, end);
	}
	return in;
}
ostream& operator<<(ostream& out, Graph& g)
{
	g.printGraph(out);
	return out;
}

bool Graph::isConnected()
{
	vector<bool> visited(numVertex+1);
	for(int i = 0; i<=numVertex; i++)
	{
		visited.at(i) = false;
	}
	int k;
	for(k = 1; k<=numVertex; k++)
	{
		int count = 0;
		for(int j = 1; j<=numVertex; j++)
		{
			if(isEdge(k,j))
			{
				count++;
			}
		}
		if(count!=0)
		{
			break;
		}
	}
	if(k == numVertex)
	{
		return true;
	}
	DFS(k,visited);
	for(int a = 1; a<=numVertex; a++)
	{
		int c = 0;
		for(int b=1; b<=numVertex; b++)
		{
			if(isEdge(a,b))
			{
				c++;
			}
		}
		if((visited.at(a)=false) && (c>0))
		{
			return false;
		}
	}
	return true;

}
bool Graph::oneStroke()
{
	if(isConnected() == false)
	{
		return false;
	}
	int odd = 0;
	for(int a = 1; a<=numVertex; a++)
	{
		int c = 0;
		for(int b=1; b<=numVertex; b++)
		{
			if(matrix[a][b])
			{
				c++;
			}
		}
		if(c%2 == 1)
		{
			odd++;
		}
	}
	if(odd>2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Graph::DFS(int v, vector<bool> visited)
{
	visited.at(v) = true;
	for(int i = 1; i<=numVertex; i++)
	{
		if(!visited.at(i) && isEdge(v,i))
		{
			DFS(i,visited);
		}
	}
}
ostream& Graph::PrintPath(ostream& out)
{
	if(!oneStroke())
	{
		return out;
	}
	vector<int>numAdj(numVertex+1);
	vector<bool>oddEdge(numVertex+1);
	int numOdd = 0;
	int startPoint;
	for(int i = 1; i<=numVertex; i++)
	{
		int count = 0;
		for(int k = 1; k<=numVertex; k++)
		{
			if(isEdge(i,k))
			{
				count++;
			}
		}
		numAdj.at(i) = count;
		if(count%2 == 1)
		{
			oddEdge.at(i) = true;
			startPoint = i;
			numOdd++;
		}
		else
		{
			oddEdge.at(i) = false;
			
		}
	}
	if(numOdd == 0)
	{
		startPoint = 1;
	}
	vector<int>path;
	stack<int> s;
	int curr = startPoint;
	while(!(s.empty())|| numAdj.at(curr) > 0)
	{
		if(numAdj.at(curr) == 0)
		{
			path.push_back(curr);
			curr = s.top();
			s.pop();
		}
		else
		{
			for(int a = 1; a<=numVertex; a++)
			{
				if(isEdge(curr,a))
				{
					s.push(curr);
					deleteEdge(curr,a);
					int temp1 = numAdj.at(curr);
					int temp2 = numAdj.at(a);
					numAdj.at(curr) = temp1 -1;
					numAdj.at(a) = temp2 - 1;
					curr = a;
					break;
				}
			}
		}
	}
	for(int l = 0; l<path.size()-1; l++)
	{
		out<<path.at(l)<<"->";
	}
	out<<path.at(path.size()-1);
	out<<endl;
	return out;

}
