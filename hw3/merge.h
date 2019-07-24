class Merge
{

public:

    //constructor
    Merge(int size, int *array, int first, int last, int &comp, int &move) 
    {
        if(first < last)
        {
            int mid = first + ((last - first)/ 2); //midpoint

            //sort first half
            Merge(size, array, first, mid, comp, move);

            //sort second half
            Merge(size, array, mid + 1, last, comp, move);

            //merge the two halfs
            merge(size, array, first, mid, last, comp, move);
        }
    }
    
    //merge two arrays
    void merge(int size, int* array, int first, int mid, int last, int &comp, int &move)
    {
        int temp[size]; //temporary array

        //Initialize local indicies to indicate subarrays
        //first subarray
        int first1 = first;
        int last1 = mid;
        //second subarray
        int first2 = mid + 1;
        int last2 = last;

        int index = first1; //nex location in temp
        while((first1 <= last1) && (first2 <= last2))
        {
            //compare first element of both subarrays
            if(array[first1] <= array [first2])
            {
                //first element of first subarray is smaller
                //gets put in the temp array first
                temp[index] = array[first1];
                first1++;
            } 
            else
            {
                //first element of second subarray is smaller
                //gets put in the temp array first
                temp[index] = array[first2];
                first2++;
            }
            comp++;
            move++;
            index++;
        }

        //finish first subarray if needed
        while(first1 <= last1)
        {
            temp[index] = array[first1];
            first1++;
            index++;
            move++;
        }

        //finish second subarray if needed
        while(first2 <= last2)
        {
            temp[index] = array[first2];
            first2++;
            index++;
            move++;
        }

        //copy results back into the original array
        for(index = first; index <= last; index++)
        {
            array[index] = temp[index];
            move++;
        }
    }
};