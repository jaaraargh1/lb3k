//TODO: Complementary work needed, you do not need both pragma once
//and header guards. Keep one of them. - fixed

//TODO: Complementary work needed. Your program has some memory leaks,
//probably because you do not free all of the memory that you use. Use
//valgrind (available on the school system and can be installed in
//your own system) by typing: valgrind ./a.out in the terminal. It
//tells you if you have any memory leaks.

//TODO: Complementary work needed. Any helper functions should be
//private so that they cannot be accessed from outside the class. - fixed

//TODO: Functions that should not change the class should be declared
//as const. (Hint: getsize). - fixed

//TODO: You have warnings from the compilation that indicate that you
//have missed something. Your implementation for the copy and move
//construction is not completed (they only initialize the list to an
//empty list).

#ifndef list_h
#define list_h
#include <string>
#include <iostream>

class List
{
struct Node;

  
public:
List();
~List();
List(List && other); // move constructor -- List l{}
List & operator = (List && other);

List(List const& other); // Copy constructor -- List l{l2};
List & operator = (List const& other);
  
bool is_empty() const;
void insert(int value);
void print() const;
int  getSize() const;  
int indexAt(int index) const;
void remove(int index);
  
private:
void print_helper(Node * curr) const;
  
struct Node
{
  int value{};
  Node * next{};
   
};
Node * first{nullptr};
};

/*





/*
void List::print() const
{
Node * curr{first};



while(curr != nullptr)
{
std::cout << curr -> value;
curr = curr -> next;
}
}
*/



#endif
