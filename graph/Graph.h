#ifndef GRAPH
#define GRAPH

#include "../algorithms.h"

namespace algorithms {

namespace graphs
{
    class Graph
    {
    protected:

        bool isDirected;

        int vertexNumber;

    public:
        Graph(int vertexNumber, bool isDirected)
        {
            this->isDirected = isDirected;
            this->vertexNumber = vertexNumber;
        }

        virtual ~Graph() = 0;

        virtual void addArc(int sourceNumber, int targetNumber) = 0;
    };

}

}

#endif // GRAPH

