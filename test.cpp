#include<bits/stdc++.h>
using namespace std;
string solve(string s) { 
    string ans = "";
    stack<char> st;
    int flag = 0;
    for(char c : s){
        if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty()){
                ans += c;
            }else{
                st.push(c);
            }
        }
    }
    return ans;
}
int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}