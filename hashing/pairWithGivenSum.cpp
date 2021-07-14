#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
bool PairWithGivenSum(int arr[], int n, int summ){
    unordered_set<int> h;
    for(int i = 0; i < n; i++){
        if(h.find(summ-arr[i])!=h.end()){
            return true;
        }else{
            h.insert(arr[i]);
        }
    }
    return false;
}
int main(){
    int n, summ;
    cin >> n >> summ;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool flag = PairWithGivenSum(arr,n,summ);
    if(flag==true){
        cout << "pair exits" << endl;
    }else{
        cout << "no such pair exists" << endl;
    }
    return 0;
}