#include<bits/stdc++.h>
using namespace std;
int longestSubArrayWithGivenSum(int arr[], int n, int summ){
    unordered_map<int,int> m;
    int pre_sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(pre_sum==summ){
            res = i+1;
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({pre_sum,i});
        }
        if(m.find(pre_sum-summ)!=m.end()){
            res = max(res, i - m[pre_sum-summ]);
        }
        m.insert({pre_sum,i});
    }
    return res;
}
int main(){
    int n, summ;
    cin >> n >> summ;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = longestSubArrayWithGivenSum(arr, n, summ);
    cout << ans << endl;
    return 0;
}