#include<bits/stdc++.h>
using namespace std;
int LCP(string s, int i, int j, vector<vector<int>> &memo){
    if(i==j){
        return memo[i][j] = 1;
    }
    if(s[i]==s[j] and i + 1 == j){
        return memo[i][j] = 2;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if(s[i]==s[j]){ 
        return memo[i][j] = 2 + LCP(s, i+1, j-1, memo);
    }
    return memo[i][j] = max(LCP(s,i+1, j, memo), LCP(s,i,j-1, memo));
}
int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    cout << LCP(s, 0, s.length()-1, memo) << endl;
    return 0;
}