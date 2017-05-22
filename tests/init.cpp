#include <BST.hpp>
#include <catch.hpp>
#include <fstream>

SCENARIO ("init", "[init]")

{

  BST<int> test;

  REQUIRE(test.getroot() == nullptr);
  REQUIRE(test.getcount() == 0);

}

SCENARIO("insert", "[init]")

{

  BST<int> test;

  test.add(10);

  REQUIRE(test.search(5, test.getroot()) == true);

}

SCENARIO("find_node", "[init]")

{

  BST<int> test;

  test.add(10);

  REQUIRE(test.search(10, test.getroot()) != false);

  REQUIRE(test.search(10, test.getroot()) == true);

}

SCENARIO("get root", "[init]")

{

  BST<int> test;

  test.add(10);
	
  REQUIRE(test.getcount() == 1);

  REQUIRE(test.getroot() != 0);

}


SCENARIO ("read/write", "[init]")

{

    BST<int> test1;
    test1.input("File1.txt");
    bool isCatched = false;
  
  try
    {
      test1.output("File2.txt");
    }
    
    catch(bool isCatched)
    {
      isCatched = true;
      throw std::logic_error ("Error.");
    }
   
  REQUIRE(isCatched == false); 

  BST<int> test2;

  test2.input("File2.txt");

  REQUIRE(test1.getcount() == test2.getcount());

}

SCENARIO("deleteX")

{

  BST<int> test;

  test.add(1);

  test.add(2);

  test.add(3);

  test.del(test.getroot(), 1);

  test.del(test.getroot(), 2);

  REQUIRE(test.search(1, test.getroot())== false);
  REQUIRE(test.search(2, test.getroot())== false);

  REQUIRE(test.search(3, test.getroot())== true);

  REQUIRE(test.getcount() == 1);

}
	



