#ifndef ADJANCENCYLISTGRAPH
#define ADJANCENCYLISTGRAPH

#include "Graph.h"
#include "Vertex.h"
#include "../exceptions/GraphException.h"

using algorithms::exceptions::GraphException;

namespace algorithms
{
namespace graphs {

    class AdjancencyListGraph: public Graph
    {
    private:
        Vertex* list;

    public:
        AdjancencyListGraph(int vertexNumber, bool isDirected): vertexNumber(vertexNumber), isDirected(isDirected)
        {
            this->list = new Vertex[this->vertexNumber];
        }

        ~AdjancencyListGraph()
        {
            delete[] this->list;
        }

        void addArc(int sourceNumber, int targetNumber)
        {
            if ((sourceNumber < 0) || (targetNumber < 0)
                || (sourceNumber > this->vertexNumber - 1)
                || (targetNumber > this->vertexNumber - 1))
            {
                throw GraphException("Source or target number are't in graph!");
            }



        }

    };
}
}

#endif // ADJANCENCYLISTGRAPH

