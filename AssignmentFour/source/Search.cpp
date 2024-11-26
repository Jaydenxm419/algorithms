#include "AssignmentFour/include/Search.h"
#include "AssignmentFour/include/DirectedGraphVertex.h"
#include <string>
using namespace std;

Search::Search() {}

DirectedGraphVertex* Search::doVertexSearch(string id, vector<DirectedGraphVertex*> vertices) {
    DirectedGraphVertex* vertex;
    for (int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->getId() == id) {
            vertex = vertices[i];
        }
    }
    return vertex;
}

Search doSearch;