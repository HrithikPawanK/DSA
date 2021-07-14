#include<bits/stdc++.h>
using namespace std;
void permutate(string s, int l, int h){
    if(l==h){
        cout << s << endl;
        return;
    }
    for(int i = l; i <= h; i++){
        swap(s[l], s[i]);
        permutate(s, l+1, h);
        swap(s[l], s[i]);
    }
}
int main(){
    string s = "abc";
    permutate(s, 0, 2);
    return 0;
}