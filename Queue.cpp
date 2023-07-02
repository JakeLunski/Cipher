// Jake Lunski
// CPSC 1071-002
// Binary Beasts
// 4/3/2023

#include "Queue.h"

using namespace std;

// Constructor for Queue class
Queue::Queue(int capacity) : front(nullptr), rear(nullptr), count(0), capacity(capacity) {} 

// Destructor for Queue class
Queue::~Queue() {
    while (!isEmpty()) {
        int temp;           // holds dequeued vals
        dequeue(temp);      // Remove all nodes from the queue
    }
}

// Enqueue method for Queue class
void Queue::enqueue(int data) {
    if (!isFull()){
        Node* newNode = new Node;   // Create new node
        newNode->data = data;       // Set data of new node
        newNode->next = nullptr;    // Set next of new node to null

        if (rear != nullptr) {      // If there is at least one node in the queue
            rear->next = newNode;   // Set next of rear node to the new node 
        }

        rear = newNode;             // Set rear of queue to the new node

        if (front == nullptr) {     // If there were no nodes in the queue
            front = rear;           // Set front of queue to the new node
        }
        count++;
    }
    else {
        cout<<"The queue is full"<<endl;
    }
}

// Dequeue method for Queue class
void Queue::dequeue(int &val) {
    if (!isEmpty()) {                        // If the queue is empty handle empty queue case
        val = front->data;          // Save the data of the front node
        Node* temp = front;         // Save the address of the front node
        front = front->next;        // Set the front of the queue to the next node

        if (front == nullptr) {            // If the queue is now empty
                rear = nullptr;         // Set the rear of the queue to null
        }
        delete temp;                // Delete temp, Free the memory allocated for the front node
        count--;
    }

    else {
        cout<< "The queue is empty\n";     // Print error message to console
    }
}

bool Queue::isFull() {
    return count >= capacity;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return front == 0;
}
