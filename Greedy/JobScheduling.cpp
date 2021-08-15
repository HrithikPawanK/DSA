#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
int JobScheduling(vector<pair<int,int>> &v){
    sort(v.begin(),v.end(),cmp);
    int maxDeadLine = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first > maxDeadLine){
            maxDeadLine = v[i].first;
        }
    }
    bool arr[maxDeadLine+1];
    arr[0] = true;
    int ans = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = v[i].first; j > 0; j--){
            if(arr[j]==false){
                arr[j] = true;
                ans += v[i].second;
                break;
            }
        }
    }
    return ans;
}
int main(){
    vector<pair<int,int>> v;
    int n,deadline,profit;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> deadline >> profit;
        v.push_back({deadline,profit});
    }
    int ans = JobScheduling(v);
    cout << ans;
    return 0;
}