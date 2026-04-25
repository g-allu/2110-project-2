#include <iostream>
using namespace std;

#define NODES 7
#define INF 99999

int graph[NODES][NODES] = {
    {0, 14, 0, 0, 10, 0, 17},
    {14, 0, 9, 10, 3, 0, 0},
    {0, 9, 0, 2, 0, 0, 0},
    {0, 10, 2, 0, 0, 7, 0},
    {10, 3, 0, 0, 0, 4, 6},
    {0, 0, 0, 7, 4, 0, 1},
    {17, 0, 0, 0, 6, 1, 0}};

char nodeName[NODES] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

int dist[NODES];
int prev_node[NODES];
bool visited[NODES];

int minDistance()
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

void printPath(int node)
{
    if (prev_node[node] == -1)
    {
        cout << nodeName[node];
        return;
    }
    printPath(prev_node[node]);
    cout << " -> " << nodeName[node];
}

void dijkstra(int source)
{
    for (int i = 0; i < NODES; i++)
    {
        dist[i] = INF;
        prev_node[i] = -1;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < NODES; count++)
    {
        int u = minDistance();
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
                    prev_node[v] = u;
                }
            }
        }
    }

    cout << "=======================================================" << endl;
    cout << "  Dijkstra's Shortest Path from '" << nodeName[source] << "'" << endl;
    cout << "=======================================================" << endl;
    cout << "  Dest  | Min Cost | Path" << endl;
    cout << "-------------------------------------------------------" << endl;

    int totalCost = 0;
    for (int i = 0; i < NODES; i++)
    {
        if (i == source)
            continue;
        cout << "   " << nodeName[i] << "    |    " << dist[i] << "     | ";
        printPath(i);
        cout << endl;
        totalCost += dist[i];
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "  Total cost from '" << nodeName[source] << "' to all nodes: " << totalCost << endl;
    cout << "=======================================================" << endl;
}

int main()
{
    dijkstra(0);
    return 0;
}