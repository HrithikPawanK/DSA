#include<bits/stdc++.h>
using namespace std;
// logic : one stack from front of array and other from back of array.
class TwoStacks{
    int *arr, cap, top1, top2;
    TwoStacks(int c){
        cap = c;
        arr = new int[c];
        top1 = -1;
        top2 = c;
    }
    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            arr[top2] = x; 
        }
    }
    void push1(int x){
        if(top1 + 1 < top2){
            top1++;
            arr[top1] = x;
        }
    }
    int pop1(){
        if(top1 >= 0){
            int res = arr[top1];
            top1--;
            return res;
        }
        return INT_MAX;
    }
    int pop2(){
        if(top2 < cap){
            int res = arr[top2];
            top2++;
            return res;
        }
        return INT_MAX;
    }
};
int main(){

    return 0;
}