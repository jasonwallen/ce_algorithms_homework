#include <algorithm>

class Bubble
{

public:

    //constructor
    Bubble(int size, int *array, int &comp, int &move) 
    {
        bool sorted = false;
        int pass = 1;

        //sort the array
        while(!sorted && (pass < size))
        {
            sorted = true;
            for(int i = 0; i < size - pass; i++)
            {
                //compare the current index with the next index
                //swap if the next index is less than the current index
                int nextI = i + 1;
                comp++;
                if(array[i] > array[nextI])
                {
                    std::swap(array[i], array[nextI]);
                    move += 3;
                    sorted = false;
                }
            }
            pass++;
        }

    }
    
};