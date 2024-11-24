#include <string>
#include <vector>
#include "DirectedGraphVertex.h"
using namespace std;

#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

/* This class represents a directed graph */
class DirectedGraph {
    private:
        vector<DirectedGraphVertex*> vertices;
    public:
        DirectedGraph();
        vector<DirectedGraphVertex*> getVertices();
        void addVertex(DirectedGraphVertex* vertex);
};

#endif