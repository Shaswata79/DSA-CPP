#ifndef DSA_GRAPHS_H
#define DSA_GRAPHS_H

#define V 7
#define E 9


void runGraphExample();
void bfs(int g[][6], int start, int n);
void dfs(int g[][6], int start, int n);

// Prim's Algorithm: Select the next min cost edge which is connected to an existing vertex in MST
void PrimsMST(int G[V][V], int n);

// Kruskal's Algorithm: Select the edge with the min cost and add to MST. If the edge forms a cycle, select the next edge with the min cost.
void KruskalMST(int edges[3][E]);

void runPrimsMSTExample();
void runKruskalMSTExample();

#endif //DSA_GRAPHS_H
