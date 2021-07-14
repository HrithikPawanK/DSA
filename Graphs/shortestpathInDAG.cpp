#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &adj, int u, int v, vector<int> &indegree){
    adj[u].push_back(v);
    indegree[v]++; // increasing indegree because it's u --> v
}
void addWeight(vector<vector<int>>& weights, int u, int v, int w){
    weights[u][v] = w;
}
// ** we can use topological sorting for shortest distances in DAG.
// because there won't be any back edge to destroy the distance calculation.

// topological sort
vector<int> topologicalSort(vector<vector<int>>& adj, vector<int>& indegree, int V){
    vector<int> topo;
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return topo;
}
// time complexity --> O(V+E) :)
void shorestPath(vector<vector<int>>& adj, vector<int>& indegree, int V, int s, vector<vector<int>>& weights){
    vector<int> topo = topologicalSort(adj, indegree, V);
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    for(int i = 0; i < V; i++){
        int u = topo[i];
        if(dist[u]!=INT_MAX){ // this is needed.
            for(int v : adj[u]){
                if(dist[v] > dist[u] + weights[u][v]){ // then update the dist[v]
                    dist[v] = dist[u] + weights[u][v];
                }
            }
        }
    }
    for(int i = 0; i < V; i++){
        (dist[i]==INT_MAX)? cout << "INF" << " " : cout << dist[i] << " ";
    }
    cout << endl;
}
int main(){
    int V,E;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    vector<int> indegree(V, 0);
    vector<vector<int>> weights(V, vector<int>(V, 0));
    int u,v,w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        addEdge(adj, u, v, indegree); 
        addWeight(weights, u, v, w);
    }
    shorestPath(adj, indegree, V, 1, weights);
    return 0;
}