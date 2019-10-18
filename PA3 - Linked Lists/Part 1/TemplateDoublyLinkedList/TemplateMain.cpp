#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  TemplatedLinkedList<string> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  TemplatedLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  TemplatedLinkedList<string> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insertAfter, insertBefore
  // add tests for removeAfter, removeBefore
  // add tests for TemplatedLinkedListLength
  DListNode<string> p("20", nullptr, nullptr);
  //Insert After
  cout<<"List 2, Insert 19 after 20: "<<endl;
  dll2.insertAfter(p, "19");
  cout<<dll2<<endl;
  cout<<"List 3, Insert 19 before 20: "<<endl;
  dll3.insertBefore(p, "19");
  cout<<dll3<<endl;
  cout<<"List 2 Length: ";
  cout<< TemplatedLinkedListLength(dll2)<<endl;
  cout<<"List 3 Length: ";
  cout<< TemplatedLinkedListLength(dll3)<<endl;
  cout<<endl;
  // // add tests for removeAfter, removeBefore
  cout<<"List 2, Remove 19 after 20: "<<endl;
  dll2.removeAfter(p);
  cout<<dll2<<endl;
  cout<<"List3, Remove 19 before 20: "<<endl;
  dll3.removeBefore(p);
  cout<<dll3<<endl;
  cout<<"List 2 Length: ";
  cout<< TemplatedLinkedListLength(dll2)<<endl;
  cout<<"List 3 Length: ";
  cout<< TemplatedLinkedListLength(dll3)<<endl;
  cout<<endl;
  // // add tests for TemplatedLinkedListLength
  //Check Length
  cout<<"Delete Lists 2 and 3"<<endl;
  dll2.clear();
  dll3.clear();
  cout<<"List 2 Length: ";
  cout<< TemplatedLinkedListLength(dll2)<<endl;
  cout<<"List 3 Length: ";
  cout<< TemplatedLinkedListLength(dll3)<<endl;
  cout<<endl;
  return 0;
}
