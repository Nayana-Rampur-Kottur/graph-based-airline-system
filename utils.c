#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Load graph from a file
void loadGraphFromFile(Graph* g, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening distances file");
        exit(1);
    }

    char src[50], dest[50];
    int distance;

    // Read each line and add the edge to the graph
    while (fscanf(file, "%s %s %d", src, dest, &distance) == 3) {
        addEdge(g, src, dest, distance);
    }

    fclose(file);
}
