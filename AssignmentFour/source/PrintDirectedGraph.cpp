#include "AssignmentFour/include/PrintDirectedGraph.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"
#include "AssignmentFour/include/ProjectConstants.h"
#include <stack>
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

// Print the shortest paths to each vertex from a start vertex
void PrintDirectedGraph::printBellmanFord(vector<DirectedGraph*> graphs) {
    cout << endl;
    cout << "-----------------------";
    cout << "BELLMAN-FORD ALGORITHM";
    cout << "-----------------------" << endl;
    cout << endl;
    // Iterate through graphs
    for (int i = 0; i < graphs.size(); i++) {
        vector<DirectedGraphVertex*> vertices = graphs[i]->getVertices();
        // Iterate through vertices in the graph
        for (int j = 0; j < vertices.size(); j++) {
            int numOfVertices = 0;
            stack<DirectedGraphVertex*> predecessorStack;
            DirectedGraphVertex* vertex = vertices[j];
            DirectedGraphVertex* destination = vertex;
            // Backtrack to start vertex from each vertex
            while(vertex->getPredecessor() != nullptr) {
                predecessorStack.push(vertex);
                numOfVertices++;
                vertex = vertex->getPredecessor();
            }
            // Consider the start vertex
            predecessorStack.push(vertex);
            // Don't include the path for the start vertex
            if (numOfVertices >= 1) {
                int index = 0;
                // Print the paths
                cout << vertex->getId() << POINTER_INDICATOR << destination->getId();
                cout << " cost is " << to_string(destination->getWeight()) << "; path: ";
                while (!predecessorStack.empty()) {
                    cout << predecessorStack.top()->getId();
                    vertex = predecessorStack.top();
                    predecessorStack.pop();
                    if (index < numOfVertices) {
                        cout << POINTER_INDICATOR;
                    };
                    index++;
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------------------" << endl;
}


PrintDirectedGraph print;