#include <iostream>
using namespace std;

// sets constants
const int NODES = 7;
const int INF = 9999999;

// adjacency matrix of the the graph
int graph[NODES][NODES] = {
    {0, 14, 0, 0, 10, 0, 17},
    {14, 0, 9, 10, 3, 0, 0},
    {0, 9, 0, 2, 0, 0, 0},
    {0, 10, 2, 0, 0, 7, 0},
    {10, 3, 0, 0, 0, 4, 6},
    {0, 0, 0, 7, 4, 0, 1},
    {17, 0, 0, 0, 6, 1, 0}};

// node labels
char name[NODES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

// arrays for Dijkstra's algorithm
int dist[NODES];
int last_node[NODES];
bool visited[NODES];

// finds the unvisited node with the smallest distance from the source node
int minimumDistance()
{
    int minVal = INF;
    int minIdx = -1;

    for (int i = 0; i < NODES; i++)
    {
        if (!visited[i] && dist[i] < minVal)
        {
            minVal = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}

// prints the path from the source node to the given node
void printPath(int node)
{
    int path[NODES];
    int size = 0;

    while (node != -1)
    {
        path[size] = node;
        size++;
        node = last_node[node];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        cout << name[path[i]];
        if (i != 0)
            cout << " -> ";
    }
}

// Dijkstra's algorithm to find the shortest path from the source node to all other nodes
void dijkstra(int source)
{
    for (int i = 0; i < NODES; i++)
    {
        dist[i] = INF;
        last_node[i] = -1;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int i = 0; i < NODES; i++)
    {
        int u = minimumDistance();
        if (u == -1)
            break;
        visited[u] = true;

        for (int v = 0; v < NODES; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INF)
            {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    last_node[v] = u;
                }
            }
        }
    }

    cout << "Shortest paths from '" << name[source] << "':" << endl;
    for (int i = 0; i < NODES; i++)
    {
        if (i == source)
            continue;
        cout << "  " << name[source] << " -> " << name[i]
             << "  (cost: " << dist[i] << ")  path: ";
        printPath(i);
        cout << endl;
    }
}

// main functions to run the program
int main()
{
    dijkstra(0);
    return 0;
}