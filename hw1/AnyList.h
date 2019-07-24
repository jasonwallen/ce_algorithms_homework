#ifndef ANYLIST_H
#define ANYLIST_H

#include <iostream>

template <class ListType>
class anyList 
{

	//private attributes
	ListType* listElements;
	int listSize;

public:

	//constructor
	anyList(int size)
	{
		listElements = new ListType[size];
		listSize = size;
	}

	//destructor
	~anyList()
	{
		delete[] listElements;
	}

	void insert(int index, ListType element)
	{
		listElements[index] = element;
	}

	//displays the content of the list
	void dispList()
	{
		std::cout << "The list elements are:\n";
		for(int i = 0; i < listSize; i++)
			std::cout << listElements[i] << '\n';
		std::cout << '\n';
	}

	//sorts the list in ascending order
	void sortList()
	{
		int j;
		ListType temp;

		//Insertion Sort algorithm
		for(int i = 0; i < listSize; i++)
		{
			j = i;
			//check if the current element is smaller than the previous one
			while(j > 0 && listElements[j] < listElements[j-1])
			{
				//swap the elements
				temp = listElements[j];
				listElements[j] = listElements[j-1];
				listElements[j-1] = temp;
				j--;
			}
		}
	}

};

#endif