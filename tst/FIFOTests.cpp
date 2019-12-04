#include "FIFO.hpp"
#include "gtest/gtest.h"
#include "GetException.hpp"

/**
 * FIFOTestCase is a Test Fixture that implements the Unit Testing for FIFO 
 * Provided Unit Test for each operation on FIFO object
 * Tests written in Googletest xUnit framework
 */


/** TEST FIXTURE **/
class FIFOTestCase : public :: testing :: Test{
  protected:
    // Test Object
    FIFO<int> * FIFOArray;
  
    // Allocate memory before every test
    virtual void SetUp(){ 
      FIFOArray = new FIFO<int>;
    }

    // Deallocate memory after every test
    virtual void TearDown(){
      delete FIFOArray;
      FIFOArray = nullptr;  
    }

    /** HELPER FUNCTIONS **/

    // Exception Handling for Get() called on empty FIFOArray 
    void TestGetException(){
      try{
        int popped_item = FIFOArray->Get();
      }
      catch(GetException& e){
        std::cout<<e.what();
      }
    }

    // Exception Handling for adding element when FIFOArray is full
    void TestAddException(){
      try{
        ASSERT_EQ(FIFOArray->Add(5),true);
      }
      catch(GetException& e){
        std::cout<<e.what();
      }
    }
};

/** TESTS **/

// Test for isEmpty() function
TEST_F(FIFOTestCase,testisEmpty){
  ASSERT_TRUE(FIFOArray->isEmpty());
  FIFOArray->Add(1);
  ASSERT_FALSE(FIFOArray->isEmpty());
}

// Test for size() function
TEST_F(FIFOTestCase,testsize){
  int num1 = 5, num2 = 10;
  ASSERT_EQ(FIFOArray->size(),0);
  ASSERT_EQ(FIFOArray->Add(num1),true);
  ASSERT_EQ(FIFOArray->size(),1);
  ASSERT_EQ(FIFOArray->Add(num2),true);
  ASSERT_EQ(FIFOArray->size(),2);
  ASSERT_EQ(FIFOArray->Get(),num1);
  ASSERT_EQ(FIFOArray->size(),1);
  ASSERT_EQ(FIFOArray->Get(),num2);
  ASSERT_EQ(FIFOArray->size(),0);
  
}

// Test for Add() function
TEST_F(FIFOTestCase,testAdd){
  int num1 = 5, num2 = 10, num3 = 15;
  ASSERT_EQ(FIFOArray->Add(num1),true);
  ASSERT_EQ(FIFOArray->size(),1);
  ASSERT_EQ(FIFOArray->Add(num2),true);
  ASSERT_EQ(FIFOArray->size(),2);
  ASSERT_EQ(FIFOArray->Add(num3),true);
  ASSERT_EQ(FIFOArray->size(),3);
}

// test for Get() function
TEST_F(FIFOTestCase,testGet){
  int num1 = 5, num2 = 10, num3 = 15;
  ASSERT_EQ(FIFOArray->Add(num1),true);
  ASSERT_EQ(FIFOArray->size(),1);
  ASSERT_EQ(FIFOArray->Get(),num1);
  ASSERT_TRUE(FIFOArray->isEmpty());
  TestGetException();                       // Tests that Exception is thrown and catch block is executed
  ASSERT_EQ(FIFOArray->Add(num3),true);
  ASSERT_EQ(FIFOArray->Add(num2),true);
  ASSERT_EQ(FIFOArray->Add(num1),true);
  ASSERT_EQ(FIFOArray->Get(),num3);
  ASSERT_EQ(FIFOArray->size(),2);
  ASSERT_EQ(FIFOArray->Get(),num2);
  ASSERT_EQ(FIFOArray->size(),1);
  ASSERT_EQ(FIFOArray->Get(),num1);
  ASSERT_EQ(FIFOArray->size(),0);
}
