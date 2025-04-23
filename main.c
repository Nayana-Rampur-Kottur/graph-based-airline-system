#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "utils.h"
#include "dijkstra.h"

int main() {
    Graph g;
    initGraph(&g); // Initialize an empty graph

    // Load graph data from the file "distances.txt"
    loadGraphFromFile(&g, "distances.txt");

    // Ask user for source and destination
    char src[50], dest[50];
    printf("Enter source: ");
    scanf("%s", src);
    printf("Enter destination: ");
    scanf("%s", dest);

    // Compute and print the shortest path using Dijkstra's algorithm
    dijkstra(&g, src, dest);

    return 0;
}
