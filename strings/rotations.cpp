#include<bits/stdc++.h>
using namespace std;
// we were given two strings s1 and s2.
// we need to find where s1 becomes s2 by rotating some units left or right.
// trick concatenate s1 and s1 then find s2 in that. :)
bool rotation(string& s1, string& s2){
    if(s1.length() != s2.length()){
        return false;
    }
    return ((s1+s1).find(s2) != string::npos);
}
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << rotation(s1, s2);
    return 0;
}