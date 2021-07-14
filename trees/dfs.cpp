#include<bits/stdc++.h>
using namespace std;
void dfs(int root, vector<vector<int>> &edges, int parent){
    cout << root + 1 << " ";
    for(auto i : edges[root]){
        if(i!=parent){
            dfs(i,edges,root);
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n,vector<int>());
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }   
    dfs(0,edges,-1);
    cout << endl;
    dfs(2,edges,-1);
    return 0;
}