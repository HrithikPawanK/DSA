#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int LIS(vector<pair<int,int>> &v, int n){
    vector<int> lis(n,0);
    lis[0] = 1;
    for(int i = 1; i < n; i++){
        lis[i] = 1;
        for(int j = 0; j < i; j++){
            if(v[j].second < v[i].second){
                lis[i] = max(lis[i],lis[j]+1);
            }
        }
    }
    int maxx = lis[0];
    for(int i = 1; i < n; i++){
        if(lis[i] > maxx){
            maxx = lis[i];
        }
    }
    return maxx;
}
int main(){
    vector<pair<int,int>> v;
    int n;
    cin >> n;
    int x,y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),mycmp);
    int res = LIS(v,n);
    cout << "LIS: "<< res << endl;
}