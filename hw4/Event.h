#include <ctime>

//represents the simulation customers' arrival and departure events
class Event
{
public:

    char EventType; //'A' for arrival and 'D' for departure
    int CustId; //ID of the customer who created the event
    int ADTime; //Arrival or Departure time

};
