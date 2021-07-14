#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BFS(vector<vector<int>> &adj, int s, vector<bool>& visited){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

// if we were given disconnected graph and no source is given.
// time complexity --> O(V+E)
// E because for each vetices we traverse its adjacent edges(adjacent vertices) which in turn becomes E. Rememeber its 2E for undirected graph.
// V becaues if every vertex is disconnected then we do bfs for each vertex.

void BFSDis(vector<vector<int>> &adj, int V){
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            BFS(adj, i, visited);
        }
    }
}

// checking no of connected components
// connected components are
/*
         7      8
        / \    / \
       9   3  4   6     connected components = 2;
*/

// it can be used for no of islands problem.
int connectedComponents(vector<vector<int>>& adj, int V){
    int count = 0;
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

//DFS

// time complexity - O(V+E) similar reason as BFS.
void DFSRec(vector<vector<int>>& adj, int s, vector<bool>& visited){
    visited[s] = true;
    cout << s << " ";
    for(int v : adj[s]){
        if(visited[v]==false){
            DFSRec(adj, v, visited);
        }
    }
}
void DFS(vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            DFSRec(adj, i, visited);
        }
    }
}

// shortest distance from source to every other vertices. (unweighted graph)
// in bfs we traverse its adjacent first then its adjacents of adjacents.
// so bfs is used to solve this.
// use distance vector to store the distances.
void shortestpath(vector<vector<int>>& adj, int s, int V){
    vector<bool> visited(V, false);
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(visited[v]==false){
                visited[v] = true;
                dist[v] = dist[u] + 1; // main logic
                q.push(v);
            }
        }
    }
    for(int e : dist){
        cout << e << " ";
    }
    cout << endl;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    int u, v;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << connectedComponents(adj, V) << endl;
    vector<bool> visited(V, false);
    DFS(adj, V);
    cout << endl;
    shortestpath(adj, 0, V);
    return 0;
}