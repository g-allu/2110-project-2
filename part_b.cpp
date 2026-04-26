#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_EDGES 20
#define NODES 10

// struct to hold an edge with its two endpoints and weight
struct Edge
{
    int u, v, weight;
};

// node labels
char nodeName[NODES] = {'A', 'B', 'C', 'D', 'F', 'H', 'I', 'J', 'K', 'L'};

int totalEdges = 15;

// start, end, and weigth
Edge edges[MAX_EDGES] = {

    {0, 2, 3}, // AC
    {3, 4, 2}, // DF
    {1, 5, 2}, // BH
    {8, 6, 4}, // KI
    {9, 7, 5}, // LJ

    {0, 3, 5}, // AD
    {0, 1, 8}, // AB
    {3, 8, 7}, // DK
    {1, 9, 7}, // BL
    {8, 9, 9}, // KL

    {4, 5, 5}, // FH
    {5, 6, 8}, // HI
    {6, 2, 7}, // IC
    {2, 7, 6}, // CJ
    {7, 4, 4}, // JF
};

int parent[NODES];
int rankArr[NODES];

// set each node as its own parent
void initDSU()
{
    for (int i = 0; i < NODES; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

// find the root of x by walking up the tree
int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// join two components together; returns false if they are already connected
bool unite(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
        return false;

    if (rankArr[rootX] < rankArr[rootY])
    {
        int temp = rootX;
        rootX = rootY;
        rootY = temp;
    }
    parent[rootY] = rootX;

    // if both had the same rank, the new root increases by one
    if (rankArr[rootX] == rankArr[rootY])
        rankArr[rootX]++;

    return true;
}

int main()
{
    // sort edges by weight ascending
    sort(edges, edges + totalEdges, [](Edge a, Edge b)
         { return a.weight < b.weight; });

    initDSU();

    Edge mst[NODES - 1]; // stores the edges chosen for the MST
    int count = 0;       // how many edges we have added so far
    int cost = 0;        // total of the MST weight

    for (int i = 0; i < totalEdges; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // only add the edge if it connects two different components
        if (unite(u, v))
        {
            mst[count] = edges[i];
            count++;
            cost += w;
        }

        // needs nodes-1
        if (count == NODES - 1)
            break;
    }

    cout << "MST Edges:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "  " << nodeName[mst[i].u] << " -- "
             << nodeName[mst[i].v] << "  (weight: " << mst[i].weight << ")" << endl;
    }

    cout << "Minimum total railroad length: " << cost << endl;

    return 0;
}