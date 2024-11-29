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
void Search::doWeightReset(vector<DirectedGraph*> graphs) {
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        for (int j = 0; j < vertices.size(); j++) {
            // Initialize the weights of the vertices
            if (vertices[j]->getId() == BF_START_VERTEX) {
                vertices[j]->setWeight(START_VERTEX_WEIGHT);
            } else {
                vertices[j]->setWeight(ABSURDLY_LARGE_VALUE);
            }
        }
     }
}

// Do a Bellman-Ford algorithm to find all of the shortest paths in a directed graph
bool Search::findShortestPath(vector<DirectedGraph*> graphs) {
    bool isUsable = true;
    // Set the initial weights to all vertices in all graphs
    doWeightReset(graphs);
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
                    DirectedGraphEdge* edge = edges[k]; 
                    relaxEdge(vertex, edge);
                }
            }
        }
        // Ensure there are negative loops between vertices
        for (int j = 0; j < vertices.size(); j++) {
            DirectedGraphVertex* vertex = vertices[j];
            vector<DirectedGraphEdge*> edges = vertices[j]->getNeighbors();
            for (int k = 0; k < edges.size(); k++) {
                DirectedGraphEdge* edge = edges[k];
                long currentVertexWeight = edge->getVertex()->getWeight();
                long outgoingVertexWeight = vertex->getWeight() + edge->getWeight();
                // There are remaining edges that will 'never' have a shortest path
                if ((currentVertexWeight) > outgoingVertexWeight) {
                    isUsable = false;
                }
            }
        }

    }
    print.printBellmanFord(graphs);
    return isUsable;
}

// Relax a vertex weight
void Search::relaxEdge(DirectedGraphVertex* vertex, DirectedGraphEdge* edge) {
    long currentVertexWeight = edge->getVertex()->getWeight();
    long outgoingVertexWeight = vertex->getWeight() + edge->getWeight();
    // There is a new shortest path to the outgoing vertex
    if (currentVertexWeight > outgoingVertexWeight) {
        edge->getVertex()->setWeight(outgoingVertexWeight);
        edge->getVertex()->setPredecessor(vertex);
    }
}
 
Search doSearch;