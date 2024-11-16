#include "AssignmentThree/BinarySearchTree.h"
#include "AssignmentThree/Graph.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

const int MAGIC_ITEM_COUNT = 666;
const int FIND_MAGIC_ITEM_COUNT = 42;
const std::string MAGIC_ITEMS_FILE = "TextFiles/magicitems.txt";
const std::string FIND_MAGIC_ITEMS_FILE = "TextFiles/magicitems-find-in-bst.txt";
const std::string GRAPH_COMMAND_FILE = "TextFiles/graph.txt";

// Initialize a new binary tree
BinarySearchTree* doTreeInitialization(){
    // File of items to be read into array
    ifstream file(MAGIC_ITEMS_FILE);
    // Items in file
    string item;
    // Items array that holds magic items from text file
    string items[MAGIC_ITEM_COUNT];
    // Check if the input file exists
    if (file) {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(file, item)) {
            items[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();
    }
    // Make nodes
    BinarySearchTree *BST = new BinarySearchTree();
    for (int i = 0; i < MAGIC_ITEM_COUNT; i++) {
        BSTNode *newNode = new BSTNode(items[i]);
        BST->insertNode(newNode);
    }
    return BST;
}

// Do a tree traversal using left, root, right algorithm
void doDepthFirstTreeTraversal(BinarySearchTree* BST) {  
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "IN ORDER TRAVERSAL" << "\n";
    std::cout << "--------------------" << "\n";
    // Begin the traversal
    BST->doinOrderTraversal();
}

// Retrieve a number of items from a tree
void getMagicItems(BinarySearchTree* BST) {
    // File of 42 items 
    ifstream bstFile(FIND_MAGIC_ITEMS_FILE);
    // Hold each line item
    string item;
    // Read in BST magic items
    item = "";
    string bstItems[FIND_MAGIC_ITEM_COUNT];
    if (bstFile) {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(bstFile, item))
        {
            bstItems[i] = item;
            i++;
        }
        // Close the file to prevent errors
        bstFile.close();
    }
    // Retrieve each item from bstItems
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "RETRIEVING  " << FIND_MAGIC_ITEM_COUNT << " ITEMS" << "\n";
    std::cout << "--------------------" << "\n";
    for (int i = 0; i < FIND_MAGIC_ITEM_COUNT; i++) {
        BST->getNode(bstItems[i])->getData();
        std::cout << "\n";
    }
    // Get the number of comparisons from the tree
    float totalComparisons = BST->getTotalComparisons();
    std::cout << "Total Comparisons: " << totalComparisons << std::endl;
    float averageComparisons = totalComparisons / FIND_MAGIC_ITEM_COUNT;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average Comparisons: " << averageComparisons << std::endl;
}

// Parse the components of a command
std::vector<std::string> parseCommand(const std::string &command) {
    std::vector<std::string> tokens;
    std::istringstream stream(command);
    std::string word;
    // Separate the components into a vector
    while (stream >> word)
    {
        tokens.push_back(word);
    }
    // Return the vector of subcommands
    return tokens;
}

// Print a graph as an adjacency list
void printAdjacencyList(std::vector<Graph*> graphs) {
    int graphNum = 1;
    for (int i = 0; i < graphs.size(); i++) {
        std::vector<GraphNode*> vertices = graphs[i]->getVertices();
        std::cout << "--------------------" << "\n";
        std::cout << "ADJACENCY LIST: " << graphNum <<  "\n";
        std::cout << "--------------------" << "\n";
        graphNum = graphNum + 1;
        for (int j = 0; j < vertices.size(); j++) {
            GraphNode* vertex = vertices[j];
            std::vector<GraphNode*> neighbors = vertex->getNeighbors();
            std::cout << "[" << vertex->getNodeId() << "] ";
            for (int k = 0; k < neighbors.size(); k++) {
                std::cout << " " << neighbors[k]->getNodeId();
            }
            std::cout << "\n";
        }
    }
}

// Print a graph as a matrix
void printGraphMatrix(std::vector<Graph*> graphs) {
    // Keep track of the graph that is being printed
    int graphNum = 1;
    // Iterate through the different graphs
    for (int i = 0; i < graphs.size(); i++) {
        // Get the vertices from the current graph
        std::vector<GraphNode *> vertices = graphs[i]->getVertices();
        // Create the matrix 
        std::vector<std::vector<std::string> > matrix(vertices.size(), std::vector<std::string>(vertices.size(), "."));
        // Prepare the matrix
        bool zeroFlag = false; 
        // Iterate through the x axis of the matrix
        for (int i = 0; i < vertices.size(); i++) {
            // Iterate through the y axis of the matrix
            for (int j = 0; j < vertices.size(); j++) {
                matrix[i][j] = "."; 
            }
            // Flag that a graph starts with a vertex of id 0
            if (vertices[i]->getNodeId() == "0") {
                zeroFlag = true;
            }
        }

        // Iterate through the vertices to denote the neighbors of each vertex
        for (int i = 0; i < vertices.size(); i++) {
            // Get the neighbors of the current vertex
            std::vector<GraphNode*> neighbors = vertices[i]->getNeighbors();
            // Check if the zero flag was set 
            if (zeroFlag) {
                // Iterate through the neighbors without shifting the vector indices
                for (int j = 0; j < neighbors.size(); j++) {
                    // Add the edge to the matrix
                    matrix[std::stoi(vertices[i]->getNodeId())][std::stoi(neighbors[j]->getNodeId())] = "1";
                }
            } else {
                // Iterate through the neighbors with a vector index shift
                for (int j = 0; j < neighbors.size(); j++) {
                    // Add the edge to the matrix
                    matrix[std::stoi(vertices[i]->getNodeId()) - 1][std::stoi(neighbors[j]->getNodeId()) - 1] = "1";
            }
            }
        }

        // Print the matrix
        std::cout << "--------------------" << "\n";
        std::cout << "MATRIX NOTATION: " << graphNum << "\n";
        std::cout << "--------------------" << "\n";
        std::cout << "  ";
        graphNum = graphNum + 1;
        std::cout << "\n";
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

void doDepthFirstTraversals(std::vector<Graph*> graphs){
    // Depth First Traversal
        std::cout << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "DEPTH FIRST TRAVERSALS" << std::endl;
        std::cout << "-------------------" << std::endl;
        int graphNum = 1;
        // Iterate through all graph objects
        for (int i = 0; i < graphs.size(); i++) {
            std::cout << "-------------------" << std::endl;
            std::cout << "Vertices in Graph: " << graphNum;
            std::cout << std::endl;
            // Retrieve the vertices in the graph
            std::vector<GraphNode*> vertices = graphs[i]->getVertices();
            // Do a depth first traversal starting at the first vertex
            graphs[i]->depthFirstTraversal(vertices[0]);
            // Iterate through the vertices to find island vertices
            std::cout << "\n" << "Island Vertices: " << "\n";
            for (int j = 0; j < vertices.size(); j++) {
                // If a vertex has no neighbors
                if(vertices[j]->getNeighbors().empty()) {
                    // Traverse starting at the island vertex
                    graphs[i]->depthFirstTraversal(vertices[j]);
                }
            }
            std::cout << "\n";
            graphNum = graphNum + 1;
            // Reset the graph
            for (int j = 0; j < vertices.size(); j++) {
                vertices[j]->setStatus(false);
            }
        }
}


// Breadth first traversal for graphs
void doBreadthFirstTraversal(std::vector<Graph*> graphs) {
    int graphNum = 1;
    std::cout << std::endl;
    std::cout << "----------------------------" << "\n";
    std::cout << "BREADTH FIRST TRAVERSAL: " << "\n";
    std::cout << "----------------------------" << "\n";
    // Iterate through the graphs
    for (int i = 0; i < graphs.size(); i++) {
        std::cout << "Graph: " << graphNum << ": ";
        graphNum = graphNum + 1;
        std::vector<GraphNode*> vertices = graphs[i]->getVertices();
        graphs[i]->breadthFirstTraversal(vertices[0]);
        std::cout << std::endl;
        std::cout << "\n";
    }
}

// Read graph file instructions
std::vector<Graph*> doGraphsInitialization() {
    // File of commands
    ifstream file(GRAPH_COMMAND_FILE);
    // Hold the command at a given line
    std::string command;
    // Define a generic graph
    Graph *graph = nullptr;
    // Define a vector to contain the graphs for output
    std::vector<Graph *> graphs;
    // Open the file for reading
    if (file){
        int i = 0;
        // Read file for commands
        while (getline(file, command)) {
            // Create a new graph
            if (command == "new graph") {
                graph = new Graph();
                graphs.push_back(graph);
            }
            // Add a vertex to the graph
            std::string addVertexStr = "add vertex";
            if (command.find(addVertexStr) != std::string::npos) {
                std::vector<std::string> tokens = parseCommand(command);
                graph->addVertex(tokens[2]);
            }
            // Add an edge between two vertices
            std::string addEdgeString = "add edge";
            if (command.find(addEdgeString) != std::string::npos) {
                // Get the all of the vertex pointers in the graph
                std::vector<GraphNode*> vertices = graph->getVertices();
                // Get the current subcommands from the current line
                std::vector<std::string> tokens = parseCommand(command);
                // Define the vertex id's from the command that will be connected
                std::string firstVertexId = tokens[2];
                std::string secondVertexId = tokens[4];
                // Search for the vertex object in vertices vector
                GraphNode *firstVertex = nullptr;
                GraphNode *secondVertex = nullptr;
                // Search for the vertex id's in the vertices vector
                for (int i = 0; i < vertices.size(); i++) {
                    if (vertices[i]->getNodeId() == firstVertexId) {
                        firstVertex = vertices[i];
                    }
                    else if (vertices[i]->getNodeId() == secondVertexId) {
                        secondVertex = vertices[i];
                    }
                }
                // Add an edge to the pair of vertices
                graph->addEdge(firstVertex, secondVertex);
            }
        }
        file.close();
    }
    return(graphs);
}

int main() {
    // Initialize the binary search tree
    BinarySearchTree* BST = doTreeInitialization();
    // Do a traversal of the tree using the left, root, right algorithm
    doDepthFirstTreeTraversal(BST);
    // Retrieve a number of items from the tree
    getMagicItems(BST);
    // Get all graphs
    std::vector<Graph*> graphs = doGraphsInitialization();
    // Print the graph as an adjacency list
    printAdjacencyList(graphs);
    // Print the matrix as an adjacency list
    printGraphMatrix(graphs);
    // Print vertices in a depth first traversal
    doDepthFirstTraversals(graphs);
    // Print vertices in a breadth first traversal
    doBreadthFirstTraversal(graphs);
    return 0;
}

