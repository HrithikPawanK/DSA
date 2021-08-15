#include<bits/stdc++.h>
using namespace std;
/*
    we are given an array, for each element at index i, arr[i] represent maximum number of jumps we
    can make from that index.
    we need to go from first cell to last cell.
*/
int minJumps(vector<int> &v, int n){
    if(n==1){
        return 0;
    }
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        if(i+v[i]>=n-1){
            int sub_res = minJumps(v,i+1);
            if(sub_res!=INT_MAX){
                return 1 + min(sub_res,res);
            }
        }
    }
    return res;
}
int minJumpsDp(vector<int> &v, int n){  
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[j]+j >= i){
                if(dp[j]!=INT_MAX){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}
int main(){
    vector<int> v;
    int n,temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    int ans = minJumps(v,n);
    int ans2 = minJumpsDp(v,n);
    cout << ans2 << endl;
    cout << ans << endl;
    return 0;
}