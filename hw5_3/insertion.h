class Insertion
{

public:

    //constructor
    Insertion(int size, int *array, int &comp, int &move) 
    {
        for(int i = 1; i < size; i++)
        {
            int next = array[i]; //next item in the array
            int loc = i; //location of unsorted region

            while((loc > 0) && (array[loc-1] > next))
            {
                comp++;
                array[loc] = array[loc-1]; //shift the array to the right
                move++;
                loc--;
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