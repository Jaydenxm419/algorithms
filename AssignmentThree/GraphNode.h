#include <iostream>
#include <string>
#include <vector>
#ifndef GraphNode_H
#define GraphNode_H

class GraphNode {
    private:
        bool processed;
        std::string identifier;
        std::vector<GraphNode*> neighbors;
    public:
        GraphNode(const std::string& id);
        const std::string& getNodeId();
        void addNeighbor(GraphNode* newNeighbor);
        const std::vector<GraphNode*>& getNeighbors() const; 
        bool getStatus() const;
        void setStatus(bool status);
};

#endif