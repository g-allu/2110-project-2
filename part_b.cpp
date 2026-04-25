#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_EDGES 20
#define NODES 10

struct Edge
{
    int u, v, weight;
};

char nodeName[NODES] = {'A', 'B', 'C', 'D', 'F', 'H', 'I', 'J', 'K', 'L'};

int totalEdges = 16;
Edge edges[MAX_EDGES] = {
    {2, 1, 2},
    {3, 4, 2},
    {0, 2, 3},
    {4, 6, 4},
    {6, 7, 4},
    {6, 8, 4},
    {0, 3, 5},
    {2, 5, 5},
    {7, 9, 5},
    {4, 7, 6},
    {2, 4, 7},
    {3, 8, 7},
    {1, 9, 7},
    {0, 1, 8},
    {5, 7, 8},
    {8, 9, 9},
};

int parent[NODES];
int rankArr[NODES];

void initDSU()
{
    for (int i = 0; i < NODES; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y)
{
    int rx = find(x);
    int ry = find(y);

    if (rx == ry)
        return false;

    if (rankArr[rx] < rankArr[ry])
    {
        int temp = rx;
        rx = ry;
        ry = temp;
    }
    parent[ry] = rx;
    if (rankArr[rx] == rankArr[ry])
        rankArr[rx]++;

    return true;
}

int main()
{
    sort(edges, edges + totalEdges, [](Edge a, Edge b)
         { return a.weight < b.weight; });

    initDSU();

    Edge mst[NODES - 1];
    int mstCount = 0;
    int totalCost = 0;

    for (int i = 0; i < totalEdges; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (unite(u, v))
        {
            mst[mstCount] = edges[i];
            mstCount++;
            totalCost += w;
        }

        if (mstCount == NODES - 1)
            break;
    }

    cout << "=======================================================" << endl;
    cout << "  Kruskal's Minimum Spanning Tree" << endl;
    cout << "=======================================================" << endl;
    cout << "  Edge    | Weight | In MST?" << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i < totalEdges; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        bool inMST = false;
        for (int j = 0; j < mstCount; j++)
        {
            if (mst[j].u == u && mst[j].v == v && mst[j].weight == w)
            {
                inMST = true;
                break;
            }
        }

        cout << "  " << nodeName[u] << " - " << nodeName[v]
             << "    |   " << w << "    |  " << (inMST ? "YES" : "no") << endl;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "  MST Edges Selected:" << endl;
    for (int i = 0; i < mstCount; i++)
    {
        cout << "    " << nodeName[mst[i].u] << " -- "
             << nodeName[mst[i].v] << "  (weight: " << mst[i].weight << ")" << endl;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "  Minimum total railroad length: " << totalCost << endl;
    cout << "=======================================================" << endl;

    return 0;
}