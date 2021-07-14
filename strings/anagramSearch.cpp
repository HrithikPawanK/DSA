#include<bits/stdc++.h>
using namespace std;
/*
    we were given strings txt and pattern we need to find whether there exists any substring in txt
    such that substring is an anagram of pattern.
    -> anagram means any of its permutations. 
*/
// using sliding window and maintaining two arrays for frequecy and comparing them. :)
const int CHAR = 256;
bool isSame(int ct[], int cp[]){
    for(int i = 0; i < CHAR; i++){
        if(ct[i]!=cp[i]) return false;
    }
    return true;
}
bool isPresent(string txt, string pat){
    int m = pat.length();
    int n = txt.length();
    int ct[CHAR] = {0}, cp[CHAR] = {0};
    for(int i = 0; i < m; i++){
        ct[txt[i]]++;
        cp[pat[i]]++;
    }
    if(isSame(ct, cp)){
        return true;
    }
    for(int i = m; i < n; i++){
        ct[txt[i]]++;
        ct[txt[i-m]]--;
        if(isSame(ct, cp)) return true;
    }
    return false;
}
int main(){
    string txt = "geeksforgeekst"; 
    string pat = "rofgk"; 
    cout << isPresent(txt, pat) << endl;
    return 0;
}