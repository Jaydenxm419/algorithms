#include <iostream>
#include <string>
#ifndef GraphNode_H
#define GraphNode_H

class GraphNode {
    private:
        std::string identifier;
    public:
        GraphNode(const std::string& id);
        const std::string& getNodeId();
};

#endif