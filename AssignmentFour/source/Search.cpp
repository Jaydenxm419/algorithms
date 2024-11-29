#include "AssignmentFour/include/Search.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"
#include "AssignmentFour/include/BuildDirectedGraph.h"
#include "AssignmentFour/include/ProjectConstants.h"
#include "AssignmentFour/include/PrintDirectedGraph.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Search::Search() {}

// Search for a vertex based on the id in a vector of vertices
DirectedGraphVertex* Search::doVertexSearch(string id, vector<DirectedGraphVertex*> vertices) {
    DirectedGraphVertex* vertex;
    for (int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->getId() == id) {
            vertex = vertices[i];
        }
    }
    return vertex;
}

// Reset the weights of the vertices in all graphs for the bellman-algorithm
void Search::doPathReset(vector<DirectedGraph*> graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        for (int j = 0; j < vertices.size(); j++) {
            if (vertices[j]->getId() == "1") {
                vertices[j]->setWeight(START_VERTEX_WEIGHT);
                // cout << vertices[j]->getId() << " " << vertices[j]->getWeight() << endl;
            } else {
                vertices[j]->setWeight(ABSURDLY_LARGE_VALUE);
                // cout << vertices[j]->getId() << " " << vertices[j]->getWeight();
            }
        }
     }
}

// Do a Bellman-Ford algorithm to find all of the shortest paths in a directed graph
bool Search::findShortestPath(vector<DirectedGraph*> graphs) {
    // Set the initial weights to all vertices in all graphs
    doPathReset(graphs);
    // Iterate through the graphs
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        // Iterate to cover maximum path lengths
        for (int l = 0; l < vertices.size() - 1; l++) {
            // Iterate vertices to discover updated shortest paths
            for (int j = 0; j < vertices.size(); j++) {
                DirectedGraphVertex* vertex = vertices[j];
                vector<DirectedGraphEdge*> edges = vertex->getNeighbors();
                // Iterate through the current vertex neighbors
                for (int k = 0; k < edges.size(); k++) {
                    long currentVertexWeight = edges[k]->getVertex()->getWeight();
                    long outgoingVertexWeight = vertex->getWeight() + edges[k]->getWeight();
                    // There is a new shortest path to the outgoing vertex
                    if (currentVertexWeight > outgoingVertexWeight) {
                        edges[k]->getVertex()->setWeight(outgoingVertexWeight);
                        edges[k]->getVertex()->setPredecessor(vertex);
                    }
                }
            }
        }

        for (int j = 0; j < vertices.size(); j++) {
            DirectedGraphVertex* vertex = vertices[j];
            vector<DirectedGraphEdge*> edges = vertices[j]->getNeighbors();
            for (int k = 0; k < edges.size(); k++) {
                DirectedGraphEdge* edge = edges[k];
                if (edge->getVertex()->getWeight() > vertex->getWeight() + edge->getWeight()) {
                    return false;
                }
            }
        }

    }
    print.printBellmanFord(graphs);
    return true;
}
 
Search doSearch;