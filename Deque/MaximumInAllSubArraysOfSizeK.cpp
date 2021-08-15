#include<bits/stdc++.h>
using namespace std;
void bruteForce(int arr[], int n, int k){
    for(int i = 0; i <= n - k; i++){
        int maxx = arr[i];
        for(int j = i + 1; j < i + k; j++){
            maxx = max(maxx, arr[j]);
        }
        cout << maxx << " ";
    }
    cout << endl;
}
// using deque --> O(n)
// logic always have greater element as front of deque
// add elements from back if element is greater then back of deque then remove element until
// back becomes greater or deque becomes empty
// remove all elements from front which are not part of current window.
// we'll get largest element of current window from front. 
void printKMax(int arr[], int n, int k){
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while(!dq.empty() and arr[i] >= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
    for(int i = k; i < n; i++){
        while(!dq.empty() and dq.front() <= i - k) dq.pop_front();
        while(!dq.empty() and arr[i] >= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
        cout << arr[dq.front()] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {10, 8, 5, 12, 15, 7, 6};
    int n = 8, k = 3;
    bruteForce(arr, n, k);
    printKMax(arr, n, k);
    return 0;
}   