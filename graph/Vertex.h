#ifndef GRAP_VERTEX
#define GRAP_VERTEX

#include "../algorithms.h"

namespace algorithms {

namespace graphs
{
    enum VertexColor {WHITE, GRAY, BLACK};

    template<typename Item>
    class Vertex
    {
    private:
        Item* data;

        Vertex* parent;

        int dist;

        VertexColor color;



    public:
        Vertex(Item* data = nullptr)
        {
            this->data = data;
            this->setColor(VertexColor::WHITE);
            this->setDist(0);
            this->setParent(nullptr);
        }

        Item* getData() const
        {
            return this->data;
        }

        VertexColor getColor() const
        {
            return this->color;
        }

        void setColor(VertexColor color)
        {
            this->color = color;
        }

        int getDist() const
        {
            return this->dist;
        }

        void setDist(int dist)
        {
            this->dist = dist;
        }

        Vertex* getParent() const
        {
            return this->parent;
        }

        void setParent(Vertex* parent)
        {
            this->parent = parent;
        }
    };
}
}

#endif // GRAP_VERTEX

