#include<bits/stdc++.h>
using namespace std;
// next greater element 
// traversing from back :)
// finally reverse the result.
vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> res;
    res.push_back(-1);
    stack<long long> st;
    st.push(arr[n-1]);
    for(int i = n - 2; i >= 0; i--){
        while(!st.empty() and arr[i] >= st.top()) st.pop();
        long long nextGreater = st.empty() ? -1: st.top();
        res.push_back(nextGreater);
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    
    return 0;
}