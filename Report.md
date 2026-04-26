Part A Used Dijkstra's Algorithm

This problem required to find the minimum possible path from one vertex to another. This had to be repeated for every multiple times for every vertex with the start always being A.

This algorithm which is a standard and most efficient method for finding the shortest path from one single vertex to all other verticies in a weighted graph.

By using this algorithm the program ensures that the cost of traveling to any vertex from A is the absolute minimum. This meets the requirements completely for part A.

Part B Used Kruskal’s Algorithm

This problem requried to find the minimum possible path that spans the entire graph connecting each city with the least distance. Which is a minimum spanning tree (MST).

This algorithm works by sorting all available edges by their weight in ascending order and adding them one by one. This edge list is very suitable for the 15 edge list.

This implementation correctly utilizes a disjoint set union which basically prevent any cycles from forming within the tree which breaks the code entirely. This ensures that we always have the shortest path and do not have any redudent loops. This algorithm is a greedy algorithm which is specifically designed to find the MST in a weighted graph.
