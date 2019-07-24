#include "PQueue.h"


//private functions


//Insert a new event to a sorted list
bool PQueue::listInsert(Event ev)
{
    //check if the array is less than max capacity   
    if(count < QCapacity)
    {
        //add the event into the array
        events[count] = ev;

        //increment the current number of events in the array
        count++;

        //Descending sort algorithm
        for(int i = 0; i <= count; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(events[i].ADTime >= events[j].ADTime)
                {
                    //swap
                    Event tempEvent = events[i];
                    events[i] = events[j];
                    events[j] = tempEvent;
                }
            }
        }

        //print queue times to check if sorted
        // for(int i = 0; i < count; i++)
        // {
        //     std::cout << events[i].ADTime << ' ';
        // }
        // std::cout << "\n";

        //check the event type of the first event in the queue
        //std::cout << "First event is " << events[count-1].EventType << "\n";

        return true;
    }
    else
    {
        return false;
    }
    
}

//Delete the event at the end of the list
bool PQueue::listDelete()
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        count--; //decrease count

        //print queue to make sure event was deleted correctly
        // for(int i = 0; i < count; i++)
        //     std::cout << events[i].ADTime << ' ';
        // std::cout << "\n";
        // std::cout << "Next event is " << events[count-1].EventType << "\n";

        return true;
    }
    
}

//Get the event at the end of the list
Event PQueue::listPeek()
{
    if(!isEmpty())
        return events[count-1]; //return the front of the queue which is the back
    else
    {
        std::cerr << "The list is empty.\n";
        exit(1);
    }
}

//public functions

//constuctor
PQueue::PQueue(int c)
{
    QCapacity = c;
    events = new Event[QCapacity];
    count = 0;
}

//destructor
PQueue::~PQueue()
{
    delete[] events;
}

//Checks if the queue is empty
bool PQueue::isEmpty()
{
    if(count == 0)
        return true;
    else
        return false;    
}

//calls listInsert() to insert a new event
bool PQueue::enqueue(Event ev)
{
    return listInsert(ev);
}

//calls listDelete() to remove the queue's front event
bool PQueue::dequeue()
{
    return listDelete();
}

//calls listPeek() to return the queue's front event
Event PQueue::peekFront()
{
    return listPeek();
}
