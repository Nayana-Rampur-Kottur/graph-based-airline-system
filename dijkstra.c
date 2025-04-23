#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include "dijkstra.h"

// Function to perform Dijkstra's algorithm
void dijkstra(Graph* g, const char* srcName, const char* destName) {
    int src = getNodeIndex(g, srcName); // Find the source node index
    int dest = getNodeIndex(g, destName); // Find the destination node index

    // Check if either source or destination is invalid
    if (src == -1 || dest == -1) {
        printf("Invalid source or destination.\n");
        return;
    }

    int dist[MAX_NODES];  // Distance array to store shortest distance from source
    bool visited[MAX_NODES] = {false};  // Boolean array to track visited nodes
    int prev[MAX_NODES];  // Array to store the previous node in the shortest path

    // Initialize distance and previous node arrays
    for (int i = 0; i < g->numNodes; i++) {
        dist[i] = INT_MAX; // Set all distances to infinity initially
        prev[i] = -1; // Set previous node to -1 (undefined)
    }

    dist[src] = 0; // Distance from the source to itself is 0

    // Main loop to find the shortest path for all nodes
    for (int i = 0; i < g->numNodes - 1; i++) {
        int min = INT_MAX, u = -1;

        // Find the unvisited node with the smallest distance
        for (int j = 0; j < g->numNodes; j++) {
            if (!visited[j] && dist[j] <= min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // No reachable node found, break out

        visited[u] = true; // Mark the node as visited

        // Update distances for the neighbors of the current node
        for (int v = 0; v < g->numNodes; v++) {
            if (!visited[v] && g->adjacencyMatrix[u][v] != -1 && 
                dist[u] + g->adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjacencyMatrix[u][v];
                prev[v] = u; // Store the current node as the previous node for v
            }
        }
    }

    // If there is no path to the destination
    if (dist[dest] == INT_MAX) {
        printf("No path found from %s to %s.\n", srcName, destName);
        return;
    }

    // Reconstruct the path from source to destination
    int path[MAX_NODES], count = 0, current = dest;
    while (current != -1) {
        path[count++] = current;
        current = prev[current];
    }

    // Print the shortest path
    printf("Shortest path from %s to %s: ", srcName, destName);
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", g->nodes[path[i]].name);
        if (i != 0) printf(" -> ");
    }
    printf("\nTotal distance: %d\n", dist[dest]);
}
