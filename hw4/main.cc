//compile everything using -std=c++11

#include "BankTellerService.h"

int main()
{
    BankTellerService myBank("input.txt", "output.txt");
    myBank.readCustomersInfo();
    myBank.serveCustomers();
    myBank.getStatistics();
    return 0; 
}
