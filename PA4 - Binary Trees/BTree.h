/*
 * Binary Tree - header file
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
using namespace std;

struct Node
{
  int value;
  Node* left;
  Node* right;
  int search_cost;

  // constructor
  Node(): value(0), left(nullptr), right(nullptr), search_cost(0){}
  Node(int val)
  : value(val), left(nullptr), right(nullptr), search_cost(0) {}
  // query
  bool is_leaf() { return (left == nullptr && right == nullptr); }
};

class BTree
{
private:
  int size;
  Node* root;

public:
  // constructors
  BTree() : root(nullptr), size(0) {} // default constructor
  BTree(Node* root, int size): root(root), size(size){}
  BTree(const BTree& other); // copy constructor
  BTree(BTree&& other); // move constructor
  ~BTree(); //destructor
  // assignment and move assignment operator
  BTree& operator=(const BTree& other);
  BTree& operator=(BTree&& other);
  void copy(Node* n, Node* old);
  int height(Node* node);
  int height();
  void clear(Node* node); 
  void clear();
  int get_size() { return size; }
  Node* get_root() { return root; }
  // should not be used unless it is really necessary
  void set_root(Node* node) { root = node; }
  Node* insert(Node* node, int obj, int compCount);
  int insert(int obj);
  Node* search(Node* node, int obj);
  void update_search_cost();
  void update_search_cost(Node* curr, int level);
  void inorder(ostream& out, Node* root);
  void print_level_by_level(ostream& out);
  int total_search_cost();
  int total_search_cost(Node* curr, int cost);


};

ostream& operator<<(ostream& out, BTree& tree);
ostream& operator<<(ostream& out, Node& node);

istream& operator>>(istream& in, BTree& tree);

#endif
