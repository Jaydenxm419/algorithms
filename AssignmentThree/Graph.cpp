#include "Graph.h"
#include "GraphNode.h"
#include <queue>

Graph::Graph() : vertices() {}

// Return the vertices of the graph
const std::vector<GraphNode*>& Graph::getVertices() {
    return vertices;
}

// Add a vertex to the graph
void Graph::addVertex(std::string id) {
    GraphNode *node = new GraphNode(id);
    vertices.push_back(node);
}

// Add an edge to a vertex
void Graph::addEdge(GraphNode* firstNode, GraphNode* secondNode) {
    firstNode->addNeighbor(secondNode);
    secondNode->addNeighbor(firstNode);
}

// Do breadth first traversal for a graph
void Graph::breadthFirstTraversal(GraphNode* start) {
    // Define a queue
    std::queue<GraphNode*> queue;
    // Enqueue the first vertex
    queue.push(start);
    // Indicate that the vertex has been processed
    start->setStatus(true);
    // Iterate through the queue
    while(!queue.empty()) {
        // Get the next vertex pointer from the queue
        GraphNode* currentVertex = queue.front();
        queue.pop();
        std::cout << currentVertex->getNodeId() << " ";
        // Iterate through the neighbors of the vertex
        for (int i = 0; i < currentVertex->getNeighbors().size(); i++) {
            // Process unprocessed neighbors 
            if (!currentVertex->getNeighbors()[i]->getStatus()) {
                // Enqueue the neighbors
                queue.push(currentVertex->getNeighbors()[i]);
                currentVertex->getNeighbors()[i]->setStatus(true);
            }
        }

    }
}

// Do depth first traveral for a graph
void Graph::depthFirstTraversal(GraphNode* start) {
    // Process node if not processed
    if(!start->getStatus()) {
        std::cout << start->getNodeId() << " ";
        start->setStatus(true);
    }
    // Check status of neighbors
    std::vector<GraphNode*> neighbors = start->getNeighbors();
    int numOfNeighbors = neighbors.size();
    // Iterate through the neighbors of the current vertex
    for (int i = 0; i < numOfNeighbors; i++) {
        // Recurse if a neighbor is not processed
        if (!neighbors[i]->getStatus()) {
            depthFirstTraversal(neighbors[i]);
        }
    }
}