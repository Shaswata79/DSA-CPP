#include "Graphs.h"
#include <queue>
#include <iostream>
#include <stack>

void runGraphExample(){

    // a graph with 6 vertices
    int graph[6][6]={{0,1,1,0,0,0},
                 {1,0,0,1,0,0},
                 {1,0,0,1,0,0},
                 {0,1,1,0,1,1},
                 {0,0,0,1,0,0},
                 {0,0,0,1,0,0}};

    std::cout << "BFS" << std::endl;
    bfs(graph, 0, 6);

    std::cout << "DFS" << std::endl;
    dfs(graph, 0, 6);
}

void bfs(int g[][6], int start, int n){
    int j = 0;
    int visited[6] = {0};
    std::queue<int> bfs_queue;

    bfs_queue.push(start);
    while (!bfs_queue.empty()){
        int i = bfs_queue.front();
        bfs_queue.pop();

        if(visited[i] == 0){
            visited[i] = 1;
            std::cout << i << " ";
        }

        for(j = 0; j < n; j++){
            if(g[i][j] == 1 && visited[j] == 0){
                bfs_queue.push(j);
            }
        }
    }

    std::cout << std::endl;
}

void dfs(int g[][6], int start, int n){
    int j = 0;
    int visited[6] = {0};
    std::stack<int> dfs_stack;

    dfs_stack.push(start);
    while (!dfs_stack.empty()){
        int i = dfs_stack.top();
        dfs_stack.pop();

        if(visited[i] == 0){
            visited[i] = 1;
            std::cout << i << " ";
        }

        for(j = 0; j < n; j++){
            if(g[i][j] == 1 && visited[j] == 0){
                dfs_stack.push(j);
            }
        }
    }
    std::cout << std::endl;
}
