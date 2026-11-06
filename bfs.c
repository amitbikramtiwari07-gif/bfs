#include <stdio.h>

void bfs(int adj[10][10], int v, int start)
{
    int visited[10] = {0};
    int queue[10];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int neighbor = 0; neighbor < v; neighbor++)
        {
            if (adj[node][neighbor] == 1 && visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
}

int main()
{
    int v, adj[10][10], start;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(adj, v, start);

    return 0;
}