#ifndef QUICKSORT
#define QUICKSORT

#include "base.h"
#include "sort.h"

namespace algorithms
{
namespace sort{

    template<typename Item, typename IndexType>
    IndexType partition(Item array[], IndexType left, IndexType right)
    {
        Item x = array[right];

        IndexType i = left - 1;
        for (IndexType j = left; j < right; j++)
        {
            if (array[j] <= x)
            {
                i++;
                exchange(array[i], array[j]);
            }
        }

        exchange(array[++i], array[right]);

        return i;
    }

    template<typename Item, typename IndexType>
    void quickSort(Item array[], IndexType left, IndexType right)
    {
        if (left < right)
        {
            IndexType pivotIndex = partition(array, left, right);
            quickSort(array, left, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, right);
        }
    }
}
}

#endif // QUICKSORT

