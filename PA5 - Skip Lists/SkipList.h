#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int value;
	int search_cost;
	int level;
	int insertion_cost;
	Node* prev;
	Node* next;
	Node* up;
	Node* down;
	Node(int e=0, Node *p = nullptr, Node *n = nullptr, Node* u = nullptr, Node* d = nullptr, int l = 0)
	: value(e), prev(p), next(n), up(u), down(d), search_cost(0), level(l), insertion_cost(0) {}
};

class SkipList
{
private:
	int size;
	vector<Node> Heads;
	vector<Node> Tails;

public:
	SkipList();
	SkipList(SkipList& old);
	~SkipList();
	SkipList& operator=(const SkipList& old);
	void clear();
	int get_size() const {return size;}
	void insert(int value);
	void insert(int value, int level);
	Node* search(int value);
	void remove(int value);
	ostream& printList(ostream& out);
	int avg_insertion_cost();
	int avg_deletion_cost();
	int coinToss();
	void update_search_cost();
	int get_insertion_cost(Node* node) const {return node->insertion_cost;}
	int get_search_cost(Node* node) const {return node->search_cost;}
	
};
ostream& operator<<(ostream& out, Node& node);
ostream& operator<<(ostream& out, SkipList& slist);
istream& operator>>(istream& in, SkipList& slist);


#endif