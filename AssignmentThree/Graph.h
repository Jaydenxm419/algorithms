#include "GraphNode.h"
#include <vector>
#include <string>
class Graph {
    private:
        std::vector<GraphNode*> vertices;
        // Maybe add an name to the graph?
    public:
    Graph();
    const std::vector<GraphNode*>& getVertices();
    void addVertex(std::string id);
    void addEdge(GraphNode* firstNode, GraphNode* secondNode);
    void breadthFirstTraversal(GraphNode* start);
    void depthFirstTraversal(GraphNode* start);
};