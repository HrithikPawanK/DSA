#include<bits/stdc++.h>
using namespace std;
bool SubArrayWithGivenSum(int arr[], int n, int summ){
    for(int i = 0; i < n; i++){
        int curr_sum = 0;
        for(int j = i; j < n; j++){
            curr_sum += arr[j];
            if(curr_sum == summ){
                return true;
            }
        }
    }
    return false;
}
//using hashing
//using prefix summ concept
bool SubArrayWithGivenSumHashing(int arr[], int n, int summ){
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(pre_sum==summ){
            return true;
        }
        if(s.find(summ-pre_sum)!=s.end()){
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
int main(){
    int n, summ;
    cin >> n >> summ;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bool flag = SubArrayWithGivenSumHashing(arr,n,summ);
    if(flag){
        cout << "exists" << endl;
    }else{
        cout << "does not exists" << endl;
    }
    return 0;
}