#include<bits/stdc++.h>
using namespace std;
// note op2 op1
int evaluatePostfix(string S)
{
    stack<int> st;
    unordered_set<char> set = {'*','-','+','/'};
    for(char c : S){
        if(set.find(c)==set.end()){
            st.push(c-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res;
            if(c=='*'){
                res = op2 * op1;
            }else if(c=='/'){
                res = op2 / op1;
            }else if(c=='+'){
                res = op2 + op1;
            }else{
                res = op2 - op1;
            }
            st.push(res);
        }
    }
    return st.top();
}
int main(){
    
    return 0;
}