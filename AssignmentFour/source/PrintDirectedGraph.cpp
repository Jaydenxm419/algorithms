#include "AssignmentFour/include/PrintDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"

#include <iostream>
#include <vector>
using namespace std;

PrintDirectedGraph::PrintDirectedGraph() {}

void PrintDirectedGraph::printAdjancencyList(vector<DirectedGraph*> graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        for (int j = 0; j < vertices.size(); j++) {
            cout << "[" << vertices[j]->getId() << "]" << " ";
            for (int k = 0; k < vertices[j]->getNeighbors().size(); k++) {

                cout << vertices[j]->getNeighbors()[k]->getVertex()->getId() << " ";
            }
            cout << std::endl;
        }
        cout << std::endl;
    }
}

PrintDirectedGraph print;