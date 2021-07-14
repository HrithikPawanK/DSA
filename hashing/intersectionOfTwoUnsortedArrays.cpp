#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
// we need to count number of distinct elements in intersection
int countDistinctIntersectionElements(int a[],int b[],int n1,int n2){
    unordered_set<int> s_a(a,a+n1);
    int count = 0;
    for(int i = 0; i < n2; i++){
        if(s_a.count(b[i])){
            // we are erasing so that the it wont check for it again. so removes duplicate problem.
            s_a.erase(b[i]);
            count++;
        }
    }
    return count;
}
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    int a[n1], b[n2];
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];
    cout << countDistinctIntersectionElements(a,b,n1,n2);
    return 0;
}