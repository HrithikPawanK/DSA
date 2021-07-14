#include<bits/stdc++.h>
using namespace std;
// it is similar to longest sub array with given summ
// replace 0's with -1 then find the longest sub array with summ as zero.
// easy :)
int solve(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i]==0){
            arr[i] = -1;
        }
    }
    unordered_map<int, int> m;
    int pre_sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(pre_sum == 0){
            res = i+1;
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({pre_sum,i});
        }
        if(m.find(pre_sum)!=m.end()){
            res = max(res, i - m[pre_sum]);
        }
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = solve(arr,n);
    cout << ans << endl;
    return 0;
}