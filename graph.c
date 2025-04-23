#include <stdio.h>
#include <string.h>
#include "graph.h"

// Initialize the graph (set number of nodes to 0 and set all edges to -1)
void initGraph(Graph* g) {
    g->numNodes = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            g->adjacencyMatrix[i][j] = -1; // -1 means no edge between nodes
        }
    }
}

// Get the index of a node by name, return -1 if node is not found
int getNodeIndex(Graph* g, const char* name) {
    for (int i = 0; i < g->numNodes; i++) {
        if (strcmp(g->nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Node not found
}

// Add a new node to the graph, only if it does not already exist
void addNode(Graph* g, const char* name) {
    if (getNodeIndex(g, name) == -1 && g->numNodes < MAX_NODES) {
        strcpy(g->nodes[g->numNodes].name, name);
        g->numNodes++;
    }
}

// Add an undirected edge with a weight between two nodes
void addEdge(Graph* g, const char* src, const char* dest, int weight) {
    addNode(g, src);
    addNode(g, dest);

    int i = getNodeIndex(g, src);
    int j = getNodeIndex(g, dest);

    g->adjacencyMatrix[i][j] = weight;
    g->adjacencyMatrix[j][i] = weight; // Assuming undirected graph (i.e., bidirectional)
}

// Print the graph (node and its neighbors with weights)
void printGraph(Graph* g) {
    for (int i = 0; i < g->numNodes; i++) {
        printf("%s: ", g->nodes[i].name);
        for (int j = 0; j < g->numNodes; j++) {
            if (g->adjacencyMatrix[i][j] != -1) {
                printf("-> %s(%d) ", g->nodes[j].name, g->adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}
