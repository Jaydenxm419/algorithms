#include <vector>
#include <string>

using namespace std;
#ifndef DIRECTED_GRAPH_VERTEX_H
#define DIRECTED_GRAPH_VERTEX_H

class DirectedGraphEdge;
/* This class represents a vertex within a graph */
class DirectedGraphVertex {
    private:
        // Neighbors of a vertex 
        vector<DirectedGraphEdge*> neighbors;
        // Previous vertex of a vertex in the shortest path 
        DirectedGraphVertex* predecessor;
        // Unique identifier for the vertex
        string id;
        // Final calculated weight based upon the weights of each edge to a vertex
        int weight;
    public:
        DirectedGraphVertex(const std::string& identifier);
        // Returns neighbors
        vector<DirectedGraphEdge*> getNeighbors();
        // Add a neighbor
        void addNeighbor(DirectedGraphEdge* edge);
        // Returns predecessor
        DirectedGraphVertex* getPredecessor();
        // Set the previous vertex in the shortest path
        void setPredecessor(DirectedGraphVertex* predecessor);
        // Return the weight 
        int getWeight();
        // Update the weight
        void setWeight(int weight);
        // Return the id 
        string getId();
};

#endif