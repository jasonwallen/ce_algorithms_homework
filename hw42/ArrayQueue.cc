#include "ArrayQueue.h"

//constructor
ArrayQueue::ArrayQueue(int c)
{
    QCapacity = c;
    IDs = new int[QCapacity];
    front = 0;
    back = QCapacity - 1;
    count = 0;
}

//destructor
ArrayQueue::~ArrayQueue()
{
    delete[] IDs;
}

//checks if the queue is empty
bool ArrayQueue::isEmpty()
{
    return count == 0;
}

//insert a new ID to a sorted list
bool ArrayQueue::enqueue(const int newID)
{
    if(count < QCapacity)
    {
        back = (back + 1) % QCapacity;
        IDs[back] = newID;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

//delete the ID at the front of the list
bool ArrayQueue::dequeue()
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        front = (front + 1) % QCapacity;
        count--; //decrease count
        return true;
    }
}

//get the ID at the front of the list
int ArrayQueue::peekFront()
{
    if(!isEmpty())
        return IDs[front];
    else
    {
        std::cerr << "Error: The queue is empty.\n";
        exit(1);
    }
}

//returns the current number of items in the queue
int ArrayQueue::queueLength()
{
    return count;
}