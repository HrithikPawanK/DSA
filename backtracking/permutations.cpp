#include<bits/stdc++.h>
using namespace std;
// print all permutations which do not contain given substring ex: AB
bool isSafe(string s, int l, int i, int h){
    if(l != 0 and s[l-1] == 'A' and s[i]=='B'){
        return false;
    }
    if(h = l + 1 and s[i] == 'A' and s[l]== 'B'){
        return false;
    }
    return true;
}
void permutate(string s, int l, int h){
    if(l==h){
        if(s.find("AB")==string::npos){
            cout << s << endl;
        }
        return;
    }
    for(int i = l; i <= h; i++){
        if(isSafe(s, l, i, h)){
            swap(s[l], s[i]);
            permutate(s, l+1, h);
            swap(s[l], s[i]);
        }
    }
}
int main(){
    string s = "ABC";
    permutate(s, 0, 2);
    return 0;
}