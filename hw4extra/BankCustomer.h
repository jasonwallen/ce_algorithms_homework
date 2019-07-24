#include <ctime>

//maintains the data of each customer that arrives at the bank
class BankCustomer
{
public:

    //attributes
    int ID;
    int ArrivalTime;
    int ServiceStartTime;
    int TransactionLength;

    //queueing waiting time = ServiceStartTime - ArrivalTime
    //departure time = ServiceStartTime + TransactionLength

};