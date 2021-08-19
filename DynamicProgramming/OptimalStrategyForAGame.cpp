#include<bits/stdc++.h>
using namespace std;
// given a even sized array and two players 
// each player can take element either from front or back
// ours first turn
// we need to get maximum sum
// both play optimally
int optimalRecur(int arr[], int i, int j){
    if(i + 1 == j) return max(arr[i], arr[j]);
    return max(arr[i] + min(optimalRecur(arr, i + 2, j), optimalRecur(arr, i + 1, j - 1))
               , arr[j] + min(optimalRecur(arr, i + 2, j - 1), optimalRecur(arr, i, j - 2)));
}
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << optimalRecur(arr, 0, 3) << endl;
    return 0;
}