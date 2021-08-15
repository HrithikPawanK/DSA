#include<bits/stdc++.h>
using namespace std;
// making push costly.
class Stack{
    public:
    queue<int> q1, q2;
    int pop(){
        int res = q1.front();
        q1.pop();
        return res;
    }
    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    bool isEmpty(){
        return q1.empty();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(30);
    st.push(40);
    st.push(50);
    while(!st.isEmpty()){
        cout << st.pop() << " ";
    }
    cout << endl;
    return 0;
}