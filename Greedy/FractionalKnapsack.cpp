#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    double r1 = (double) a.second/a.first;
    double r2 = (double) b.second/b.first;
    return r1 > r2;
}
int fractionalKnapSack(vector<pair<int,int>> &v, int capacity){
    sort(v.begin(),v.end(),cmp);
    int i = 0;
    int ans = 0;
    while(capacity!=0){
        if(v[i].first<=capacity){
            ans += v[i].second;
            capacity -= v[i].first;
        }
        else{
            ans += capacity*(v[i].second/v[i].first);
            return ans;
        }
        i++;
    }
    return ans;
}
int main(){
    vector<pair<int,int>> v;
    int n,w,p,capacity;
    cin >> n;
    cin >> capacity;
    for(int i = 0; i < n; i++){
        cin >> w >> p;
        v.push_back({w,p});
    }
    int ans = fractionalKnapSack(v,capacity);
    cout << ans;
    return 0;
}