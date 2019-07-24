#include <iostream>

//maintains the bank waiting line
//implemented as a circular array
class ArrayQueue
{
private:
    int QCapacity; //Max size of the queue
    int* IDs; //Array of queue items (the customers' IDs in this case)
    int front; //Index to front of queue
    int back; //Index to back of queue
    int count; //Number of items currently in the queue

public:
    ArrayQueue(int c); //constructor

    ~ArrayQueue(); //destructor

    bool isEmpty(); //checks if the queue is empty

    bool enqueue(const int newID); //insert a new ID to a sorted list

    bool dequeue(); //delete the ID at the front of the list

    int peekFront(); //get the ID at the front of the list

    int queueLength(); //returns the current number of items in the queue
};