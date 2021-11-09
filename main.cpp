#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"
#include <iomanip>
#include <iostream>
#include <string>

//TODO: Complementary work needed. You have to check that the values
//are in the correct places when you test insert and remove. You could
//either change your print so that it returns a string, or you can use
//indexAt to check that the list works as it should.

//TODO: You have to test your copy and move constructors. Make sure
//that you test that it is actually a deep copy with your copy
//constructor (as well as copy assignement).

using namespace std;

TEST_CASE("IS EMPTY"){
  List l{};
  CHECK(l.is_empty()==true);
 
}


TEST_CASE("Insert first / head "){

  List l{};
  l.insert(1);
  
    
  CHECK(l.is_empty()==false);
}

TEST_CASE("Insert 4 nodes "){

  List l{};
  l.insert(1);
  l.insert(4);
  l.insert(2);
  l.insert(5);
    l.insert(4);
  l.insert(2);
  l.insert(5);
  
  CHECK(l.is_empty()==false);
}

TEST_CASE("print "){

  List l{};
  l.insert(155);
  l.insert(42);
  l.insert(23);
  l.insert(5);
  l.insert(5);
  l.insert(4);
  l.insert(5);
  l.insert(2);
  l.insert(15);
  l.insert(18);
  //  l.print();
  // CHECK(l.is_empty()==false);
  
}

TEST_CASE("size "){

  List l{};
  l.insert(155);
  l.insert(42);
  l.insert(23);
  l.insert(5);
  l.insert(5);
  l.insert(4);
  l.insert(5);
  l.insert(2);
  l.insert(15);
  l.insert(18);
  CHECK(l.getSize()==10);
}

TEST_CASE("index at test "){

  List l{};
  l.insert(155);
  l.insert(42);
  l.insert(23);
  l.insert(15);
  l.insert(5);
  CHECK(l.indexAt(3)==42);
  
}

TEST_CASE("Remove list"){

  List l{};
  l.insert(155);
  l.remove(155);
  CHECK(l.is_empty());
  l.insert(100);
  l.insert(5);
  l.insert(4);
  l.insert(10);
  l.insert(23);
  l.remove(4);
  l.remove(23);
  l.remove(10);
  l.remove(100);
  l.remove(5);
  CHECK(l.is_empty()==true);
}

TEST_CASE("Test copy"){
  List L1{};
  List L2{};
  L1.insert(2);
  L1.insert(1);
  L1.insert(5);
  L1.insert(22);
  L1.insert(24);
  
  L2=L1;
  cout << "L1 ";
  L2.print();
  
  cout << endl;
  cout << "L2 ";
  L1.print();
  cout << endl;
}

List getList(){
List tmp{};
return tmp;
}
TEST_CASE("Test Move"){
  List L1{};
  List L2{std::move(getList())};
  L1.insert(2);
  L1.insert(1);
  L1.insert(5);
  L1.insert(22);
  L1.insert(24);
  
  L2=L1;
  
  cout << "L1 ";
  L2.print();
  
  cout << endl;
  cout << "L2 ";
  L1.print();
  cout << endl;
}


//List l2;
//l2.insert(1);
//List l{std::move(l2)};
//CHECK(print(l) == "1");
