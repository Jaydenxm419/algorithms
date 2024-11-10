#include "Graph.h"
#include "GraphNode.h"

Graph::Graph() : vertices() {}

// Return the vertices of the graph
const std::vector<GraphNode*>& Graph::getVertices() {
    return vertices;
}

// Add a vertex to the graph
void Graph::addVertex(std::string id) {
    GraphNode *node = new GraphNode(id);
    vertices.push_back(node);
    std::cout << "Node Added: " << id << "\n";
}

// Add an edge to a vertex
void Graph::addEdge(GraphNode* firstNode, GraphNode* secondNode) {

}