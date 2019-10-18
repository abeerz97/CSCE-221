#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "TemplateDoublyLinkedList.h"
using namespace std;

template <typename T> 
class MinQueue{
private:
	TemplatedLinkedList<T> dll;
	int capacity;
public:
	MinQueue(): dll(){capacity = 0;}//constructor
  	~MinQueue(){dll.~TemplatedLinkedList<T>();} // destructor
	void enqueue(T x);
	TemplatedLinkedList<T>& getQueue(){return dll;}
	T dequeue();
	int size();
	T first() const;
	T last() const;
	bool isEmpty() const {return dll.isEmpty();}
	T min();
};

struct EmptyQueueException : std::range_error {
  explicit EmptyQueueException(char const* msg=NULL): range_error(msg) {}
};

template <typename T> 
T MinQueue<T>::first() const
{
	if(dll.isEmpty())
	{
		throw EmptyQueueException("Access to an empty queue");
	}
	return dll.first();
}

template <typename T> 
T MinQueue<T>::last() const
{
	if(dll.isEmpty())
	{
		throw EmptyQueueException("Access to an empty queue");
	}
	return dll.last();
}

template <typename T> 
T MinQueue<T>::dequeue()
{
	if(dll.isEmpty())
	{
		throw EmptyQueueException("Access to an empty queue");
	}
	capacity--;
	return dll.removeFirst();
}

template <typename T> 
void MinQueue<T>::enqueue(T x)
{
	dll.insertLast(x);
	capacity++;
}

template <typename T> 
T MinQueue<T>::min()
{
	DListNode<T> *curr = dll.getFirst();
	T m = curr->obj;
	while(curr != dll.getAfterLast())
	{
		if(curr->obj < m)
		{
			m = curr->obj;
		}
		curr = curr->next;
	}
	return m;
}
template <typename T> 
int MinQueue<T>::size()
{
	return capacity;
}

