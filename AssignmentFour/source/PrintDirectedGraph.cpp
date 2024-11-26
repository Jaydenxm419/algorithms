#include "AssignmentFour/include/PrintDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

PrintDirectedGraph::PrintDirectedGraph() {}

// Print graphs as adjacency list
void PrintDirectedGraph::printAdjancencyList(vector<DirectedGraph*> graphs) {
    // Each graph
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        // Each vertex
        for (int j = 0; j < vertices.size(); j++) {
            // Get neighbors of the vertex
            vector<DirectedGraphEdge*> neighbors = vertices[j]->getNeighbors();
            // Get the Id 
            string vertexId = vertices[j]->getId();
            cout << "[" << vertexId << "]" << " ";
            // Each neighbor
            for (int k = 0; k < neighbors.size(); k++) {

                cout << vertices[j]->getNeighbors()[k]->getVertex()->getId() << " ";
            }
            cout << std::endl;
        }
        cout << std::endl;
    }
}

PrintDirectedGraph print;