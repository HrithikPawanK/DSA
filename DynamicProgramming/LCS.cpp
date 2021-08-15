#include<bits/stdc++.h>
using namespace std;
int LCSRECUR(int i, int j, string s1, string s2){
    if(i>=s1.size() or j>=s2.size()){
        return 0;
    }
    if(s1[i]==s2[j]){
        return 1 + LCSRECUR(i+1,j+1,s1,s2);
    }
    else{
        int left = LCSRECUR(i+1,j,s1,s2);
        int right = LCSRECUR(i,j+1,s1,s2);
        return max(left, right);
    }
}
int LCSMEMO(int i, int j, string s1, string s2, vector<vector<int>> &memo){
    if(i >= s1.size() or j >= s2.size()){
        return 0;
    }
    if(memo[i][j]!=-1) return memo[i][j];
    if(s1[i]==s2[j]){
        return memo[i][j] = 1 + LCSMEMO(i+1, j+1, s1, s2, memo);
    }else{
        int left = LCSMEMO(i+1,j,s1,s2,memo);
        int right = LCSMEMO(i,j+1,s1,s2,memo);
        return memo[i][j] = max(left, right);
    }
}
int lcsDP(string s1, string s2, int m, int n){
	int dp[m+1][n+1];
	for(int i = 0; i <= m; i++) dp[i][0] = 0;
	for(int j = 0; j <= n; j++) dp[0][j] = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> memo(s1.size(), vector<int>(s2.size(), -1));
    cout << LCSMEMO(0,0,s1,s2,memo) << endl;
    return 0;
}