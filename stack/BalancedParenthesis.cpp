#include<bits/stdc++.h>
using namespace std;
// logic latest opened should be closed first
bool balParenthesis(string& s){
    stack<char> st;
    unordered_map<char,char> m = {{')','('}, {']','['}, {'}', '{'}};
    for(char c : s){
        if(c == '(' or c == '[' or c == '{'){
            st.push(c);
        }else{
            if(st.empty()){
                return false;
            }
            if(st.top()!=m[c]){
                return false;
            }
            st.pop();
        }
    }
    return (st.empty() == true);
}
int main(){   
    string s = "";
    return 0;
}