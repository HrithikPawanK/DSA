#include<bits/stdc++.h>
using namespace std;
vector <int> maxOfMin(int arr[], int n)
{
    stack<int> st;
    int l[n], r[n];
    l[0] = -1;
    st.push(0);
    for(int i = 1; i < n; i++){
        while(!st.empty() and arr[i] <= arr[st.top()]) st.pop();
        l[i] = st.empty()? -1 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    r[n-1] = n; 
    st.push(n-1);
    for(int i = n - 2; i >= 0; i--){
        while(!st.empty() and arr[i] <= arr[st.top()]) st.pop();
        r[i] = st.empty()? n : st.top();
        st.push(i);
    }
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        int len = r[i] - l[i] - 2;
        res[len] = max(res[len], arr[i]);
    }
    for(int i = n-2; i > 0; i--){
        res[i] = max(res[i], res[i+1]);
    }
    return res;
}
int main(){
    
    return 0;
}