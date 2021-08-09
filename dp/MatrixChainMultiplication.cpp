#include<bits/stdc++.h>
using namespace std;
int matrixChainMultiplication(int arr[], int i, int j){
    if(i + 1 == j) return 0; // only one matrix means no multipliactions needed.
    int res = INT_MAX;
    /*
        M1  M2  M3
       2   1  3   4
     */
    for(int k = i + 1; k < j; k++){
        res = min(res, matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k, j) + arr[i]*arr[k]*arr[j]);
    }
    return res;
}
int matrixChainMDP(int arr[], int n){
    int dp[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i+1] = 0;
    }
    for(int gap = 2; gap < n; gap++){
        for(int i = 0; i + gap < n; i++){
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }   
    cout << matrixChainMultiplication(arr, 0, n-1) << endl;
    return 0;
}