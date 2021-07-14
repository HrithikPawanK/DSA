#include<bits/stdc++.h>
using namespace std;
int minCoins(vector<int> &coins, int n, int val){
    if(val==0){
        return 0;
    }
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        if(coins[i]<=val){
            int sub_res = minCoins(coins,n,val-coins[i]);
            if(sub_res!=INT_MAX){
                res = min(res,sub_res+1);
            }
        }
    }
    return res;
}
// time complexity --> theta(val*n) space complexity--> theta(n)
int minCoinsDP(vector<int> &coins, int n, int val){
    vector<int> dp(val+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= val; i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j]>=0){
                int sub_res = dp[i-coins[j]];
                if(sub_res!=INT_MAX){
                    dp[i] = min(dp[i],sub_res+1);
                }
            }
        }
    }
    return dp[val];
}
int main(){
    vector<int> coins;
    int val,n;
    cin >> val >> n;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        coins.push_back(temp);
    }
    int ans = minCoinsDP(coins,n,val);
    cout << ans << endl;
}