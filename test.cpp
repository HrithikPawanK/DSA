#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define SWAP(a, b, c) {c t; t = a, a = b, b = t;}
unsigned int foo(int a, int b){
    return 1 + a < b ? -1 : foo(a--, b++);
}
unsigned int fun(){
    return -1;
}
void solve(){
    int a = 10;
    float b = 1.235;
    cout << 
}
int main(){
    ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}