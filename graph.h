#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 100         // Maximum number of nodes in the graph
#define MAX_NAME_LENGTH 50    // Maximum length for node names

// Structure to represent a node (location in the graph)
typedef struct {
    char name[MAX_NAME_LENGTH]; // Name of the node (e.g., city name)
} Node;

// Structure to represent the graph (adjacency matrix representation)
typedef struct {
    int numNodes;                         // Number of nodes in the graph
    int adjacencyMatrix[MAX_NODES][MAX_NODES]; // Adjacency matrix to store edge weights
    Node nodes[MAX_NODES];                // Array of nodes
} Graph;

// Function declarations
void initGraph(Graph* g);               // Initialize the graph
int getNodeIndex(Graph* g, const char* name); // Get index of a node by its name
void addNode(Graph* g, const char* name);   // Add a node to the graph
void addEdge(Graph* g, const char* src, const char* dest, int weight); // Add an edge between nodes
void printGraph(Graph* g);               // Print the graph (for debugging)

#endif
