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

// Print the edges between vertices in directed graphs
void PrintDirectedGraph::printGraphEdges(vector<DirectedGraph*> graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        for (int j = 0; j < vertices.size(); j++) {
            // Get neighbors of the vertex
            vector<DirectedGraphEdge*> neighbors = vertices[j]->getNeighbors();
            for (int k = 0; k < neighbors.size(); k++) {    
                cout << "("<< vertices[j]->getId() << ", " << neighbors[k]->getVertex()->getId() << " : " << "w = " << to_string(neighbors[k]->getWeight()) << ")";
                cout << std::endl;
            }
        }
        cout << std::endl;
    }
}

void PrintDirectedGraph::printVertexWeights(vector<DirectedGraph*> graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        for (int j = 0; j < vertices.size(); j++) {
            // Get neighbors of the vertex
            vector<DirectedGraphEdge*> neighbors = vertices[j]->getNeighbors();
            // Vertex
            cout << "v: " << vertices[j]->getId() << ": w :"<< to_string(vertices[j]->getWeight()) << endl;
        }
        cout << std::endl;
    }
}
// Find the shortest path to each vertex 
void PrintDirectedGraph::doBellmanFord(vector<DirectedGraph*> graphs) {

}

PrintDirectedGraph print;