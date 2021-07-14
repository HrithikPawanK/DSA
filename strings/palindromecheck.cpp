#include<bits/stdc++.h>
using namespace std;
int main(){
    string s, s1;
    cin >> s;   
    s1 = s;
    reverse(s1.begin(), s1.end());
    cout << (s1==s) << endl;
    bool flag = true;
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i]!=s[n-i-1]){
            flag = false;
            break;
        }
    }
    cout << flag << endl;
    return 0;
}