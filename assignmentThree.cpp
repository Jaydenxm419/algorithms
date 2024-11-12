// main.cpp
#include "AssignmentOne/node.h"
#include "AssignmentOne/stack.h"
#include "AssignmentOne/queue.h"
#include "AssignmentOne/sorting.h"
#include "AssignmentTwo/Search.h"
#include "AssignmentTwo/HashTable.h"
#include "AssignmentThree/BinarySearchTree.h"
#include "AssignmentThree/Graph.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void runBinarySearchTreeTest()
{

    // File of items to be read into array
    ifstream file("magicitems.txt");
    ifstream bstFile("magicitems-find-in-bst.txt");
    // Items in file
    string item;
    // Items array that holds magic items from text file
    string items[666];
    // Check if the input file exists
    if (file)
    {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(file, item))
        {
            items[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();
    }
    // Make nodes
    BinarySearchTree *BST = new BinarySearchTree();
    for (int i = 0; i < 666; i++)
    {
        BSTNode *newNode = new BSTNode(items[i]);
        BST->insertNode(newNode);
    }
    // Do in order traversal
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "IN ORDER TRAVERSAL" << "\n";
    std::cout << "--------------------" << "\n";
    BST->doinOrderTraversal();

    // Read in BST magic items
    item = "";
    string bstItems[42];
    if (bstFile)
    {
        // Iterate each line of the text file into the items array
        int i = 0;
        while (getline(bstFile, item))
        {
            bstItems[i] = item;
            i++;
        }
        // Close the file to prevent errors
        file.close();
    }
    // Retrieve each item from bstItems
    std::cout << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "RETRIEVING 42 ITEMS" << "\n";
    std::cout << "--------------------" << "\n";
    for (int i = 0; i < 42; i++)
    {
        BST->getNode(bstItems[i])->getData();
        std::cout << "\n";
    }
}

void runGraphTest()
{
    Graph *graph = new Graph();
    graph->addVertex("1");
    graph->addVertex("2");
    const std::vector<GraphNode *> vertices = graph->getVertices();
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << "ID Retrieved: " << vertices[i]->getNodeId() << "\n";
    }
    vertices[0]->addNeighbor(vertices[1]);
    const std::vector<GraphNode *> nodeOneNeighbors = vertices[0]->getNeighbors();
    for (int i = 0; i < nodeOneNeighbors.size(); i++)
    {
        std::cout << "Neighbor ID Retrieved: " << nodeOneNeighbors[i]->getNodeId() << "\n";
    }
}

// Parse the components of a command
std::vector<std::string> parseCommand(const std::string &command)
{
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

// Read graph file instructions
void readGraphFile()
{
    // File of commands
    ifstream file("graph.txt");
    // Hold the command at a given line
    std::string command;
    // Define a generic graph
    Graph *graph = nullptr;
    // Define a vector to contain the graphs for output
    std::vector<Graph *> graphs;
    ;
    // Open the file for reading
    if (file)
    {
        int i = 0;
        // Read for commands
        while (getline(file, command))
        {
            // Create a new graph
            if (command == "new graph")
            {
                graph = new Graph();
                graphs.push_back(graph);
            }
            // Add a vertex to the graph
            std::string addVertexStr = "add vertex";
            if (command.find(addVertexStr) != std::string::npos)
            {
                std::vector<std::string> tokens = parseCommand(command);
                graph->addVertex(tokens[2]);
            }
            // Add an edge between two vertices
            std::string addEdgeString = "add edge";
            if (command.find(addEdgeString) != std::string::npos)
            {
                // Get the all of the vertex pointers in the graph
                std::vector<GraphNode *> vertices = graph->getVertices();
                // Get the current subcommands from the current line
                std::vector<std::string> tokens = parseCommand(command);
                // Define the vertices that will be connected
                std::string firstVertexId = tokens[2];
                std::string secondVertexId = tokens[4];
                // Search for the vertex object in vertices vector
                GraphNode *firstVertex = nullptr;
                GraphNode *secondVertex = nullptr;
                // Search for the vertex id's in the vertices vector
                for (int i = 0; i < vertices.size(); i++)
                {
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

        // // Print the Adjacency List
        // for (int i = 0; i < graphs.size(); i++) {
        //     std::vector<GraphNode*> vertices = graphs[i]->getVertices();
        //     std::cout << "--------------------" << "\n";
        //     std::cout << "ADJACENCY LIST" << "\n";
        //     std::cout << "--------------------" << "\n";
        //     for (int j = 0; j < vertices.size(); j++) {
        //         GraphNode* vertex = vertices[j];
        //         std::vector<GraphNode*> neighbors = vertex->getNeighbors();
        //         std::cout << "[" << vertex->getNodeId() << "] ";
        //         for (int k = 0; k < neighbors.size(); k++) {
        //             std::cout << " " << neighbors[k]->getNodeId();
        //         }
        //         std::cout << "\n";
        //     }
        // }

        for (int i = 0; i < graphs.size(); i++) {
            std::vector<GraphNode *> vertices = graphs[i]->getVertices();
            // Initialize the matrix with the correct dimensions and a default value
            std::vector<std::vector<std::string> > matrix(vertices.size(), std::vector<std::string>(vertices.size(), "*"));
            // Populate the matrix
            for (int i = 0; i < vertices.size(); i++) {
                for (int j = 0; j < vertices.size(); j++) {
                    matrix[i][j] = "*"; // Fill each cell as desired
                }
            }

            // Print the matrix contents
            std::cout << "  ";
            bool zeroFlag = false;
            for (int i = 0; i < vertices.size(); i++) {
                std::cout << vertices[i]->getNodeId() << " ";
                if (vertices[i]->getNodeId() == "0") {
                    zeroFlag = true;
                }
            }
            std::cout << "\n";
            for (int i = 0; i < matrix.size(); i++) {
                std::cout << vertices[i]->getNodeId() << " ";
                for (int j = 0; j < matrix[i].size(); j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }

            // Iterate through the vertices
            for (int i = 0; i < vertices.size(); i++) {
                // Get the neighbors of the current vertex
                std::vector<GraphNode*> neighbors = vertices[i]->getNeighbors();
                // Iterate through the neighbors
                if (zeroFlag) {
                    for (int j = 0; j < neighbors.size(); j++) {
                        matrix[std::stoi(vertices[i]->getNodeId())][std::stoi(neighbors[j]->getNodeId())] = "1";
                    }
                } else {
                    for (int j = 0; j < neighbors.size(); j++) {
                        matrix[std::stoi(vertices[i]->getNodeId()) - 1][std::stoi(neighbors[j]->getNodeId()) - 1] = "1";
                }
                }
            }
        
            // Print
            std::cout << "  ";
            for (int i = 0; i < vertices.size(); i++) {
                std::cout << vertices[i]->getNodeId() << " ";
            }
            std::cout << "\n";
            for (int i = 0; i < matrix.size(); i++) {
                std::cout << vertices[i]->getNodeId() << " ";
                for (int j = 0; j < matrix[i].size(); j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }


        }

        // for (int j = 0; j < vertices.size(); j++) {
        //     horizontalAxis.push_back(vertices[i]->getNodeId());

        // }
    }
}


int main()
{

    // Test for binary search tree
    // runBinarySearchTreeTest();
    // runGraphTest();
    readGraphFile();

    return 0;
}

// std::cout << "--------------------" << "\n";
//             std::cout << "MATRIX LIST" << "\n";
//             std::cout << "--------------------" << "\n";
//             for (int j = 0; j < vertices.size(); j++) {
//                 GraphNode* vertex = vertices[j];
//                 std::vector<GraphNode*> neighbors = vertex->getNeighbors();
//                 std::cout << "[" << vertex->getNodeId() << "] ";
//                 for (int k = 0; k < neighbors.size(); k++) {
//                     std::cout << " " << neighbors[k]->getNodeId();
//                 }
//                 std::cout << "\n";