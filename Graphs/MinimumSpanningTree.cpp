#include<bits/stdc++.h>
using namespace std;
/*
    spanning tree: A subgraph from the given graph such that it has V vertices and V-1 edges and
    vertices are connected.
    minimum spanning tree : spanning tree with minimum total weight. 
    Note: ** spanning tree is only applicable for undirected graph.
    ** minimum spanning tree is only applicable for weighted undirected graph.
*/
// prims algorithm
/*  
    first consider any vertex then considering it as a cluster. now join edge such that it has 
    minimum weight and connects any node from cluster to any of the remaining vertices. same pattern untill all 
    vertices are added.

    we take MST array we make every vertex true which are in cluter remaining as false.
    we add vertices not in mst to mst which has minimum weight. 
*/
// time complexity --> O(V*V) it can we optimized if we use adjancency list representation and min heap
// data structure for getting minimum value every time.
// key array is maintained so that for every vertex we add to cluster it adds its adjacent vertices weights.
// if already present and if the new weights are less then they will be updated.
int primMst(vector<vector<int>>& graph, int V){
    vector<int> key(V, INT_MAX);
    vector<bool> mSet(V, false);
    int res = 0;
    key[0] = 0; // considering first vertex as 0.
    for(int count = 0; count < V; count++){
        int u = -1; // minimum index;
        for(int i = 0; i < V; i++){
            if(!mSet[i] and (u == -1 || key[i] < key[u])){
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];
        for(int v = 0; v < V; v++){
            if(graph[u][v]!=0 and !mSet[v]){
                key[v] = min(key[v], graph[u][v]); // note we are using graph[u][v] because it is distance between u and v.
            }
        }
    }
    return res;
}
int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    int u,v,w;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    cout << primMst(graph, V) << endl;
    return 0;
}