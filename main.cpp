#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "quicksort.h"
#include "binarysearch.h"

using namespace std;

using algorithms::search::binarySearch;
using algorithms::search::ITEM_NOT_FOUNT_INDEX;
using algorithms::sort::quickSort;

template<typename Item, typename SizeType>
void showArray(Item array[], SizeType size)
{
    for (SizeType i = 0; i < size; i++)
    {
        cout << "[" << i << "] = " << array[i] << endl;
    }

    cout << endl;
}

int main()
{
    srand(time(nullptr));

    const int MAX_ITEMS = 100;

    float* array = new float[MAX_ITEMS];
    float minValue = 20.6;
    float maxValue = 98.1;

    float randValue = 0.0;

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        randValue = minValue + (maxValue - minValue) * ((float)rand() / (float) RAND_MAX);
        array[i] = randValue;
    }

    quickSort(array, 0, MAX_ITEMS - 1);
    showArray(array, MAX_ITEMS);

    int searchIndex = binarySearch(randValue, array, 0, MAX_ITEMS - 1);
    if (searchIndex != ITEM_NOT_FOUNT_INDEX)
    {
        cout << "Item with value: " << randValue << " has index " << searchIndex << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }


    delete[] array;


    return 0;
}

