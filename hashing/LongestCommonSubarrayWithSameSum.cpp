#include<bits/stdc++.h>
using namespace std;
// we are given arrays with equal sizes.
// we need to find the longest subarray in both such that starting and ending 
// are equal in both and the sums are equal.

// logic here is to subtract arr2 from arr1 then find the longest
// subarray with sum zero.
int solve(int arr1[], int arr2[], int n){
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++){
        arr1[i] -= arr2[i];
    }
    int pre_sum = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr1[i];
        if(pre_sum==0){
            res = i + 1;
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
    int arr1[n], arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    int ans = solve(arr1,arr2,n);
    cout << ans << endl;
    return 0;
}