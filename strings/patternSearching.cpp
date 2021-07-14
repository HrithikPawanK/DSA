#include<bits/stdc++.h>
using namespace std;
// naive Pattern Searching
void patterMatching(string &text, string &pattern){
    int n = text.length();
    int m = pattern.length();
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(pattern[j]!=text[i+j]) break;
        }
        if(j==m){
            cout << i << " ";
        }
    }
}


int main(){
    string text, pattern;
    cin >> text >> pattern; 
    patterMatching(text,pattern);
    return 0;
}