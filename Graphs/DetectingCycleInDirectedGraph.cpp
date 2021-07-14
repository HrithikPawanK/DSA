#include<bits/stdc++.h>
using namespace std;
// using DFS
/*
    for directed graph if the decendants having adjacent nodes as ancestors then there exists cycle.
    it is called as back edge.
    -> it is different from undirected graph's cycle detection.
    we use extra recursion stack array to check whether its decendants have edge to ancestors.
*/

// for directed only one edge is added
void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
}

bool DFSRec(vector<vector<int>>& adj, int s, vector<bool>& visited, vector<bool>& recStack){
    visited[s] = true;
    recStack[s] = true;
    for(int u : adj[s]){
        if(visited[u]==false and DFSRec(adj, u, visited, recStack)) return true;
        else if(recStack[u]==true){ // if its in recursion stack
            return true; // cycle detected
        }
    }
    recStack[s] = false; // getting out of recursion stack.
    return false;
}
bool DFS(vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            if(DFSRec(adj, i, visited, recStack)==true){
                return true; // cycle detected
            }
        }
    }
    return false;
}
int main(){
    int V,E;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    int u,v;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << DFS(adj, V) << endl;
    return 0;
}