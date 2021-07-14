#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
void SieveOfEratosthenes(ll n){
    vector<ll> prime(n+1, true);
    for(ll p = 2; p*p <= n; p++){
        if(prime[p]==true){
            for(ll i = p*p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }
    for(ll i = 2; i <= n; i++){
        if(prime[i]==true){
            cout << i << " ";
        }
    }
    cout << endl;
}
int main(){
    SieveOfEratosthenes(50);
    return 0;
}