/*
 * Binary Tree - source file (functions implementation)
 */

#include "BTree.h"
#include <iostream>
#include <vector>
#include <math.h>

ostream& operator<<(ostream& out, BTree& tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream& operator<<(ostream& out, Node& node)
{
  out << node.value
      << "["
      << node.search_cost
      << "]";
  return out;
}

istream& operator>>(istream& in, BTree& tree)
{
  /*
    take input from the in stream, and build your tree

    input will look like
    4 
    2 
    6 
    1 
    3 
    5 
    7
  */

	int n;
	in>>n;//input value into int n
	tree.insert(n);	//insert int n into BST
  return in;//return input operator
}

BTree::BTree(const BTree& other)
{
  /*
    complete this copy constructor
    make sure when copying nodes to copy
    - value
    - left and right children
  */
	Node* curr = other.root;
	if( curr == nullptr)
	{
    this->root = nullptr;//no need to copy from an empty tree
	}
  else
  {
    copy(this->root, curr);//copying contents
    int s = other.size;//copying size
    size = s;
  }
}
BTree::~BTree()
{
	clear(root);
}
BTree::BTree(BTree&& other)
{
  /*
    complete this move constructor
  */
	this->root = other.root;//give new tree the pointer to the root of the old tree
	delete other.root;//delete the pointer from the old tree
}

BTree& BTree::operator=(const BTree& other)
{
  if (this != &other) 
  {
    /*
      complete this assignment operator
      make sure when copying nodes to copy
      - value
      - left and right children
    */
    Node* curr = other.root;
    if(curr == nullptr)
	  {
      root = nullptr;
	  }
    else
    {
      copy(this->root, curr);//call copy function
      this->size = other.size;//copy size of tree
    }
  }
  return *this;
}

BTree& BTree::operator=(BTree&& other)
{
  if (this != &other) 
  {
    
   	this->root = other.root;//give new tree the pointer to the root
   	delete other.root;//delete pointer to root in original tree
  }
  return *this;
}
void BTree::copy(Node* n, Node* old)
{
	if(old == nullptr)
    {
      n = nullptr;//don't copy
    }
    else
    {
      n = new Node();
      n->value = old->value;
      n->left = old->left;
      n->right = old->right;
      n->search_cost = old->search_cost;
      copy(n->left, old->left);//copy left subtree
      copy(n->right, old->right);//copy right subtree
    }
    update_search_cost();//update search cost after copy
}
void BTree::clear() 
{
  if(this->root) 
  {
    if(root->left != nullptr) //clear left subtree
    {
      clear(root->left);
    }
    if(root->right != nullptr) //clear right subtree
    {
      clear(root->right);
    }
      delete root;
  }
}
void BTree::clear(Node* node) 
{
    if(node)//if node isnt nullptr
    {
        if(node->left != nullptr) 
		{
        	clear(node->left);//clear left subtree
    	}
        if(node->right != nullptr) 
        {
        	clear(node->right);//clear right subtree
        }
        delete node;
    }
}


int BTree::insert(int obj)
{
  Node* n = get_root();
  n = insert(n, obj, 1);
  return obj;
}
Node* BTree::insert(Node* node, int obj, int compCount)
{
	if(node == nullptr)//empty space for the new node to be inserted into 
	{
    //initialize contents of node
		node = new Node;
		node->value = obj;
		node->left = nullptr;
		node->right = nullptr;
		node->search_cost = compCount;
    if(size == 0)
    {
      root = node;
    }
		size++;
    return node;
	}
	else if(obj < node->value)//branch to the left
	{
    compCount++;
		node->left = insert(node->left, obj, compCount);
	}
	else if(obj > node->value)//branch to the right
	{
    compCount++;
		node->right = insert(node->right, obj, compCount);
	}
	else
	{
		//Duplicate Items
    return node;
	}
	
	return node;
}

Node* BTree::search(Node* node, int obj)
{
  /*
    recursivly search down the tree to find the node that contains obj
    - if you don't find anything return nullptr
  */
	while(node != nullptr)
	{
		if(node->value > obj)
		{
			node = node->left;
		}
		else if(node->value < obj)
		{
			node = node->right;
		}
		else if(node->value == obj)
		{
			return node;
		}
	}
	cout<<"Item not found"<<endl;
	return nullptr;
}

void BTree::update_search_cost()
{
  /*
    do a BFS of your tree and update the search cost of all nodes
  */
  int level = 1;
  Node* curr = root;
  if(curr != nullptr)
  {
    curr->search_cost = level;
  }
  if(curr->left)
  {
    update_search_cost(curr->left, level +1);
  }
  if(curr->right)
  {
    update_search_cost(curr->right, level + 1);
  }
}
void BTree::update_search_cost(Node* curr, int level)
{
  /*
    do a BFS of your tree and update the search cost of all nodes
  */
	if(curr!= nullptr)
	{
		curr->search_cost = level;
	}
	if(curr->left != nullptr)
	{
		update_search_cost(curr->left, level + 1);
	}
	if(curr->right != nullptr)
	{
		update_search_cost(curr->right, level + 1);
	}
	return;
}
int BTree::height()  
{  
  Node* node = this->root;
  if (node == nullptr) 
  { 
    return 0; 
  } 
  else
  {  
    int lheight = height(node->left);  
    int rheight = height(node->right);  
    if (lheight > rheight)
    {
      return(lheight + 1);  
    }  
    else 
    {
    	return(rheight + 1);  
    }
  }  
}
int BTree::height(Node* node)  
{  
  if (node == NULL) 
  { 
    return 0; 
  } 
  else
  {  
    int lheight = height(node->left);  
    int rheight = height(node->right);  
    if (lheight > rheight)
    {
      return(lheight + 1);  
    }  
    else 
    {
      return(rheight + 1);  
    }
  }  
}  

void BTree::inorder(ostream& out, Node* root)
{
  /*
    print your nodes in infix order

    if our tree looks like 

    4
    2 6
    1 3 5 7

    we should get

    1 2 3 4 5 6 7 
  */
  if(root->left != nullptr)
  {
    inorder(out,root->left);
  }
  out<<*root<<' ';
  if(root->right != nullptr)
  {
    inorder(out, root->right);
  }
	
}

void BTree::print_level_by_level(ostream& out)
{
  /*
    print the tree using a BFS 

    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */
  if (root == NULL) return; 
  
  // Create an empty queue for 
  // level order tarversal 
  vector<Node*> v; 
    
  // to store front element of  
  // queue. 
  Node *curr; 
  int levelCounter = 0;
  int currLevel = 1;

  // Enqueue Root and NULL node. 
  v.push_back(root); 
  v.push_back(nullptr); 

  while (v.size() > 1 && (currLevel < 5)) 
  { 
      curr = v.front(); 
      v.erase(v.begin()); 
        
      // condition to check  
      // occurrence of next  
      // level. 
      if (curr == nullptr) 
      { 
        if(levelCounter < pow(2, currLevel -1))
        {
          levelCounter++;
          out<<"X"<<" ";

        }
        else
        {
          v.push_back(nullptr); 
          out << "\n";
          currLevel++; 
          levelCounter = 0;
        }
      }
      else 
      { 
        // pushing left child of current node. 
        if(curr->left) 
        {
          v.push_back(curr->left); 
        } 
        else
        {
          v.push_back(nullptr);
        }   
        // pushing rigth child of current node. 
        if(curr->right)
        {
          v.push_back(curr->right); 
        } 
        else
        {
          v.push_back(nullptr);
        }
        out << *curr << " ";
        levelCounter++;
      } 
  } 
} 
int BTree::total_search_cost()
{
  int cost = 1;
  Node* curr = root;
  if(curr == nullptr)
  {
    return cost;
  } 
  if(curr->left)
  {
    cost = curr->left->search_cost + total_search_cost(curr->left, cost);
  }
  if(curr->right)
  {
    cost = curr->right->search_cost + total_search_cost(curr->right, cost);
  }
  return cost;
}
int BTree::total_search_cost(Node* curr, int cost)
{
  if(curr == nullptr)
  {
    return cost;
  } 
  if(curr->left)
  {
    cost = curr->left->search_cost + total_search_cost(curr->left, cost);
  }
  if(curr->right)
  {
    cost = curr->right->search_cost + total_search_cost(curr->right, cost);
  }
  return cost;
}
