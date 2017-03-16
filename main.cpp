#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "heap.h"

using namespace std;

using algorithms::sort::Heap;


int main()
{
    Heap<int>* heap = new Heap<int>(123);

    int min = 0;
    int max = 100;

    for (int i = 0; i < heap->getItemNumber(); i++)
    {
        int random = min + (rand() % (int)(max - min + 1));
        (*heap)[i] = random;
    }

    heap->sort();

    for (int i = 0; i < heap->getItemNumber(); i++)
    {
        cout << (*heap)[i] << endl;
    }

    delete heap;

    return 0;
}

