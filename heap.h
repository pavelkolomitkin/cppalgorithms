#ifndef HEAP
#define HEAP

#include "base.h"
#include "sort.h"

namespace algorithms
{
namespace sort{

    template<typename Item>
    class Heap
    {

    private:

        Item* array;

        int size;

        int itemNumber;

        int getLeft(int i) const
        {
            return (i << 1);
        }

        int getRight(int i) const
        {
            return ((i << 1) | 1);
        }

        int getParent(int i) const
        {
            return (i >> 1);
        }

        int getSize() const
        {
            return this->size;
        }

        void setSize(int size)
        {
            this->size = size;
        }

        void maxHeapify(int i)
        {
            int left = this->getLeft(i);
            int right = this->getRight(i);

            int largest = i;

            if ((left <= this->getSize() - 1) && (this->array[left] > this->array[i]))
            {
                largest = left;
            }

            if ((right <= this->getSize() - 1) && (this->array[right] > this->array[largest]))
            {
                largest = right;
            }

            if (largest != i)
            {
                exchange(this->array[i], this->array[largest]);
                this->maxHeapify(largest);
            }
        }

        void buildMaxHeap()
        {
            this->setSize(this->getItemNumber());

            for (int i = this->getItemNumber() / 2; i >= 0; i--)
            {
                this->maxHeapify(i);
            }
        }


    public:
        Heap(int itemNumber)
        {
            this->itemNumber = itemNumber;
            this->array = new Item[this->itemNumber];
        }

        ~Heap()
        {
            delete[] this->array;
            this->itemNumber = 0;
            this->size = 0;
        }

        int getItemNumber()
        {
            return this->itemNumber;
        }

        Item& operator[](int index)
        {
            return this->array[index];
        }

        const Item& operator[](int index) const
        {
            return this->array;
        }

        void sort()
        {
            this->buildMaxHeap();

            for (int i = this->getItemNumber() - 1; i >= 1; i--)
            {
                exchange(this->array[0], this->array[i]);
                this->setSize(this->getSize() - 1);

                this->maxHeapify(0);
            }
        }
    };

}
}

#endif // HEAP

