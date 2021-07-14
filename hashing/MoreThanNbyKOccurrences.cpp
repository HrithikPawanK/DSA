#include<bits/stdc++.h>
using namespace std;
// O(n) but its not good if k is less and n is large 
// because we need to store all the elements.
void solve(int arr[], int n, int k){
    unordered_map<int,int> umap;
    for(int i = 0; i < n; i++){
        umap[arr[i]]++;
    }
    for(auto x : umap){
        if(x.second > n/float(k)){
            cout << x.first << " ";
        }
    }
    cout << endl;
}
int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solve(arr,n,k);
    return 0;
}