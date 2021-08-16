#include<bits/stdc++.h>
using namespace std;
int maxSum(int arr[], int n){
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0], arr[1]);
    return max(maxSum(arr, n - 1), maxSum(arr, n - 2) + arr[n - 1]);
    // consider current element or dont consider.
    // if considered then we can't include next element so n - 2.
    // if not considered we can include n - 1 so n - 1.
}
int maxSumDP(int arr[], int n){
    if(n == 1) return arr[0];
    int dp[n + 1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
}
// space optimization using only two variables
int maxSumDPSpace(int arr[], int n){
    if(n == 1) return arr[0];
    int prev_prev, prev;
    prev_prev = arr[0], prev = max(arr[0], arr[1]);
    int res = prev;
    for(int i = 3; i <= n; i++){
        int res = max(prev_prev + arr[i - 1], prev);
        prev_prev = prev, prev = res;
    }
    return res;
}
int main(){
    
    return 0;
}