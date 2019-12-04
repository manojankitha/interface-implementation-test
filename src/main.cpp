#include "LIFO.hpp"
#include "FIFO.hpp"
#include <iostream>

int main()
{

  std::cout<< "Entering main code\n";
  LIFO<int> sObj;
  FIFO<int> qObj;
  
  // Performing operations on instance of LIFO class
  sObj.Add(10);                            // Adds 10 to sObj
  std::cout<<sObj.isEmpty()<<std::endl;    // prints 0
  std::cout<<sObj.Get()<<std::endl;        // prints 10
  std::cout<<sObj.isEmpty()<<std::endl;    // prints 1
    
  try{
    std::cout<<sObj.Get()<<std::endl;      // Get on empty stack throws an exception, control moves to catch block
  }
  catch(GetException& e){
    std::cout<<e.what();                   // prints "Empty Stack Error: Trying to Get when Stack is empty"
  }
  
  //Performing operations on instance of FIFO class
  qObj.Add(10);
  std::cout<<qObj.isEmpty()<<std::endl;
  std::cout<<qObj.Get()<<std::endl;
  std::cout<<qObj.isEmpty()<<std::endl;

  try{
    std::cout<<qObj.Get()<<std::endl;      // Get on empty queue throws an exception, control moves to catch block
  }
  catch(GetException& e){
    std::cout<<e.what();                   // Empty Queue Error: Trying to Get when Queue is empty
  }

  return 0;
  
}
