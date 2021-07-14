#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> a[], int u, int v){
    a[u].push_back(v);
    a[v].push_back(u);
}
int main(){
    int V = 4;
    vector<int> a[4];
    addEdge(a,0,1);  
    addEdge(a,0,2);  
    addEdge(a,1,2);  
    addEdge(a,1,3);  
    return 0;
}