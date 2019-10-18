#include "SkipList.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <limits>
#include <time.h>
ostream& operator<<(ostream& out, Node& node)
{
  out << node.value;
  return out;
}
ostream& operator<<(ostream& out, SkipList& slist)
{
	if(slist.get_size() <= 16)
	{
		slist.printList(out);
	}
	else
	{
		out<<"List is too large to print"<<endl;
	}
	return out;
}
istream& operator>>(istream& in, SkipList& slist)
{
	int x;
	in>>x;
	slist.insert(x);
	return in;
	
}
//constructor
SkipList::SkipList()
{
	size = 0;
	for(int i = 0; i< 6; i++)
	{
		Node head(std::numeric_limits<int>::min());
		Node tail(std::numeric_limits<int>::max());
		head.next = &tail;
		tail.prev = &head;
		Heads.push_back(head);
		Tails.push_back(tail);
		Heads.at(i).next = &Tails.at(i);
		Tails.at(i).prev = &Heads.at(i);
	}
	//Linking Heads
	Heads.at(0).up = &Heads.at(1);
	for(int j = 1; j<5; j++)
	{
		Heads.at(j).down = &Heads.at(j-1);
		Heads.at(j).up = &Heads.at(j+1);
	}
	Heads.at(5).down = &Heads.at(4);
	//Linking Tails
	Tails.at(0).up = &Tails.at(1);
	for(int k = 1; k<5; k++)
	{
		Tails.at(k).down = &Tails.at(k-1);
		Tails.at(k).up = &Tails.at(k+1);
	}
	Tails.at(5).down = &Tails.at(4);

	
}
//copy constructor
SkipList::SkipList(SkipList& oldList)
{
	for(int i = 0; i< 6; i++)
	{
		Node head(std::numeric_limits<int>::min());
		Node tail(std::numeric_limits<int>::max());
		head.next = &tail;
		tail.prev = &head;
		Heads.push_back(head);
		Tails.push_back(tail);
		Heads.at(i).next = &Tails.at(i);
		Tails.at(i).prev = &Heads.at(i);
	}
	//Linking Heads
	Heads.at(0).up = &Heads.at(1);
	for(int j = 1; j<5; j++)
	{
		Heads.at(j).down = &Heads.at(j-1);
		Heads.at(j).up = &Heads.at(j+1);
	}
	Heads.at(5).down = &Heads.at(4);
	//Linking Tails
	Tails.at(0).up = &Tails.at(1);
	for(int k = 1; k<5; k++)
	{
		Tails.at(k).down = &Tails.at(k-1);
		Tails.at(k).up = &Tails.at(k+1);
	}
	Tails.at(5).down = &Tails.at(4);
	//copying contents
	if(this != &oldList)
	{
		Node* old = oldList.Heads.at(0).next;
		while(old != &oldList.Tails.at(0))
		{
			insert(old->value, old->level);
			old = old->next;
		}	
	}


}
//destructor
SkipList::~SkipList()
{
	clear();
}
// copy assignment
SkipList& SkipList::operator=(const SkipList& oldList)
{
	clear();
	for(int i = 0; i< 6; i++)
	{
		Node head(std::numeric_limits<int>::min());
		Node tail(std::numeric_limits<int>::max());
		head.next = &tail;
		tail.prev = &head;
		Heads.push_back(head);
		Tails.push_back(tail);
		Heads.at(i).next = &Tails.at(i);
		Tails.at(i).prev = &Heads.at(i);
	}
	//Linking Heads
	Heads.at(0).up = &Heads.at(1);
	for(int j = 1; j<5; j++)
	{
		Heads.at(j).down = &Heads.at(j-1);
		Heads.at(j).up = &Heads.at(j+1);
	}
	Heads.at(5).down = &Heads.at(4);
	//Linking Tails
	Tails.at(0).up = &Tails.at(1);
	for(int k = 1; k<5; k++)
	{
		Tails.at(k).down = &Tails.at(k-1);
		Tails.at(k).up = &Tails.at(k+1);
	}
	Tails.at(5).down = &Tails.at(4);
	//copying content
	if(this != &oldList)
	{
		Node* old = oldList.Heads.at(0).next;
		while(old != &oldList.Tails.at(0))
		{
			insert(old->value, old->level);
			old = old->next;
		}	
	}
	return *this;

}

void SkipList::clear()
{
	
	Node* curr = Heads.at(0).next;
	while(curr != nullptr)
	{
		Node* temp = curr;
		curr = curr->next;
		remove(temp->value);
	}
	Heads.clear();
	Tails.clear();
}
//main insert function
void SkipList::insert(int value)
{
	//determining number of levels to insert value into
	int level = coinToss();
	if(level > 6)
	{
		level = 6;
	}

	//calling helper function
	insert(value, level);
}
//overloaded insert helper function
void SkipList::insert(int value, int level)
{
	int numCmp = 0;
	int index = level-1;
	int l = level;
	vector<Node> input;
	Node* curr = &Heads.at(level-1);
	//inserting elements
	while((curr != nullptr)|| (l!=0))
	{
		if(curr->next->value > value && curr->down != nullptr)
		{
			numCmp++;
			Node* temp = curr->next;
			curr->next = new Node(value);
			curr->next->next = temp;
			curr->next->prev = curr;
			curr->next->level = level;
			curr->next->insertion_cost = numCmp;
			temp->prev = curr->next;
			input.push_back(*curr->next);
			curr = curr->down;
			size++;
			l--;
		}
		else if(curr->next->value > value)
		{
			numCmp++;
			Node* temp = curr->next;
			curr->next = new Node(value);
			curr->next->next = temp;
			curr->next->prev = curr;
			curr->next->level = level;
			curr->next->insertion_cost = numCmp;
			temp->prev = curr->next;
			input.push_back(*curr->next);
			size++;
			l--;
			break;
		}
		else if(curr->next->value == value)
		{
			cout<<"Duplicate Items"<<endl;
			return;
		}
		else
		{	
			curr = curr->next;
			numCmp++;
		}
		
	}
	//Linking inserted elements
	if(index > 1)
	{
		input.at(index).up = &input.at(index-1);
		for(int k  = index-1; k>0; k--)
		{
			input.at(k).up = &input.at(k-1);
			input.at(k).down = &input.at(k+1);
		}
		input.at(0).down = &input.at(1);
	}
	else if(index == 1)
	{
		input.at(0).down = &input.at(1);
		input.at(1).up = &input.at(0);
	}
	else
	{
		input.at(0).up = nullptr;
		input.at(0).down = nullptr;
	}
	
	if(size <= 16)
	{
		cout<<"Inserted: "<<input.at(index)<<", # comparisons: "<<input.at(index).insertion_cost<<endl;
		return;
	}
	else
	{
		cout<<"List too large to print number of comparisons"<<endl;
		return;
	}

}
void SkipList::update_search_cost()
{
	Node* curr = &Heads.at(0);

	while(curr != &Tails.at(0))
	{
		search(curr->value);
		curr = curr->next;
	}
}
int SkipList::avg_insertion_cost()
{
	int cost=0;
	Node* curr = &Heads.at(0);

	while(curr != &Tails.at(0))
	{
		Node* temp;
		temp = search(curr->value);
		cost += temp->insertion_cost;
		curr = curr->next;
	}
	return cost/size;
}
int SkipList::avg_deletion_cost()
{
	int cost=0;
	Node* curr = &Heads.at(0);

	while(curr != &Tails.at(0))
	{
		Node* temp;
		temp = search(curr->value);
		cost += temp->search_cost;
		cost += temp->level;
		curr = curr->next;
	}
	return cost/size;
}


Node* SkipList::search(int value)
{
	int i = 5;
	Node* curr = &Heads.at(i);
	curr = curr->next;
	int num = 0;
	while(i >=0 && curr != nullptr)
	{
		if(curr == &Tails.at(i))
		{
			i--;
			curr = Heads.at(i).next;
		}
		else if(curr->value > value)
		{
			curr = curr->down;
			curr = curr->prev;
			i--;
			num++;
		}
		else if(curr->value < value)
		{
			curr = curr->down;
			curr = curr->next;
			i--;
			num++;
		}
		else if(curr->value == value)
		{
			for(int k = i; k>=0; k--)
			{
				curr = curr->down;
				i--;
			}
			curr->search_cost =num;
			return curr;
		}
		else if(i == 0 && curr->value < value)
		{
			curr = curr->next;
			num++;
			while(curr!= nullptr)
			{
				if(curr->value == value)
				{
					curr->search_cost =num;
					return curr;
				}
				curr = curr->next;
				num++;
			}
		}
		else if(i == 0 && curr->value > value)
		{
			curr = curr->prev;
			num++;
			while(curr!= nullptr)
			{
				if(curr->value == value)
				{
					curr->search_cost =num;
					return curr;
				}
				curr = curr->prev;
				num++;
			}
		}
	}
	
	return nullptr;
}
//delete function
void SkipList::remove(int value)
{
	Node* curr = search(value);
	int cost = curr->search_cost;
	int i = 0;
	while(curr != &Tails.at(i))
	{
		Node* temp = curr;
		curr = curr->up;
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		i++;
		temp = nullptr;
	}
	if(size <= 16)
	{
		cout<<"# comparisons: "<< cost + i <<endl;
	}

}
int SkipList::coinToss()
{
	int num = 1;
	int x = rand()%2;
	while(x == 1)
	{
		x = rand()%2;
		num++;
		
	}
	return num;
}
ostream& SkipList::printList(ostream& out)
{
	for(int c = 0; c < 6 ; c++)
	{
		Node* curr = Heads.at(5-c).next;
		Node* end = &Tails.at(5-c);
		out<< "-Infinity, ";
		while(curr != end)
		{
			
			out<<*curr<<", ";
			curr=curr->next;
			
		}
		out<<"Infinity"<<endl;

	}
	return out;
}
