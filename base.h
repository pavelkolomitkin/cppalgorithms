#ifndef BASE
#define BASE

namespace algorithms
{
    template<typename Item>
    void exchange(Item& item1, Item& item2)
    {
        Item temp = item1;
        item1 = item2;
        item2 = temp;
    }
}

#endif // BASE

