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
void Search::doShortestPath(vector<DirectedGraph*> graphs) {
    doPathReset(graphs);
    vector<DirectedGraphEdge*> savedEdges;
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        // Iterate through all vectors
        for (int j = 0; j < vertices.size(); j++) {
            // Iterate through each vectors directed edges 
            vector<DirectedGraphEdge*> edges = vertices[j]->getNeighbors();
            for (int k = 0; k < edges.size(); k++) {
                // If the "to vertex" cost > "from vertex" cost + edge cost 
                savedEdges.push_back(edges[k]);
                long toWeight = edges[k]->getVertex()->getWeight();
                long fromWeight = (vertices[j]->getWeight() + edges[k]->getWeight());
                if (toWeight > fromWeight) {
                    edges[k]->getVertex()->setWeight(fromWeight);
                    edges[k]->getVertex()->setPredecessor(vertices[j]);
                }
            }
        }
        // for (int j = 0; j < savedEdges.size(); j++) {
        //     if (savedEdges[j]->getVertex()->getWeight() > savedEdges[j]->getVertex()->getPredecessor()->getWeight() && savedEdges[j]->getVertex()->getWeight() != 0) {
        //         cout << "False" << endl;
        //     }
        // }
    }

    print.printVertexWeights(graphs);
    // cout << "True" << endl;
}
 
Search doSearch;