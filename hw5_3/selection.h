#include <algorithm>

class Selection
{

public:

    //constructor
    Selection(int size, int *array, int &comp, int &move) 
    {
        for(int last = size; last >= 1; last--)
        {
            //find the largest element in the array
            int largest = findIndexofLargest(array, last+1, comp);
        
            //put largest element at the end
            if(largest != last)
            {
                move+=3;
                std::swap(array[largest], array[last]);
            }
        
        }

    }
    
    int findIndexofLargest(int *array, int size, int &comp)
    {
        int indexOfBig = 0; //index of largest entry found so far
        
        //i is the current index
        for(int i = 0; i < size; i++)
        {
            if(array[i] > array[indexOfBig])
            {
                indexOfBig = i;
            }
            comp++;
        }

        return indexOfBig;
    }

};