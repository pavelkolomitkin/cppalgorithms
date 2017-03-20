#ifndef BINARYSEARCH
#define BINARYSEARCH

#include "search.h"

namespace algorithms {
namespace search {

    const int ITEM_NOT_FOUNT_INDEX = -1;

    template<typename Item, typename IndexType>
    IndexType binarySearch(Item target, Item array[], IndexType left, IndexType right)
    {
        IndexType result = -1;

        while (left <= right)
        {
            IndexType middle = (left + right) / 2;

            if (target == array[middle])
            {
                result = middle;
                break;
            }
            else if (array[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        return result;
    }

}
}

#endif // BINARYSEARCH

