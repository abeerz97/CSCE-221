#include "MinQueue.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
  cout << "Create a new queue" << endl;
  MinQueue<string> q;
  cout << "list: " << q.getQueue() << endl << endl;

  cout<<"Add to Queue"<<endl;
  q.enqueue("Abeer");
  q.enqueue("Sam");
  q.enqueue("Tom");
  q.enqueue("Kobe");
  q.enqueue("Eden");
  q.enqueue("Kante");
  q.enqueue("Russell");
  q.enqueue("Giannis");
  q.enqueue("Nadal");
  q.enqueue("Lewandowski");
  cout << "list: " << q.getQueue() << endl << endl;
  cout<<"Min: "<<q.min()<<endl;
  cout<<"First in Queue: "<<q.first()<<endl;
  cout<<"Last in Queue: "<<q.last()<<endl;

  cout<<"Removed from Queue: "<<endl;
  for(int i = 0; i<=(q.size()/2); ++i)
  {
    cout<<q.dequeue()<<' ';
  }
  cout<<endl;
  cout << "list: " << q.getQueue() << endl << endl;
  cout<<"Min: "<<q.min()<<endl;
  cout<<"First in Queue: "<<q.first()<<endl;
  cout<<"Last in Queue: "<<q.last()<<endl;
  
  return 0;
}
