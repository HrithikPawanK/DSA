#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    set<int> s;
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(arr[i]);
        if(it!=s.end()){
            cout << (*it) << " ";
        }else{
            cout << -1 << " ";
        }
        s.insert(arr[i]);
    }
    cout << endl;
    return 0;
}