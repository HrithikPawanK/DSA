#include<bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dp){
    if(n <= 1){
        dp[n] = n;
        return dp[n];
    }
    if(dp[n]!=-1) return dp[n];
    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}

int main(){
    vector<int> dp(6, -1);
    cout << fib(5, dp) << endl;
    return 0;
}