#include "AssignmentFour/include/DirectedGraph.h"
#include <vector>
#include <string>
using namespace std;

class DirectedGraphVertex;
/* This file contains search algorithms for graphs */
class Search {
    public:
        Search();
        DirectedGraphVertex* doVertexSearch(string id, vector<DirectedGraphVertex*> vertices);
        void doPathReset(vector<DirectedGraph*> graphs);
};

extern Search doSearch;
