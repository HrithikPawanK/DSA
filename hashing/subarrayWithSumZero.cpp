#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
// concept is current prefix sum will be equal to past prefix sum if in the middle elements add to become zero 
bool SubArrayWithSumZero(int arr[], int n){
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(s.find(pre_sum)!=s.end()){
            return true;
        }
        // if pre_sum is zero for the subarray including first element then there will be no pre_sum past 
        // so inorder to tackle that situation pre_sum == 0 used.
        if(pre_sum==0){
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int flag = SubArrayWithSumZero(arr,n);
    if(flag==true){
        cout << "exists" << endl;
    }else{
        cout << "not exists" << endl;
    }
    return 0;
}