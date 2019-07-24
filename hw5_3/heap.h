#include <algorithm>

class Heap
{

public:

    //constructor
    Heap(int size, int *array, int &comp, int &move)
    {
        int heapSize = size;

        //converts array content into a heap
        heapCreate(size, array, comp, move);

        //array[0] is the largest item
        //swap it with the end of the heap and decrease the heap size
        //repeate the same process until the heap size is 1
        while(heapSize > 1)
        {
            std::swap(array[0], array[heapSize-1]);
            move += 3;
            heapSize--;
            heapRebuild(0, array, heapSize, comp, move);
        }
    }

    void heapCreate(int size, int *array, int &comp, int &move)
    {
        for(int i = (size/2)-1; i >= 0; i--)
        {
            heapRebuild(i, array, size, comp, move);
        }
    }

    void heapRebuild(int root, int *array, int size, int &comp, int &move)
    {
        //root is not a leaf
        if(root < size/2)
        {
            //left child index
            int largerChildIndex = 2 * root + 1;

            //the root has a right child
            if(2 * root + 2 < size)
            {
                //right child index
                int rightChildIndex = 2 * root + 2;

                if(array[rightChildIndex] > array[largerChildIndex])
                {
                    largerChildIndex = rightChildIndex;
                }
                comp++;
            }

            //if the item in the root is smaller than the item in the larger child, swap
            if(array[root] < array[largerChildIndex])
            {
                std::swap(array[root], array[largerChildIndex]);
                move += 3;
                heapRebuild(largerChildIndex, array, size, comp, move);
            }
            comp++;
        }
    }
};