#include "list.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Need an empty list
List::List():first{nullptr}{}


//want to remove our objects w/ the destructor.
List::~List(){
  while(!is_empty()) {
    remove(first->value);
  }
}

//move
List::List(List && other):first{nullptr}{}
//copy
List::List(List const& other):first{nullptr}{}  

//Comment: Use nullptr instead of NULL.
bool List::is_empty() const {
  return first == nullptr;
}

void List::insert(int val) {
  int size{0};

  
  //if it is empty insert first
  if (is_empty()) {
    Node* tmp = new Node();
    tmp->value=val;
    first = tmp;
  }
  /*  
  // in the middle
  else  {
    Node* newnode = new Node();
    Node* tmpnode = new Node();
    newnode = first;
    
    while(newnode->next != nullptr) {
      newnode=newnode->next;
      
      if(newnode->value > val) {

	tmpnode=newnode->next;
	newnode=tmpnode;
	break;
      }
    }
    
    //insert at end if we reach nullptr

    if(newnode->next = nullptr){
      tmpnode->next = newnode->next;
      newnode->next = tmpnode;
    }
    tmpnode->next=nullptr;
        delete tmpnode;
  }    
  */

 else {
      Node* newnode = new Node();
      newnode->value=val;
      first->next=newnode;
}
}

void List::print() const
{
  Node * curr{first}; 
  print_helper(curr);

}
//used via the print function
void List::print_helper(Node * curr) const
{
  if(curr != nullptr)
    {
      std::cout << curr -> value << endl;
      print_helper(curr -> next);
    }
}

//Comment: This is ok but it would be more efficient to save an int in
//the class representing the size.
int  List::getSize() const{
  
  int size{0}; 
  Node* tmp = first; 
  while (tmp != nullptr)
    {
      size++;
      tmp = tmp->next;
    }
  return size;
}

int List::indexAt(int index) const {
  Node* tmp = first;
  int currentPos = 0;
  
  while (tmp->next != nullptr){
    if (currentPos == index){

      break;}
    currentPos++;
    tmp=tmp->next;
  }
    
  
  
  return tmp->value;   
}

void List::remove(int val){

  if (first == nullptr){
    return;
  }
    Node* tmp{first};
    Node* nxtnode{tmp->next};
    
  if (first->value == val){
    tmp->next=nullptr;
  delete tmp;
  first=nxtnode;
  return;
  }

  while(true){    
    if (nxtnode->value == val){
      tmp->next = nxtnode->next;
      nxtnode->next=nullptr;
      delete nxtnode;
      break;
    }     
    if(tmp->next->next == nullptr){
      delete tmp->next->next;
      tmp->next=nullptr;
      break;
    }
    if(nxtnode==nullptr){
      break;
    }
    nxtnode = nxtnode->next;
    tmp = tmp->next;
  }
}

List & List::operator = (List const& other){

  
  Node **p = &first;

  for (Node *tmp = other.first; tmp; tmp = tmp->next)
    {
      Node* t = new Node;
      t->value = tmp->value;
      t->next = NULL;

      *p = t;
      p = &(t->next);

     
    }
  return * this;
}
//&& Is needed to for the move constructor which
//allows us to move non-
List & List::operator = (List && other){

  if (&other != this)
    {
        List L2(other);
	Node * tmp = other.first;
        std::swap(L2.first, other.first);
    }
    return *this;

}


