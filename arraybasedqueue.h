#ifndef ARRAYBASEDQUEUE
#define ARRAYBASEDQUEUE

#include "queue.h"
#include "exceptions/QueueException.h"

using algorithms::exceptions::QueueException;

namespace algorithms
{
    template<typename Item>
    class ArrayBasedQueue: public Queue<Item>
    {
    private:

        unsigned int size;

        int head = -1;
        unsigned int tail = 0;

        Item* store = nullptr;

    public:
        ArrayBasedQueue(unsigned int size)
        {
            this->size = size;
            if (this->size < 1)
            {
                throw QueueException("Size of queue can not be less 1!");
            }

            this->store = new Item[this->size];
        }

        ~ArrayBasedQueue()
        {
            if (this->store == nullptr)
            {
                delete[] this->store;
                this->store = nullptr;
            }
        }

        void enqueue(const Item& item)
        {
            if (this->tail == this->head)
            {
                throw QueueException("Queue is overflow!");
            }

            this->tail = (this->tail >= this->size - 1) ? 0 : this->tail + 1;

            this->store[this->tail] = item;
        }

        Item& dequeue()
        {
            if (this->head < 0 || (this->head == this->tail))
            {
                throw QueueException("Queue is empty");
            }

            Item& result = this->store[this->head];

            this->head = (this->head >= this->size - 1) ? 0 : this->head + 1;

            return result;
        }


    };
}

#endif // ARRAYBASEDQUEUE

