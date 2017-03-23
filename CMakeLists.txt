cmake_minimum_required(VERSION 3.6)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        exceptions/base.h
        exceptions/QueueException.h
        graph/AdjancencyListGraph.h
        graph/Graph.h
        graph/Vertex.h
        algorithms.h
        arraybasedqueue.h
        base.h
        binarysearch.h
        binarytree.h
        heap.h
        heapsort.h
        main.cpp
        queue.h
        quicksort.h
        search.h
        sort.h exceptions/GraphException.h)

add_executable(algorithms ${SOURCE_FILES})