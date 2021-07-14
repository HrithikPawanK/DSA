#include<bits/stdc++.h>
using namespace std;
// topological sorting is used in DAG (Directed Acyclic Graph)
// in topological sorting first we print independent jobs then its dependent jobs then so on.
// ** it is used for job scheduling when jobs dependent on another jobs.

// BFS based
// BFS based topological sorting is called Khan's Algorithm.

/*  
    1. first store indegree of all vertices.
    2. 0 indegree vetices to queue
    3. then do bfs.
    4. note: while doing bfs decrease the indegree of adjacent vertices by 1. and enqueue them if their indegre becomes 0.
*/
void addEdge(vector<vector<int>> &adj, int u, int v, vector<int> &indegree){
    adj[u].push_back(v);
    indegree[v]++; // increasing indegree because it's u --> v
}
// if addEdge is already written then in order to get indegree traverse the adj list and keep increment indegree[v]
// if it appears in adj list.
void BFS(vector<vector<int>>& adj, vector<int>& indegree, int V){
    // note visited array is not needed
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            indegree[v]--; // main logic
            if(indegree[v]==0){ // it 0 then only push to queue
                q.push(v);
            }
        }
    }
}
// Cycle detection using Khan's algorithm (BFS base topological sorting)
// idea is if there exits a cycle then at some point there will be no 0 indegree vertex to process. so it stops there.
// it means total processed vertices will be less than total vertices.
// reason: in cycle there is no starting point.
bool CycleDetection(vector<vector<int>>& adj, vector<int>& indegree, int V){
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count = 0; // counting how many vertices are traversed(printed).
    while(!q.empty()){
        int u = q.front();
        q.pop();
        count++; // main logic
        for(int v : adj[u]){
            indegree[v]--; 
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return count != V; // main logic
}


// topological sorting using DFS
/*
    logic: we just do DFS and maintain a stack we push a vertex to stack only after its dependencies were pushed to stack.
*/

void DFS(vector<vector<int>>& adj, int s, stack<int>& st, vector<bool>& visited){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u]==false){
            DFS(adj, u, st, visited);
        }
    }
    st.push(s);
}

void topologicalSort(vector<vector<int>>& adj, int V){
    vector<bool> visited(V, false);
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(visited[i]==false){
            DFS(adj, i, st, visited);
        }
    }
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cout << u << " ";
    }
    cout << endl;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    vector<int> indegree(V, 0);
    int u,v;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        addEdge(adj, u, v, indegree);
    }
    topologicalSort(adj, V);
    return 0;
}