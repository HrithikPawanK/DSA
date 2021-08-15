#include<bits/stdc++.h>
using namespace std;
// time complexity --> theta(n)
int maximumCuts(int n, int a, int b, int c){
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i = 1; i < n+1; i++){
        if(a<=i){
            dp[i] = max(dp[i],dp[i-a]);
        }
        if(b<=i){
            dp[i] = max(dp[i],dp[i-b]);
        }
        if(c<=i){
            dp[i] = max(dp[i],dp[i-c]);
        }
        if(dp[i]!=-1){
            dp[i]++;
        }
    }
    return dp[n];
}
int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = maximumCuts(n,a,b,c);
    cout << ans << endl;
}