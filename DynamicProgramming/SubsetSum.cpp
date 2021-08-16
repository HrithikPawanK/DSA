#include<bits/stdc++.h>
using namespace std;
// count of subsets with given sum
// ** first generate all subset then only check for summ == 0.
int subsetSum(int arr[], int n, int sum){
    if(n == 0){
        return (sum == 0)? 1 : 0;
    }
    return subsetSum(arr, n - 1, sum) + subsetSum(arr, n - 1, sum - arr[n - 1]);
}
int subsetSumDP(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    // note dp[0][0] = 1;
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j <= sum; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < arr[i-1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    
    return 0;
}