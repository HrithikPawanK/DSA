#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
void frequencyOfArrayElements(int arr[], int n){
    unordered_map<int,int> umap;
    for(int i = 0; i < n; i++){
        umap[arr[i]]++;
    }
    for(auto it:umap){
        cout << it.first << " " << it.second << endl;
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    frequencyOfArrayElements(arr,n);
    return 0;
}