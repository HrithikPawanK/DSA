#include<bits/stdc++.h>
using namespace std;
// count of subsets with given sum
// ** first generate all subset then only check for summ == 0.
int subsetSum(int arr[], int n, int sum){
    if(n == 0){
        return (sum == 0)? 1 : 0;
    }
    return subsetSum(arr, n - 1, sum) + subsetSum(arr, n - 1, sum - arr[n - 1]);
}
int main(){
    
    return 0;
}