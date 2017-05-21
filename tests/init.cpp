#include <BST.h>
#include <catch.hpp>
#include <fstream>

SCENARIO ("init", "[init]")

{

  Tree<int> test;

  REQUIRE(test.getroot() == nullptr);
  REQUIRE(test.getcount() == 0);

}

SCENARIO("insert", "[init]")

{

  Tree<int> test;

  test.add(10);

  REQUIRE(test.find_node(5, test.getroot()) == true);

}

SCENARIO("find_node", "[init]")

{

  Tree<int> test;

  test.add(10);

  REQUIRE(test.find_node(10, test.getroot()) != nullptr);

  REQUIRE(test.find_node(10, test.getroot()) == true);

}

SCENARIO("get root", "[init]")

{

  Tree<int> test;

  test.add(10);
	
  REQUIRE(test.getcount() == 1);

  REQUIRE(test.getroot() != 0);

}


SCENARIO ("read/write", "[init]")

{

    Tree<int> test1;
    test1.read("File1.txt");
    bool isCatched = false;
  
  try
    {
      test1.write("File2.txt");
    }
    
    catch(bool isCatched)
    {
      isCatched = true;
      throw std::logic_error ("Error.");
    }
   
  REQUIRE(isCatched == false); 

  Tree<int> test2;

  test2.read("File2.txt");

  REQUIRE(test1.getcount() == test2.getcount());

}

SCENARIO("deleteX")

{

  Tree<int> test;

  test.add(1);

  test.add(2);

  test.add(3);

  test.del(1);

  test.del(2);

  REQUIRE(test.find_node(1, test.getroot())== false);
  REQUIRE(test.find_node(2, test.getroot())== false);

  REQUIRE(test.find_node(3, test.getroot())== true);

  REQUIRE(test.getcount() == 1);

}
	



