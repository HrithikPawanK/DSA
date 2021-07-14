#include<bits/stdc++.h>
using namespace std;
/*
    we use distance vector and finalize vector.
    dist vector initially has INF for every vertex except src.
    for each loop we find the minimum dist vertex and finalise it by relaxing adjacent vertices.
    :) done.
*/
vector<int> dijkstra(vector<vector<int>>& graph, int V, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false); // finalized
    for(int count = 0; count < V-1; count++){
        int u = -1;
        for(int i = 0; i < V; i++){
            if(!fin[i] and (u==-1 or dist[i] < dist[u])){
                u = i;
            }
        }
        fin[u] = true;
        for(int v = 0; v < V; v++){
            if(graph[u][v]!=0 and fin[v]==false){
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}
int main(){    
    int V,E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    int x,y,w;
    for(int i = 0; i < E; i++){
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w;
    }
    vector<int> ans = dijkstra(graph, V, 0);
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
