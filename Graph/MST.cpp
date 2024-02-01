#include <iostream>
#include "Graphs.h"

#define I 32767


void printMSTPrim(int T[][V-1], int G[V][V]){
    std::cout << "Prim's Algorithm Minimum Spanning Tree Edges" << std::endl;
    for (int i = 0; i<V-1; i++){
        int c = G[T[0][i]][T[1][i]];
        std::cout << "[" << T[0][i]+1 << "]---[" << T[1][i]+1 << "] cost: " << c << std::endl;
    }
}


// Disjoint Set operations: Union and Find

// merge set with root elements u and v
void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}

// find root element
int Find(int u, int s[]){
    int x = u;

    while (s[x] > 0){
        x = s[x];
    }
    return x;
}




void PrimsMST(int G[V][V], int n){
    int u;
    int v;
    int min = I;
    int near[V];                // Stores the current nearest vertex for each vertex. -1 if we found the min cost edge
    int mst[2][V-1] = {0};      // The minimum spanning tree containing the min cost edges

    // Find the smallest cost edge in whole graph
    for(int i = 0; i < V; i++){
        near[i] = I;    // Initialize near array with INFINITY
        for(int j = i; j < V; j++){
            if(G[i][j] < min){
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    mst[0][0] = u;
    mst[1][0] = v;
    near[u] = near[v] = -1;

    // Initialize near array to track min cost edges
    for(int i = 0; i < V; i++){
        if(near[i] != -1){
            if(G[i][u] < G[i][v]){
                near[i] = u;
            } else{
                near[i] = v;
            }
        }
    }

    // Repeat for each vertex until we have a complete MST
    for(int i = 1; i < n; i++){
        int k;
        min = I;
        // Find next min edge to be added to MST
        for(int j = 0; j < V; j++){
            if(near[j] != -1 && G[j][near[j]] < min){    // If cost of (j, near[j]) is min edge, add it to MST
                k = j;
                min = G[j][near[j]];
            }
        }
        // Add new min edge to MST
        mst[0][i] = k;
        mst[1][i] = near[k];
        near[k] = -1;

        // Update near array (check if newly added vertex k is nearer to any of the other vertices)
        for (int j = 0; j < V; j++){
            if(near[j] != -1 && G[j][k] < G[j][near[j]]){
                near[j] = k;
            }
        }
    }
    printMSTPrim(mst, G);
}


void printMSTKruskal(int T[][V-1]){
    std::cout << "\nKruskal's Algorithm Minimum Spanning Tree\n" << std::endl;
    for (int i {0}; i<V-1; i++){
        std::cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << std::endl;
    }
    std::cout << std::endl;
}


void KruskalMST(int edges[3][E]){
    int mst[2][V-1];  // Solution array
    int included[E] {0};  // Track edges that are included in solution
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1};  // Array for finding cycle

    int i = 0;
    while(i < V-1){
        int min = I;    // min cost
        int u = 0;      // vertex 1
        int v = 0;      // vertex 2
        int k = 0;

        // find minimum cost edge
        for(int j = 0; j < E; j++){
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }

        // Check if the selected min cost edge (u, v) forms a cycle or not
        if(Find(u, set) != Find(v, set)){   // if no cycle, add it to MST
            mst[0][i] = u;
            mst[1][i] = v;

            // Perform union
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        included[k] = 1;
    }
    printMSTKruskal(mst);
}




void runPrimsMSTExample(){
    int cost [V][V] {
            { I, 25, I, I, I, 5, I},
            { 25, I, 12, I, I, I, 10},
            { I, 12, I, 8, I, I, I},
            { I, I, 8, I, 16, I, 14},
            {I, I, I, 16, I, 20, 18},
            {5, I, I, I, 20, I, I},
            {I, 10, I, 14, 18, I, I},
    };
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    PrimsMST(cost, n);
}


void runKruskalMSTExample(){

    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    KruskalMST(edges);
}