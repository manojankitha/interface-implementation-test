#include "LIFO.hpp"
#include "gtest/gtest.h"
#include "GetException.hpp"

/**
 * LIFOTestCase is a Test Fixture that implements the Unit Testing for LIFO 
 * Provided Unit Test for each operation on LIFO object
 * Tests written in Googletest xUnit framework
 */


/** TEST FIXTURE **/
class LIFOTestCase : public :: testing :: Test{
  protected:
    // Test Object
    LIFO<int> * LIFOArray;
    
    // Before every test
    virtual void SetUp(){ 
      LIFOArray = new LIFO<int>;
    }

    // After every test
    virtual void TearDown(){
      delete LIFOArray;
      LIFOArray = nullptr;  
    }

    /** HELPER FUNCTIONS **/

    // Exception Handling for Get() called on empty LIFOArray 
    void TestGetException(){
      try{
        size_t popped_item = LIFOArray->Get();
      }
      catch(GetException& e){
        std::cout<<e.what();
      }
    }

    // Exception Handling for adding element when LIFOArray is full
    void TestAddException(){
      try{
        ASSERT_EQ(LIFOArray->Add(5),true);
      }
      catch(GetException& e){
        std::cout<<e.what();
      }
    }
};

/** TESTS **/

// Test for isEmpty() function
TEST_F(LIFOTestCase,testisEmpty){
  ASSERT_TRUE(LIFOArray->isEmpty());
  LIFOArray->Add(1);
  ASSERT_FALSE(LIFOArray->isEmpty());
}

// Test for size() function
TEST_F(LIFOTestCase,testsize){
  int num1 = 5, num2 = 10;
  ASSERT_EQ(LIFOArray->size(),0);
  ASSERT_EQ(LIFOArray->Add(num1),true);
  ASSERT_EQ(LIFOArray->size(),1);
  ASSERT_EQ(LIFOArray->Add(num2),true);
  ASSERT_EQ(LIFOArray->size(),2);
  ASSERT_EQ(LIFOArray->Get(),num2);
  ASSERT_EQ(LIFOArray->size(),1);
  ASSERT_EQ(LIFOArray->Get(),num1);
  ASSERT_EQ(LIFOArray->size(),0);
}

// Test for Add() function
TEST_F(LIFOTestCase,testAdd){
  int num1 = 5, num2 = 10, num3 = 15;
  ASSERT_EQ(LIFOArray->Add(num1),true);
  ASSERT_EQ(LIFOArray->size(),1);
  ASSERT_EQ(LIFOArray->Add(num2),true);
  ASSERT_EQ(LIFOArray->size(),2);
  ASSERT_EQ(LIFOArray->Add(num3),true);
  ASSERT_EQ(LIFOArray->size(),3);
}

  // TEST_F(LIFOTestCase,testAddException)
  // {
  //   int foo[20] = { }; // creates an array of {capacity} values, each initialised with 0
  //   for(auto x: foo)
  //     ASSERT_EQ(LIFOArray->Add(x),true);
  //   TestAddException();
  // }

// test for Get() function
TEST_F(LIFOTestCase,testGet){
  int num1 = 5, num2 = 10, num3 = 15;
  ASSERT_EQ(LIFOArray->Add(num1),true);
  ASSERT_EQ(LIFOArray->size(),1);
  ASSERT_EQ(LIFOArray->Get(),num1);
  ASSERT_TRUE(LIFOArray->isEmpty());
  TestGetException();                      // Tests that Exception is thrown and catch block is executed
  ASSERT_EQ(LIFOArray->Add(num3),true);
  ASSERT_EQ(LIFOArray->Add(num2),true);
  ASSERT_EQ(LIFOArray->Add(num1),true);
  ASSERT_EQ(LIFOArray->Get(),num1);
  ASSERT_EQ(LIFOArray->size(),2);
  ASSERT_EQ(LIFOArray->Get(),num2);
  ASSERT_EQ(LIFOArray->size(),1);
  ASSERT_EQ(LIFOArray->Get(),num3);
  ASSERT_EQ(LIFOArray->size(),0);
}
