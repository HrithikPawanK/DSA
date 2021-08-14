#include<bits/stdc++.h>
using namespace std;
/*
    we are considering ^, *, /, +, - operators.
    ^ --> highest precedance and right to left associativity.
    *, / --> middle and left to right
    +, - --> low  and left to right
*/
string infixToPostfix(string s)
{
    stack<char> st;
    unordered_map<char,int> m = {{'^',3},{'*',2},{'/',2},{'+',1},{'-',1},{'(',0}};
    string res;
    for(char c : s){
        if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(m.find(c)==m.end()){
            res += c;    
        }else{
            if(st.empty()) st.push(c);
            else if(m[c] > m[st.top()]){
                st.push(c);
            }else{
                while(!st.empty() and m[c] <= m[st.top()]){
                    if(c=='^'){
                        break;
                    } 
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    return 0;
}