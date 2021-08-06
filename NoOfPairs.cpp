#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n; cin >> n;
    int t; cin >> t;
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++){
        m[v[i]]++;
    }   
    int count = 0;
    for(int i = 0; i < n; i++){
        int d = t - v[i];
        if(d != v[i]){
            if(m.find(d)!=m.end() and m[v[i]] > 0 and m[d] > 1){
                m[v[i]]--;
                m[d]--;
                count++;
            }
        }else{
            if(m.find(d)!=m.end() and m[v[i]] > 1){
                m[v[i]]-=2;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}