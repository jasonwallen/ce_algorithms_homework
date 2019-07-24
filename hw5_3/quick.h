#include <algorithm>

class Quick
{

public:

    //constructor
    Quick(int size, int *array, int first, int last, int &comp, int &move) 
    {
        int sz = last - first + 1;
        if(sz < size)
        {
            insertionSort(sz, array+first, comp, move);
        }
        else
        {
            //create partitions: S1 / Pivot / S2
            int pivotIndex = partition(array, first, last, comp, move);

            //sort subarrays S1 and S2
            Quick(size, array, first, pivotIndex - 1, comp, move);
            Quick(size, array, pivotIndex + 1, last, comp, move);

        }
        
    }
    
    //
    int partition(int *array, int first, int last, int &comp, int &move)
    {
        //choose pivot using median-of-three selection
        int pivotIndex = sortFirstMiddleLast(array, first, last, comp, move);
        
        //reposition pivot so it is last in the array
        std::swap(array[pivotIndex], array[last - 1]);
        move += 3;
        pivotIndex = last - 1;
        int pivot = array[pivotIndex];

        //determine the regions S1 and S2
        int indexFromLeft = first + 1;
        int indexFromRight = last - 2;
        bool done = false;

        while(!done)
        {
            //locate first entry on left that is greater than or equal to pivot
            while(array[indexFromLeft] < pivot)
            {
                indexFromLeft++;
                comp++;
            }
            comp++;

            //locate first entry on right that is less than or equal to pivot
            while(array[indexFromRight] > pivot)
            {
                indexFromRight--;
                comp++;
            }
            comp++;

            if(indexFromLeft < indexFromRight)
            {
                std::swap(array[indexFromLeft], array[indexFromRight]);
                move += 3;
                indexFromLeft++;
                indexFromRight++;
            }
            else
            {
                done = true;
            }
        }
            //place pivot between S1 and S2 and mark its new location
            std::swap(array[pivotIndex], array[indexFromLeft]);
            move += 3;
            pivotIndex = indexFromLeft;
            return pivotIndex;
    }

    //arranges the first, middle, and last entry in sorted order
    int sortFirstMiddleLast(int *array, int first, int last, int &comp, int &move)
    {
        int mid = first + ((last - first) / 2);

        //order the entries
        order(array, first, mid, comp, move);
        order(array, mid, last, comp, move);
        order(array, first, mid, comp, move);

        //pivot point
        return mid;
    }

    //arranges two entries into order if needed
    void order(int *array, int i, int j, int &comp, int &move)
    {
        if(array[i] > array[j])
        {
            std::swap(array[i], array[j]); //exchange enties
            move += 3;
        }
        comp++;
    }
    
    //Insertion sort algorithm

    void insertionSort(int size, int *array, int &comp, int &move)
    {
        for(int i = 1; i < size; i++)
        {
            int next = array[i]; //next item in the array
            int loc = i; //location of unsorted region

            while((loc > 0) && array[loc-1] > next)
            {
                array[loc] = array[loc-1]; //shift the array to the right
                loc--;
                move++;
                comp++;
            }
            comp++;

            //loc is the spot for the next item
            if(loc != i)
            {
                array[loc] = next; //insert next item into the sorted regions
                move++;
            }
        }
    }
};