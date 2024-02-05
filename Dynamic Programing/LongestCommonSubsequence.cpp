#include <string>
#include <iostream>
#include "DynamicPrograming.h"

using namespace std;

int recursiveLCS(string A, string B, int i, int j){
    if(A[i] == '\0' || B[j] == '\0'){
        return 0;
    } else if(A[i] == B[j]){
        return 1 + recursiveLCS(A, B, i+1, j+1);
    } else{
        return std::max(recursiveLCS(A, B, i+1, j), recursiveLCS(A, B, i, j+1));
    }
}

// also recursive, but uses memoization for optimization
int memoizationLCS(string A, string B, int i, int j, int** memory){
    if(A[i] == '\0' || B[j] == '\0'){
        return 0;

    } else if(A[i] == B[j]){
        if(memory[i+1][j+1] == -1){
            return 1 + memoizationLCS(A, B, i+1, j+1, memory);
        }else{
            return 1 + memory[i+1][j+1];
        }

    } else{
        int a, b;
        if(memory[i+1][j] == -1){
            a = memoizationLCS(A, B, i+1, j, memory);
        }else{
            a = memory[i+1][j];
        }

        if(memory[i][j+1] == -1){
            b = memoizationLCS(A, B, i, j+1, memory);
        }else{
            b = memory[i][j+1];
        }
        return std::max(a, b);
    }
}

int dynamicProgrammingLCS(string A, string B){
    int table[A.length()+1][B.length()+1];

    for(int i = 0; i <= A.length(); i++){
        for(int j = 0; j <= B.length(); j++){

            // table start from 0 but indexes for characters must start from 1
            int a = i-1;
            int b = j-1;

            if(i == 0 || j == 0){
                table[i][j] = 0;
            }else if(A[a] == B[b]){
                table[i][j] = 1 + table[i-1][j-1];
            }else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }

        }
    }
    return table[A.length()][B.length()];
}


void runLCS(){
    string A = "stone";
    string B = "longest";
    
    // Recursive LCS
    cout << recursiveLCS(A, B, 0, 0) << endl;

    // Recursive LCS with memoization
    int** memory;
    memory = new int *[A.length()+1];
    for (int i = 0; i <= A.length(); i++) {
        memory[i] = new int[B.length()+1];
        for (int j = 0; j <= B.length(); j++) {
            memory[i][j] = -1;
        }
    }
    cout << memoizationLCS(A, B, 0, 0, memory) << endl;

    // LCS using dynamic programming
    cout << dynamicProgrammingLCS(A, B) << endl;
}