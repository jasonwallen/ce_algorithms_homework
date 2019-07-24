#include "Event.h"
#include <iostream>

//priority queue that maintains simulation events
class PQueue
{
private:
    int QCapacity; //Max size of the queue
    Event* events; //Pointer to the array that holds arrival and departure events
    int count; //Number of events currently in the queue

    bool listInsert(Event ev); //Insert a new event to a sorted list
    
    bool listDelete(); //Delete the event at the end of the list
    
    Event listPeek(); //Get the event at the end of the list

public:
    PQueue(int c); //c for the QCapacity

    ~PQueue(); //destructor

    bool isEmpty(); //Checks if the queue is empty

    bool enqueue(Event ev); //calls listInsert() to insert a new event

    bool dequeue(); //calls listDelete() to remove the queue's front event

    Event peekFront(); //calls listPeek() to return the queue's front event
};

