#include <string>
using namespace std;

class DirectedGraphVertex;
/* This file contains search algorithms for graphs */
class Search {
    public:
        Search();
        DirectedGraphVertex* doVertexSearch(string id, vector<DirectedGraphVertex*> vertices);
};

extern Search doSearch;
