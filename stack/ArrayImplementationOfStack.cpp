#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
    int *a;
    int top;
    int cap;
    Stack(int c){
        cap = c;
        a = new int[c];
        top = -1;
    }  
    void push(int x){
        if(top == cap - 1) return;
        top++;
        a[top] = x;
    }
    int pop(){
        if(top == -1) return INT_MIN;
        int res = a[top];
        top--;
        return res;
    }
    int peak(){
        if(top == -1) return INT_MIN;
        return a[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        return (top == -1);
    }
};
// using vector(dynamic)
class DynamicStack{
    public:
    vector<int> v;
    void push(int x){
        v.push_back(x);
    }
    int pop(){
        int res = v.back();
        v.pop_back();
        return res;
    }
    int size(){
        return v.size();
    }
    bool empty(){
        return v.empty();
    }
    int peak(){
        return v.back();
    }
};
int main(){
    Stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peak() << endl;
    st.pop();
    st.pop();
    st.push(5);
    cout << st.size() << endl;
    while(!st.isEmpty()){
        cout << st.peak() << endl;
        st.pop();
    }
    return 0;
}