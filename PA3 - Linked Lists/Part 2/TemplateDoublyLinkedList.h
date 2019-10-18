#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class TemplatedLinkedList; // class declaration

// list node
template <typename T> 
struct DListNode{
  T obj;
  DListNode *prev, *next;
  DListNode(T e = "", DListNode *p = NULL, DListNode *n = NULL)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list
template <typename T> 
class TemplatedLinkedList {
private:
  DListNode<T> header, trailer;
public:
  TemplatedLinkedList() : header(""), trailer("") // constructor
  { header.next = &trailer; trailer.prev = &header; }
  TemplatedLinkedList(const TemplatedLinkedList& dll); // copy constructor
  TemplatedLinkedList(TemplatedLinkedList&& dll); // move constructor
  ~TemplatedLinkedList(); // destructor
  TemplatedLinkedList& operator=(const TemplatedLinkedList& dll); // assignment operator
  TemplatedLinkedList& operator=(TemplatedLinkedList&& dll); // move assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // return if the list is empty
  void clear();
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
  void insertAfter(DListNode<T> &p, T newobj);
  void insertBefore(DListNode<T> &p, T newobj);
  T removeAfter(DListNode<T> &p);
  T removeBefore(DListNode<T> &p);
};

// output operator
template <typename T>
ostream& operator<<(ostream& out, const TemplatedLinkedList<T>& dll);
// return the list length
template <typename T>
int TemplatedLinkedListLength(TemplatedLinkedList<T>& dll);

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
template <typename T>
TemplatedLinkedList<T>::TemplatedLinkedList(const TemplatedLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  /* Complete this function */

  header = dll.header;
  trailer = dll.trailer;
  DListNode<T> *old = dll.header.next;
  if(old != nullptr)
  {
    header.next = new DListNode<T>(old->obj, &header, old->next);
    DListNode<T> *curr = header.next;
    old = old->next;
    while(old != dll.trailer.prev)
    {
      curr->next = new DListNode<T>(old->obj, old->prev, old->next);
      curr = curr->next;
      old = old->next;
    }
    curr->next = new DListNode<T>(old->obj, old->prev, &trailer);
  }

}
///move constructor
template <typename T>
TemplatedLinkedList<T>::TemplatedLinkedList(TemplatedLinkedList<T>&& dll)
{
   // Complete this function 
  header.next = &trailer;
  trailer.prev = &header;
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;
  delete dll.header.next;
  delete dll.trailer.prev;
}

// assignment operator
template <typename T>
TemplatedLinkedList<T>& TemplatedLinkedList<T>::operator=(const TemplatedLinkedList<T>& dll)
{
  header.next = &trailer;
  trailer.prev = &header;
  if(this != &dll)
  {
    header = dll.header;
    trailer = dll.trailer;
    DListNode<T> *old = dll.header.next;
    if(old != nullptr)
    {
      header.next = new DListNode<T>(old->obj, &header, nullptr);;
      DListNode<T> *curr = header.next;
      old = old->next;
      while(old != trailer.prev)
      {
        curr->next = new DListNode<T>(old->obj, curr, old->next);
        curr = curr->next;
        old = old->next;
      }
      curr->next = new DListNode<T>(old->obj, old->prev, &trailer);
    }
  }
  return *this;
  /* Complete this function */
}
//move assignment operator
template <typename T>
TemplatedLinkedList<T>& TemplatedLinkedList<T>::operator=(TemplatedLinkedList<T>&& dll)
{
  header.next = &trailer;
  trailer.prev = &header;
  if(this != &dll)
  {
    clear();
    header.next = dll.header.next;
    trailer.prev = dll.trailer.prev;
    delete dll.header.next;
    delete dll.trailer.prev;

  }
  return *this;
}

// insert the new object as the first one
template <typename T>
void TemplatedLinkedList<T>::insertFirst(T newobj)
{ 
    /* Complete this function */
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert the new object as the last one
template <typename T>
void TemplatedLinkedList<T>::insertLast(T newobj)
{
    /* Complete this function */
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object from the list
template <typename T>
T TemplatedLinkedList<T>::removeFirst()
{ 
  
  if (isEmpty())
  {
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  }
  DListNode<T> *curr = header.next;
  curr->next->prev = &header;
  header.next = curr->next;
  T elem = curr->obj;
  delete curr;
  return elem;
}

// remove the last object from the list
template <typename T> 
T TemplatedLinkedList<T>::removeLast()
{
    /* Complete this function */
  if (isEmpty())
  {
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  }
  DListNode<T> *curr = trailer.prev;
  curr->prev->next = &trailer;
  trailer.prev = curr->prev;
  T obj = curr->obj;
  delete curr;
  return obj;
}

// destructor
template <typename T>
TemplatedLinkedList<T>::~TemplatedLinkedList()
{
    /* Complete this function */
   DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) 
  {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
template <typename T>
void TemplatedLinkedList<T>::clear()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) 
  {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;

}

// return the first object
template <typename T>
T TemplatedLinkedList<T>::first() const
{ 
    /* Complete this function */
  if (isEmpty())
  {
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  }
  return header.next->obj;
  
}

// return the last object
template <typename T>
T TemplatedLinkedList<T>::last() const
{
    /* Complete this function */
  if(isEmpty())
  {
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  }
  return trailer.prev->obj;
}

// insert the new object after the node p
template <typename T>
void TemplatedLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
    /* Complete this function */
  DListNode<T> *curr = getFirst();
  DListNode<T> *temp = nullptr;
  while(curr !=getAfterLast())
  {
    temp = curr->next;
    if(curr->obj == p.obj)
    {
      curr->next = new DListNode<T>(newobj, curr, temp);
      return;
    }
    curr = curr->next;
  }

}

// insert the new object before the node p
template <typename T>
void TemplatedLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
    /* Complete this function */
  DListNode<T> *curr = getFirst();
  DListNode<T> *temp = nullptr;
  while(curr !=getAfterLast())
  {
    temp = curr->prev;
    if(curr->obj == p.obj)
    {
      curr->prev = new DListNode<T>(newobj, temp, curr);
      temp->next = curr->prev;
      return;
    }
    curr = curr->next;
  }
}

// remove the node after the node p
template <typename T>
T TemplatedLinkedList<T>::removeAfter(DListNode<T> &p)
{
  /* Complete this function */
  DListNode<T> *curr = getFirst();
  DListNode<T> *temp = nullptr;
  while(curr !=getAfterLast())
  {
    temp = curr->next;
    if(curr->obj == p.obj)
    {
      curr->next= temp->next;
      temp->next->prev = curr;
      T elem = temp->obj;
      delete temp;
      return elem;
    }
    curr = curr->next;
  }
  return 0;
}

// remove the node before the node p
template <typename T>
T TemplatedLinkedList<T>::removeBefore(DListNode<T> &p)
{
  /* Complete this function */
  DListNode<T> *curr = getFirst();
  DListNode<T> *temp = nullptr;
  while(curr !=getAfterLast())
  {
    temp = curr->prev;
    if(curr->obj == p.obj)
    {
      curr->prev= temp->prev;
      temp->prev->next = curr;
      T elem = temp->obj;
      delete temp;
      return elem;
    }
    curr = curr->next;
  }
  return 0;
}

// return the list length
template <typename T>
int TemplatedLinkedListLength(TemplatedLinkedList<T>& dll)
{
    /* Complete this function */
  DListNode<T> *curr = dll.getFirst();
  int count = 0;
  while(curr != dll.getAfterLast())
  {
    count++;
    curr = curr->next;
  }
  return count;

}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const TemplatedLinkedList<T>& dll)
{
  
  /* Complete this function */
  DListNode<T> *curr = dll.getFirst();
  while(curr !=dll.getAfterLast())
  {
    out<<curr->obj<<' ';
    curr = curr->next;
  }
  out<<endl;
  
  return out;
}
