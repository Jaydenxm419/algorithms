#include "AssignmentFour/include/DirectedGraph.h"
#include "AssignmentFour/include/DirectedGraphEdge.h"
#include <vector>
#include <string>
using namespace std;

class DirectedGraphVertex;
/* This file contains search algorithms for graphs */
class Search {
    private:
        void relaxEdge(DirectedGraphVertex* vertex, DirectedGraphEdge* edge);
    public:
        Search();
        DirectedGraphVertex* doVertexSearch(string id, vector<DirectedGraphVertex*> vertices);
        void doWeightReset(vector<DirectedGraph*> graphs);
        bool findShortestPath(vector<DirectedGraph*> graphs);
};

extern Search doSearch;
