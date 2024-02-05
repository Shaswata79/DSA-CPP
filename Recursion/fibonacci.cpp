
#include <iostream>

int fib(int n){
    int first = 0;
    int second = 1;
    int s;

    if(n <= 1){
        return n;
    }

    for(int i = 2; i <= n; i++){
        s = first + second;
        first = second;
        second = s;
    }
    return s;
}

int recursiveFib(int n){
    if(n <= 1){
        return n;
    }
    return recursiveFib(n-2) + recursiveFib(n-1);
}

int F[100];
int memoizationRecursiveFib(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    } else{
        if(F[n-2] == -1){
            F[n-2] = memoizationRecursiveFib(n-2);
        }
        if(F[n-1] == -1){
            F[n-1] = memoizationRecursiveFib(n-1);
        }
        return F[n-2]+F[n-1];
    }
}


void runFibonacci(){
    std::cout << fib(10) << std::endl;
    std::cout << recursiveFib(10) << std::endl;

    for(int &i : F){
        i = -1;
    }
    std::cout << memoizationRecursiveFib(10) << std::endl;
}