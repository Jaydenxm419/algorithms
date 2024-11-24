#include <vector>
using namespace std;

#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

class DirectedGraphVertex;
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