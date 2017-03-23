#ifndef QUEUE
#define QUEUE

#include "algorithms.h"

namespace algorithms
{
    template<typename Item>
    class Queue
    {
    public:
        Queue()
        {

        }

        virtual ~Queue()
        {

        }

        virtual void enqueue(const Item& item) = 0;

        virtual Item& dequeue() = 0;
    };
}


#endif // QUEUE

