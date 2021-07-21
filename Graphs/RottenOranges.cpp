#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool inside(int x, int y, int n, int m){
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), tot = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) q.push(make_pair(i, j));
            }
        }
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            tot -= s;
            for(int i = 0; i < s; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto d : dir){
                    int nx = x + d.first, ny = y + d.second;
                    if(inside(nx,ny, n, m) and grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            if(!q.empty()) ans++;
        }
        return (tot == 0)? ans: -1;
    }
};