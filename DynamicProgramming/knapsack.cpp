#include<bits/stdc++.h>
using namespace std;
int knapsackRec(int wt[], int val[], int n, int W){
    if(n == 0 or W == 0){
        return 0;
    }
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsackRec(wt, val, n-1, W - wt[n-1]), knapsackRec(wt, val, n-1, W));
    }
    else if(wt[n-1] > W){
        return knapsackRec(wt, val, n-1, W);
    }
}
int memo[102][1002];
int knapsackMemo(int wt[], int val[], int n, int W){
    if(n == 0 or W == 0){
        return 0;
    }
    if(memo[n][W] != -1){
        return memo[n][W];
    }
    if(wt[n-1] <= W){
        return memo[n][W] = max(val[n-1] + knapsackMemo(wt, val, n-1, W - wt[n-1]), knapsackMemo(wt, val, n-1, W));
    }
    else if(wt[n-1] > W){
        return memo[n][W] = knapsackMemo(wt, val, n-1, W);
    }
}   
int knapsackDP(int wt[], int val[], int n, int W){
    int dp[n+1][W+1];
    for(int i = 0; i < n + 1; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j < W + 1; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    memset(memo, -1, sizeof(memo));
    return 0;
}
