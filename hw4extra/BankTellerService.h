#include "BankCustomer.h"
#include "PQueue.h"
#include "ArrayQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

class BankTellerService
{
    //bool BusyTeller; //indicates if the teller is currently busy or available
    int CustomersNum; //the total number of customers in the simulation
    std::ifstream inf; //text file with the arrival and transaction times
    std::ofstream otf; //text file with the trace messages and the final statistics
    ArrayQueue WaitingQ = ArrayQueue(100); //waitingQCapacity is just the number of customers
    PQueue EventsQ = PQueue(100); //eventsQCapacity is just the number of customers times 2 due to there being only 2 possible events
    BankCustomer* Customers; //array of the customer objects in the simulation
    int waitingQMax = 0; //the maximum length of the waiting queue

    //extra credit
    int freeTellers; //indicates the number of available tellers
    int tellerNum; //indicates the number of tellers

public:
    //constructor
    BankTellerService(std::string infS, std::string otfS);

    //destructor
    ~BankTellerService();

    void readCustomersInfo(); //reads the customers' arrival and transaction time
                                //from the input file. For each arrival data, add one
                                //customer object in the Customers array and insert
                                //an arrival event in the EventsQ.

    void serveCustomers(); //executes a loop that continues as long as there are events
                            //in the EventsQ. Serve each event in order and according to
                            //the event type (Arrival or Departure). A customer who recieves
                            //service from an available teller will result in a departure event
                            //to be inserted in the EventQ. An arrival event with a busy teller
                            //will result in adding the corresponding customer ID in the WaitingQ.
                            //A departure event results in serving a Customer from the WaitingQ or
                            //mark the teller as available (if the WaitingQ is empty)

    void getStatistics(); //calculates the needed statistics based on the updated data of the
                            //customers and stores these statistics in the output text file
};