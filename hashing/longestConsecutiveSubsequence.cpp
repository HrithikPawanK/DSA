#include<bits/stdc++.h>
using namespace std;
// we are given an array we need to find the longest subsequence such that they are consecutive
// ex: x, x + 1, x + 2, x + 3... or x, x-1, x-2, x-3....
// here order in array doesn't matter
// ex: arr = {1,9,3,4,2,20} ans: {1,2,3,4} so answer is 4. 

// using sorting nlogn solution
int solve(int arr[], int n){
    sort(arr,arr+n);
    int cur = 1, res = 1;
    for(int i = 1; i < n; i++){
        if(arr[i]==arr[i-1]+1){
            cur++;
        }
        else{
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res,cur);
    return res;
}

// using hashing
// create the hashset
// for each element x in set search x - 1 if not present then x is the starting element
// so check for next elements x + 1, x + 2 ... then increasing then current 
// then finally check for max of current
// if x - 1 exists then do nothing because its not the first element of the sequence 
// it will be counted by the first element of the sequence
// its an O(n) solution with total look ups 2*n
int solve2(int arr[], int n){
    unordered_set<int> h(arr, arr+n);
    int res = 1;
    for(auto x : h){
        if(h.find(x-1)==h.end()){
            int curr = 1;
            while(h.find(x+curr)!=h.end()){
                curr++;
            }
            res = max(res, curr);
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
    int ans2 = solve2(arr,n);
    cout << ans2 << endl;
    return 0;
}