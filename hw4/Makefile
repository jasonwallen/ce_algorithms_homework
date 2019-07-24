main: main.o BankTellerService.o PQueue.o ArrayQueue.o
	g++ -std=c++11 main.o BankTellerService.o PQueue.o ArrayQueue.o -o main

main.o: BankTellerService.h main.cc
	g++ -std=c++11 -c main.cc 

BankTellerService.o: BankTellerService.h BankTellerService.cc ArrayQueue.h Event.h BankCustomer.h PQueue.h
	g++ -std=c++11 -c BankTellerService.cc 

PQueue.o: PQueue.h PQueue.cc
	g++ -std=c++11 -c PQueue.cc

ArrayQueue.o: ArrayQueue.h ArrayQueue.cc
	g++ -std=c++11 -c ArrayQueue.cc

clean:
	rm -f *.o main