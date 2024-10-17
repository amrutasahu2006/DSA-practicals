#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void addEdge(int adjMatrix[MAX][MAX], int u, int v) {
    adjMatrix[u][v] = 1;  
}

void BFS(int adjMatrix[MAX][MAX], int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};  

    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS traversal starting from vertex %d: ", start);

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int adjMatrix[MAX][MAX], int current, int visited[MAX], int vertices) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {
            DFSUtil(adjMatrix, i, visited, vertices);
        }
    }
}

void DFS(int adjMatrix[MAX][MAX], int start, int vertices) {
    int visited[MAX] = {0}; 
    printf("DFS traversal starting from vertex %d: ", start);
    DFSUtil(adjMatrix, start, visited, vertices);
    printf("\n");
}

int main() {
    int vertices = 5;  
    int adjMatrix[MAX][MAX] = {0};  
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 3, 4);
    
    int startVertex = 0;

    BFS(adjMatrix, startVertex, vertices);
    DFS(adjMatrix, startVertex, vertices);
    return 0;
}
