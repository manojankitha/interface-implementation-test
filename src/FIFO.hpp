#ifndef FIFO_HPP
#define FIFO_HPP

#include "GetException.hpp"
#include "collection.hpp"
#include <iostream>

/**
 * FIFO implementation of COLLECTION Interface
 * FIFO stands for First-In-First-Out
 * The maximum capacity of the FIFOArray is not specified is arbitrarily fixed to 20
 * Operations like Add(),Get(),isEmpty() and size() can only be perfromed on the class objects 
 * \tparam  T refers to the Type of elements stored in the FIFO
 */
 
template <typename T>
class FIFO: public collection<T>{
    private: 
        T* FIFOArray;                              // pointer to FIFOArray's contents
        size_t front;                              // index of least recently added element of FIFOArray
        size_t rear;                               // index of most recently added element of FIFOArray                                         
        size_t capacity;                           // Maximum allocated buffer size for FIFOArray
   
  
    public:
    
    FIFO();                                        // Default construtor
    FIFO(size_t max_size);                         // Parameterized constructor
    FIFO(const FIFO& other);                       // Copy constructor
    virtual ~FIFO();                               // Destructor
    bool Add(const T&) throw (GetException);       // Adds an element at the rear end of FIFOArray 
    T Get() throw (GetException);                  // Removes element at front index from the FIFOArray and returns it
    bool isEmpty() const;                          // Returns whether the FIFOArray is empty
    size_t size() const;                           // Returns number of elements stored in FIFOArray

};

// FIFO class Function Implementations 
template<typename T>
FIFO<T>::FIFO(){
    front = -1;
    rear = -1;
    capacity = 20;                                 // arbitrary capacity chosen
    FIFOArray = new T[capacity];   
}

template<typename T>
FIFO<T>::FIFO(size_t size){
    front = -1;
    rear = -1;
    capacity = size;
    FIFOArray = new T[capacity];   
}

template<typename T>
FIFO<T>::FIFO(const FIFO& other){
    if (other.isEmpty())
        return;

    FIFOArray = new T[other.capacity];
    capacity = other.capacity;
    front = other.front;
    rear = other.rear;

    for (size_t i = front; i <= rear; i++)
        FIFOArray[i] = other.FIFOArray[i];  
}

template<typename T>
FIFO<T>::~FIFO(){
   delete [] FIFOArray; 
   FIFOArray = nullptr;
}


template<typename T>
bool FIFO<T>::isEmpty() const {
    if(front == -1){
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool FIFO<T>::Add(const T& number) throw (GetException){
    
    if(rear == capacity-1)
        {
            throw GetException("Queue Overflow Error: Trying to insert into a Queue filled upto its capacity \n");   
        }
    else
    {
        if(front == -1)
            front++;
        FIFOArray[++rear] = number;  
        return true;
    }

         
}

template<typename T>
T FIFO<T>::Get() throw (GetException){
    if(isEmpty())
    {
        throw GetException("Empty Queue Error: Trying to Get when Queue is empty\n");   
    }
    else 
        {   T temp =  FIFOArray[front];
            if (front == rear)
                front  = rear = -1;
            else
                front++;
            return temp;
        }
}

template<typename T>
size_t FIFO<T>::size() const {
    if(isEmpty()){
        return 0;
    }
    else {
        return rear-front+1;
    }   
}

#endif /* FIFO_HPP */