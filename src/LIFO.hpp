#ifndef LIFO_HPP 
#define LIFO_HPP

#include "GetException.hpp"
#include "collection.hpp"
#include <iostream>

/**
 * LIFO implementation of COLLECTION Interface
 * LIFO stands for Last-In-First-Out
 * The maximum capacity of the LIFOArray is not specified is arbitrarily fixed to 20
 * Top element of LIFOArray is only available at all times
 * Operations like Add(),Get(),isEmpty() and size() can only be perfromed on the class objects 
 * \tparam  T refers to the Type of elements stored in the LIFO
 */

template <typename T>
class LIFO: public collection<T>{
    private:                        
   
        T* LIFOArray;                           // pointer to LIFOArray's contents
        size_t top;                             // index pointing to the top element in LIFOArray
        size_t capacity;                        // Maximum allocated buffer size for LIFOArray
   
  
    public:
    
        LIFO();                                 // Default construtor
        LIFO(size_t max_size);                  // Parameterized constructor
        LIFO(const LIFO& other);                // Copy constructor
        virtual ~LIFO();                        // Destructor
        bool Add(const T&) throw(GetException); // Adds an element to the LIFOArray
        T Get() throw(GetException);            // Removes the top element from the LIFOArray and returns it
        bool isEmpty() const;                   // Returns whether the LIFOArray is empty
        size_t size() const;                    // Returns number of elements stored in LIFOArray

};

// LIFO class Function Implementations
template<typename T>
LIFO<T>::LIFO(){
    top = -1;
    capacity = 20;                              // arbitrary capacity chosen
    LIFOArray = new T[capacity];   
}

template<typename T>
LIFO<T>::LIFO(size_t size){
    top = -1;
    capacity = size;
    LIFOArray = new T[capacity];   
}

template<typename T>
LIFO<T>::LIFO(const LIFO& other){
    if (other.isEmpty())
        return;

    LIFOArray = new T[other.capacity];
    capacity = other.capacity;
    top = other.top;

    for (size_t i = 0; i <= top; i++)
        LIFOArray[i] = other.LIFOArray[i];  
}

template<typename T>
LIFO<T>::~LIFO(){
   delete [] LIFOArray; 
   LIFOArray = nullptr;
}

template<typename T>
bool LIFO<T>::isEmpty() const {
    if(top == -1){
        return true;
    }   
    else {
        return false;
    }
}

template<typename T>
bool LIFO<T>::Add(const T& number) throw (GetException){
    if(top == capacity-1){
        throw GetException("Stack Overflow Error: Trying to insert into Stack filled upto its capacity \n");
    }
    else {
        LIFOArray[++top] = number;
        return true;
    }
}

template<typename T>
T LIFO<T>::Get() throw (GetException){
    if(isEmpty()){
        throw GetException("Empty Stack Error: Trying to Get when Stack is empty\n");   
    }
    else {
        return LIFOArray[top--];
    }
}

template<typename T>
size_t LIFO<T>::size() const {
    return top+1;
}

#endif /* LIFO_HPP */