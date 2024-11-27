#include "AssignmentFour/include/Search.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/BuildDirectedGraph.h"
#include "AssignmentFour/include/ProjectConstants.h"
#include <vector>
#include <string>
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
            if (vertices[i]->getId() == "1") {
                vertices[i]->setWeight(START_VERTEX_WEIGHT);
            } else {
                vertices[i]->setWeight(ABSURDLY_LARGE_VALUE);
            }

        }
     }
}

Search doSearch;