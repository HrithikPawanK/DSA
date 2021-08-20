#include<bits/stdc++.h>
using namespace std;
//Function to find length of longest increasing subsequence.
// tail of i stores the minimum possible tail value for LIS of length i + 1.
// if current element greater thant tail element then append
// else place the current element using Binary Search.
int longestSubsequence(int n, int a[])
{
    vector<int> tail;
    tail.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > tail.back()) tail.push_back(a[i]);
        else{
            int idx = lower_bound(tail.begin(), tail.end(), a[i]) - tail.begin();
            tail[idx] = a[i];
        }
    }
    return tail.size();
}
int main(){
    
    return 0;
}