#include "BankTellerService.h"

BankTellerService::BankTellerService(std::string infS, std::string otfS)
{
    //open input file
    inf.open(infS);
    //check if the file opened
    if(inf.fail())
    {
        std::cerr << "Error: Could not open input file\n";
        exit(1);
    }

    //get the total number of customers
    std::string line;
    int totalCustomerNum = 0;
    while (getline(inf, line))
        totalCustomerNum++;
    inf.close();

    //open input file again
    inf.open(infS);
    //check if the file opened
    if(inf.fail())
    {
        std::cerr << "Error: Could not open input file\n";
        exit(1);
    }

    //open output file
    otf.open(otfS);
    //check if the file opened
    if(otf.fail())
    {
        std::cerr << "Error: Could not open output file\n";
        exit(1);
    }

    //Initialize the BankCustomer array
    Customers = new BankCustomer[totalCustomerNum];

    //initialize class parameters
    BusyTeller = false; //teller is free
    CustomersNum = 0; //no current customers
}

BankTellerService::~BankTellerService()
{
    //delete dynamically allocated array
    delete[] Customers;
    
    //close text files
    inf.close();
    otf.close();
}

void BankTellerService::readCustomersInfo()
{
    int count = 0;

    //initialize the temporary variables
    std::string line;
    std::string tempArrivalTime;
    std::string tempTransactionTime;

    //while there are lines to read in
    while(getline(inf, line))
    {
        //set the line to a string stream
        std::stringstream input(line);
        input >> tempArrivalTime >> tempTransactionTime; //read the two attributes

        //add attributes to the Customers array
        Customers[count].ArrivalTime = std::stoi(tempArrivalTime); //convert from str to int
        Customers[count].TransactionLength = std::stoi(tempTransactionTime); //convert from str to int
        Customers[count].ID = count; //get ID
        count++;
    }

    //set the current number of customers to the amount of customers read in from the file
    CustomersNum = count;

    //used to check how many customers there are
    //std::cout << CustomersNum << " customers read.\n";

    for(int i = 0; i < CustomersNum; i++)
    {
        //initliaze and set event attributes
        Event arrival;
        arrival.EventType = 'A';
        arrival.ADTime = Customers[i].ArrivalTime;
        arrival.CustId = i;

        //add event to the list
        EventsQ.enqueue(arrival);
    }

    //used to check when the arrival events are all set up
    //std::cout << "\nArrival events added.\n\n";
}

void BankTellerService::serveCustomers()
{
    otf <<  "Simulation traces:\n";
    
    //while there are events to process
    while(!EventsQ.isEmpty())
    {
        //get the next event in the queue
        Event nextEvent = EventsQ.peekFront();

        //start setting up a departure event
        Event departure;
        departure.EventType = 'D';

        if(nextEvent.EventType == 'A')
        {
            otf << "Processing an arrival event at time\t<-- " << nextEvent.ADTime << "\n";
            
            //flag for arrival event
            //std::cout << "Arrival event found.\n";

            departure.CustId = nextEvent.CustId;

            //if teller is available
            if(!BusyTeller)
            {
                BusyTeller = true; //teller is with a customer

                //ServiceStartTime is when they arrive because the teller is immediately available
                Customers[nextEvent.CustId].ServiceStartTime = nextEvent.ADTime; 

                //A customer's departure time = ServiceStartTime + TransactionLength
                departure.ADTime = Customers[nextEvent.CustId].ServiceStartTime + Customers[nextEvent.CustId].TransactionLength;

                //place the new departure event in the queue
                EventsQ.enqueue(departure);
            }
            else //if teller is busy
            {
                //add customer to the waiting queue
                WaitingQ.enqueue(nextEvent.CustId);
            }
            
        }
        else if(nextEvent.EventType == 'D')
        {
            otf << "Processing a departure event at time --> " << nextEvent.ADTime << "\n";
            
            //flag for departure event
            //std::cout << "Departure event found.\n";

            //if there are customers waiting
            if(!WaitingQ.isEmpty())
            {
                //get the first customer in the waiting line
                departure.CustId = WaitingQ.peekFront();

                //ServiceStartTime is the time of the previous customers departure
                Customers[departure.CustId].ServiceStartTime = nextEvent.ADTime;

                //A customer's departure time = ServiceStartTime + TransactionLength
                departure.ADTime = Customers[departure.CustId].ServiceStartTime + Customers[nextEvent.CustId].TransactionLength;

                //place departure in the EventsQ
                EventsQ.enqueue(departure);
                WaitingQ.dequeue();

            }
            else //if the waiting line is empty
            {
                //mark teller as available
                BusyTeller = false;
            }
            
        }
        else
        {
            //Error for invalid event type
            std::cerr << "Error: Invalid event type\n";
            exit(1);
        }

        //find waitingQMax
        if(WaitingQ.queueLength() > waitingQMax)
            waitingQMax = WaitingQ.queueLength();

        //remove event from queue
        EventsQ.dequeue();

        //flag for event completion
        //std::cout << "Event complete.\n\n";

    }
}


void BankTellerService::getStatistics()
{
    //initalize variables
    double avgWait = 0;
    double maxWait = 0;
    double waitTime = 0;

    //iterate through the Customers array
    for(int i = 0; i < CustomersNum; i++)
    {
        //waitTime = ServiceStartTime - ArrivalTime
        waitTime = Customers[i].ServiceStartTime - Customers[i].ArrivalTime;

        //add it to the total wait time by all customers
        avgWait += waitTime;

        //check if maxWait
        if(waitTime > maxWait)
            maxWait = waitTime; //set as maxWait
    }

    //calculate average wait 
    avgWait = avgWait / CustomersNum;

    //output final statistics
    otf << "\nFinal Statistics:\n"
            << "Total number of customers processd: " << CustomersNum << "\n"
            << "Average waiting time = " << avgWait << "\n"
            << "Maximum waiting time = " << maxWait << "\n"
            << "Maximum waiting queue length = " << waitingQMax << "\n";
}
