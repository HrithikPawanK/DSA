#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int EditDistance(string& word1, string& word2, int n, int m, vector<vector<int>>&memo){
        if(memo[n][m]!=-1){
            return memo[n][m];
        }
        if(n==0) return memo[n][m] = m;
        if(m==0) return memo[n][m] = n;
        int res;
        if(word1[n-1]==word2[m-1]) return memo[n][m] = EditDistance(word1, word2, n-1, m-1, memo);
        else{
            // inserting at end
            res = 1 + EditDistance(word1, word2, n, m-1, memo);
            // deleting
            res = min(res, 1 + EditDistance(word1, word2, n-1,m, memo));
            // replacing
            res = min(res, 1 + EditDistance(word1, word2, n-1,m-1, memo));
        }
        return memo[n][m] = res;
    }
    int minDistance(string word1, string word2) {
        int n,m;
        n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return EditDistance(word1, word2, n, m, memo);
    }

    // tabulation
    int EditdistanceDp(string word1, string word2) {
        int n,m;
        n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i < n+1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j < m+1; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + dp[i][j-1];
                    dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};