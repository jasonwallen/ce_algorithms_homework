/*
* Author: Jason Allen
* Due Date: 02/21/2019
* 
* Note: Must be compiled with the following line
* g++ -std=c++11 main.cc -o main
*/

#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
#include "selection.h"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "quick.h"

int move = 0;
int comp = 0;
int sort = 0;
int info[15][2]; //row, column



//check if the array is sorted
bool sorted(int *array, int size)
{
    for(int i = 0; i < size; i ++)
    {
        if(array[i] > array[i + 1])
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
}

//resets the array to the original
int array_reset(int size, int *bst, int *avg, int *wst,
                        int *tbst, int *tavg, int *twst)
{
    //set test arrays equal to original arrays
    for(int i = 0; i < size; i++)
    {
        tbst[i] = bst[i]; 
        tavg[i] = avg[i];
        twst[i] = wst[i];
    }
}

//Selection sort
void selection_sort(int size, int *array)
{
    Selection selectionSort(size, array, comp, move);
    //check if sorted and store move and comp
    if(sorted(array, size))
    {
        info[sort][0] = move;
        info[sort][1] = comp;
        move = 0;
        comp = 0;

    } 
    else
    {   
        //error message
        std::cout << "The selection sort algorithm failed.\n"; 
    }
    sort++;
}

//Bubble sort
void bubble_sort(int size, int *array)
{
    Bubble bubbleSort(size, array, comp, move);
    //check if sorted and store move and comp
    if(sorted(array, size))
    {
        info[sort][0] = move;
        info[sort][1] = comp;
        move = 0;
        comp = 0;

    } 
    else
    {
        //error message
        std::cout << "The bubble sort algorithm failed.\n"; 
    }
    sort++;
}

//Insertion sort
void insertion_sort(int size, int *array)
{
    Insertion insertionSort(size, array, comp, move);
    //check if sorted and store move and comp
    if(sorted(array, size))
    {
        info[sort][0] = move;
        info[sort][1] = comp;
        move = 0;
        comp = 0;

    } 
    else
    {
        //error message
        std::cout << "The insertion sort algorithm failed.\n"; 
    }
    sort++;
}

//Merge sort
void merge_sort(int size, int *array)
{
    Merge mergeSort(size, array, 0, size - 1, comp, move);
    //check if sorted and store move and comp
    if(sorted(array, size))
    {
        info[sort][0] = move;
        info[sort][1] = comp;
        move = 0;
        comp = 0;

    } 
    else
    {
        //error message
        std::cout << "The merge sort algorithm failed.\n"; 
    }
    sort++;
}

//Quick sort
void quick_sort(int size, int *array)
{
    Quick quickSort(size, array, 0, size - 1, comp, move);
    //check if sorted and store move and comp
    if(sorted(array, size))
    {
        info[sort][0] = move;
        info[sort][1] = comp;
        move = 0;
        comp = 0;

    } 
    else
    {
        //error message
        std::cout << "The quick sort algorithm failed.\n"; 
    }
    sort++;
}

//print the array
void print_array()
{
    std::ofstream outf;

    outf.open("sort.txt");
    if(outf.fail())
    {
        std::cerr << "Error: Could not open output file\n";
        exit(1);
    }

    outf << "Moves\tComp\n";
    //std::cout << "Moves\tComp\n";
    //traverse the array
    for(int i = 0; i < 15; i++)
    {
        if(i == 0)
            outf << "\nSELECTION SORT\n --BST--\n";
        else if(i == 1)
            outf << "--AVG--\n";
        else if(i == 2)
            outf << "--WST--\n";
        else if(i == 3)
            outf << "\nBUBBLE SORT\n --BST--\n";
        else if(i == 4)
            outf << "--AVG--\n";
        else if(i == 5)
            outf << "--WST--\n";
        else if(i == 6)
            outf << "\nINSERTION SORT\n --BST--\n";
        else if(i == 7)
            outf << "--AVG--\n";
        else if(i == 8)
            outf << "--WST--\n";
        else if(i == 9)
            outf << "\nMERGE SORT\n --BST--\n";
        else if(i == 10)
            outf << "--AVG--\n";
        else if(i == 11)
            outf << "--WST--\n";
        else if(i == 12)
            outf << "\nQUICK SORT\n --BST--\n";
        else if(i == 13)
            outf << "--AVG--\n";
        else if(i == 14)
            outf << "--WST--\n";

        for(int j = 0; j < 2; j++)
        {
            //std::cout << info[i][j] << '\t'; //print the array to the console
            outf << info[i][j] << '\t'; //print the arsay to sort.txt
        }
        outf << '\n';
        //std::cout << '\n';
    }

    outf.close(); //close the file
}


int main()
{
    const int ARRAY_SIZE = 1000; //allows the user to change the size of the array
    //statically initialize the three arrays
    int BST[ARRAY_SIZE];
    int AVG[ARRAY_SIZE];
    int WST[ARRAY_SIZE];

    //initialize test arrays
    int tBST[ARRAY_SIZE];
    int tAVG[ARRAY_SIZE];
    int tWST[ARRAY_SIZE];    

    
    srand(time(NULL)); //the seed will be different every time the code is run

    //for loop to fill all three arrays
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        BST[i] = i; //ascending order
        WST[ARRAY_SIZE-i] = i; //descending order
        AVG[i] = rand() % 100000; //randomly between 0 and 100,000
    }

    //set test arrays equal to original arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    //selection sort all arrays
    selection_sort(ARRAY_SIZE, tBST);
    selection_sort(ARRAY_SIZE, tAVG);
    selection_sort(ARRAY_SIZE, tWST);

    //reset arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    //bubble sort all arrays
    bubble_sort(ARRAY_SIZE, tBST);
    bubble_sort(ARRAY_SIZE, tAVG);
    bubble_sort(ARRAY_SIZE, tWST);
    
    //reset arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    //insertion sort all arrays
    insertion_sort(ARRAY_SIZE, tBST);
    insertion_sort(ARRAY_SIZE, tAVG);
    insertion_sort(ARRAY_SIZE, tWST);
    
    //reset arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    //merge sort all arrays
    merge_sort(ARRAY_SIZE, tBST);
    merge_sort(ARRAY_SIZE, tAVG);
    merge_sort(ARRAY_SIZE, tWST);
    
    //reset arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    //quick sort all arrays
    quick_sort(ARRAY_SIZE, tBST);
    quick_sort(ARRAY_SIZE, tAVG);
    quick_sort(ARRAY_SIZE, tWST);
    
    //reset arrays
    array_reset(ARRAY_SIZE, BST, AVG, WST, tBST, tAVG, tWST);

    print_array();

    return 0;
    
}
