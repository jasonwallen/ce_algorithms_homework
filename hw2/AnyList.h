#ifndef ANYLIST_H
#define ANYLIST_H

#include <iostream>

template <class T, class P>
class anyList 
{

	//private attributes
	T* ListKeys; //To store a list of type T keys to be sorted (e.g. GPA)
	P* ListObjectsP; //To store a list of type P, which is a pointer to
	//an object (e.g. Student*) that is associated with the corresponding key
	int listSize; //Current number of elements in the list
	int listCapacity; //Max number of elements allowed in the list

public:

	//constructor
	anyList(int listCapacity)
	{
		this->listCapacity = listCapacity;
		listSize = 0;

		ListKeys = new T[listCapacity];
		ListObjectsP = new P[listCapacity];
	}

	//destructor
	~anyList()
	{
		delete[] ListKeys;
		delete[] ListObjectsP;
	}

	//adds "key" to the "ListKeys" and "objectPointer" to the
	//"ListObjectsP", then updates the "listSize"
	void addListKey(T key, P objectPointer)
	{
		ListKeys[listSize] = key;
		ListObjectsP[listSize] = objectPointer;

		listSize++;
	}

	//calls the "print info" method for every object in "ListObjectsP"
	void dispList()
	{
		for(int i = 0; i < listSize; i++)
			ListObjectsP[i]->printInfo();
	}

	//sorts "ListKeys" in ascending order of its keys' values and updates
	//the contents of ListObjectsP accordingly.
	void sortList()
	{
		int j;
		T tempT;
		P tempP;

		//Insertion Sort algorithm
		for(int i = 0; i < listSize; i++)
		{
			j = i;
			//check if the current element is smaller than the previous one
			while(j > 0 && ListKeys[j] < ListKeys[j-1])
			{
				//swap the elements in both arrays
				tempT = ListKeys[j];
				ListKeys[j] = ListKeys[j-1];
				ListKeys[j-1] = tempT;

				tempP = ListObjectsP[j];
				ListObjectsP[j] = ListObjectsP[j-1];
				ListObjectsP[j-1] = tempP;

				j--;

			}
		}
	}

};

#endif