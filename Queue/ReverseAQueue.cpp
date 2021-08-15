#include<bits/stdc++.h>
using namespace std;
// using recursion
void reverse(queue<int>& q){
    if(q.empty()) return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}
int main(){
    // using stack
    queue<int> q;
    for(int i = 1; i <= 5; i++){
        q.push(i);
    }
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl; 
    
    // for recursive method.
    queue<int> q1;
    for(int i = 1; i <= 5; i++){
        q1.push(i);
    }
    reverse(q1);
    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    return 0;
}