TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    algorithms.h \
    base.h \
    sort.h \
    heap.h \
    binarytree.h \
    quicksort.h \
    binarysearch.h \
    search.h \
    queue.h \
    arraybasedqueue.h \
    heapsort.h \
    exceptions/queueexception.h \
    exceptions/base.h \
    graph/graph.h \
    graph/vertex.h \
    graph/adjancencylistgraph.h

DISTFILES += \
    .gitignore

