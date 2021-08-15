#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string& s, int i, int j){
    while(i < j){
        if(s[i]!=s[j]) return false;
        i++, j--;
    }
    return true;
}
int palindromePartRec(string& s, int i, int j){
    if(ispalindrome(s, i, j)) return 0;
    int res = INT_MAX;
    for(int k = i; k < j; k++){
        res = min(res, 1 + palindromePartRec(s, i, k) + palindromePartRec(s, k+1, j));
    }
    return res;
}
int palindromeDP(string& s, int n){
    int dp[n][n];
    bool ispal[n][n];
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        ispal[i][i] = true;
    }
    for(int gap = 1; gap < n; gap++){
        for(int i = 0; i + gap < n; gap++){
            int j = i + gap;
            if(s[i]==s[j] && (ispalindrome(s, i + 1, j - 1) || gap==1)){ // just extra optimization
                ispal[i][j] = true;
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                ispal[i][j] = false;
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    string s; cin >> s;
    int n = s.length();
    return 0;
}