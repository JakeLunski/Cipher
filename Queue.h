// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* front;    // pointer to the front node of the queue.
    Node* rear;     // pointer to the rear node of the queue.
    int count;      // keeps track of the number of elements in the queue
    int capacity;   // the maximum number of elements allowed in the queue

public:
    Queue(int capacity = 100);  // constructor that sets the capacity to 100
    ~Queue();       // destructor to clear memory from queue
    void enqueue(int value);    // adds int elementer to the rear of the queue
    void dequeue(int &val);     // removes the front element of the queue
    bool isFull() ;         // checks if the queue has reached capcity
    bool isEmpty() ;        // returns true if the queue is full or false if empty
};

#endif 