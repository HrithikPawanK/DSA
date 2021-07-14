#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
int countDistinct(int arr[], int n){
    unordered_set<int> s;
    // we can directly specify the entire array
    // unordered_set<int> s1(arr,arr+n);
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    return s.size();
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << countDistinct(arr,n) << endl;
    return 0;
}