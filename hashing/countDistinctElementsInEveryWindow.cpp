#include<bits/stdc++.h>
using namespace std;
// we need to find distinct elements in each window of size k
// for an array of size n there will be n-k+1 windows
// here we are using unordermap to store frequencies of each elemnt
// first we add elements of first window 
// then we traverse through k to n-1 for other windows just by 
// removing last element from past windows and adding new element
// if frequency of deleted element is zero remove element from map
// for each iteration print size of map
void solve(int arr[], int n, int k){
    unordered_map<int,int> umap;
    for(int i = 0; i < k; i++){
        umap[arr[i]]++;
    }
    cout << umap.size() << " ";
    for(int i = k; i < n; i++){
        umap[arr[i-k]]--;
        if(umap[arr[i-k]]==0){
            umap.erase(arr[i-k]);
        }
        umap[arr[i]]++;
        cout << umap.size() << " ";
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