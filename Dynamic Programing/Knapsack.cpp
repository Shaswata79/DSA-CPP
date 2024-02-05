#include "DynamicPrograming.h"
#include <algorithm>
#include <iostream>

/**
 *
 * @param W - the capacity of the knapsack
 * @param value - the values of each item
 * @param weight - the weight of each item
 * @param n - the number of items
 */
int knapsack(int W, int value[], int weight[], int n){
    int table[n][W+1];

    for(int i = 0; i < n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                table[i][w] = 0;
            }else if(weight[i] <= w){
                table[i][w] = std::max(table[i-1][w], value[i] + table[i-1][w-weight[i]]);
            }else{
                table[i][w] = table[i-1][w];
            }
        }
    }
    return table[n-1][W];
}

void runKnapsackProblem(){
    int profits[] = {0, 1, 2, 5, 6};
    int weights[] = {0, 2, 3, 4, 5};
    int capacity = 8;
    int n = sizeof(profits) / sizeof(profits[0]);
    std::cout << knapsack(capacity, profits, weights, n) << std::endl;
}

