#include <string>
using namespace std;

class DirectedGraphVertex;

class Search {
    public:
        Search();
        DirectedGraphVertex* doVertexSearch(string id, vector<DirectedGraphVertex*> vertices);
};

extern Search doSearch;
