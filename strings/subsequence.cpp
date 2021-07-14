#include<bits/stdc++.h>
using namespace std;
bool isSubsequenceRec(const string &s1, const string &s2, int n, int m){
    if(m==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(s1[n-1] == s2[m-1]){
        return isSubsequenceRec(s1,s2,n-1,m-1);
    }
    return isSubsequenceRec(s1,s2,n-1,m);
}
bool isSubSequence(string s1, string s2){
    int n,m;
    n = s1.length();
    m = s2.length();
    int j = 0;
    for(int i = 0; i < n and j < m; i++){
        if(s1[i]==s2[j]){
            j++;
        }
    }
    return (j==m);
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;  
    int n = s1.length(), m = s2.length();
    cout << isSubSequence(s1,s2) << endl;
    cout << isSubsequenceRec(s1,s2,n,m) << endl;
    return 0;
}