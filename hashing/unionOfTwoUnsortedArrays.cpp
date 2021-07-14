#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
int countDistinctUnionElements(int a[], int b[], int m, int n){
    unordered_set<int> s(a,a+m);
    for(int i = 0; i < n; i++){
        s.insert(b[i]);
    }
    return s.size();
}
int main(){
    int m,n;
    cin >> m >> n;
    int a[m], b[n];
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    cout << countDistinctUnionElements(a,b,m,n) << endl;
    return 0;
}