#ifndef DIRECTED_GRAPH_EDGE_H
#define DIRECTED_GRAPH_EDGE_H

class DirectedGraphVertex;
class DirectedGraphEdge {
    private:
        // The vertex a predecessor vertex is pointing to 
        DirectedGraphVertex* vertex;
        // The weight of the edge connection
        int edgeWeight;
    public:
        DirectedGraphEdge(DirectedGraphVertex *vertex, const int &edgeWeight);
        // Return the vertex
        DirectedGraphVertex* getVertex();
        // Return the edge weight
        int getWeight();
};

#endif