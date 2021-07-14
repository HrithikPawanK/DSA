#include<bits/stdc++.h>
using namespace std;
// in the traversal if the adjacent node is already visited then there's a cycle
// note : while considering adjacent nodes don't consider its parent.

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFSRec(vector<vector<int>>& adj, int s, vector<bool>& visited, int parent){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u]==false){
            if(DFSRec(adj, u, visited, s)==true){
                return true;
            }
        }
        else if(u!=parent){
            return true; // cycle detected
        }
    }
    return false;
}
bool DFS(vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            if(DFSRec(adj, i, visited, -1)==true){
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