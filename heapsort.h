
#ifndef HEAP_SORT
#define HEAP_SORT

#include "base.h"

namespace algorithms
{
    namespace sort
    {
        namespace heap
        {
            template<typename Item>
            void fixUp(Item array[], int k)
            {
                while (k > 1 && array[k/2] < array[k])
                {
                    Item temp = array[k];
                    array[k] = array[k/2];
                    array[k/2] = temp;
                    k /= 2;
                }
            }

            template<typename Item>
            void fixDown(Item array, int k, int N)
            {
                while (2 * k <= N)
                {
                    int j = 2 * k;

                    if (j < N && array[j] < array[j + 1]) j++;
                    if (!(array[k] < array[j])) break;

                    exchange(array[k], array[j]); k = j;
                }
            }

            void heapSort()
            {

            }
        }
    }
}

#endif
