#include<bits/stdc++.h>
using namespace std;
// contiguous left elements which are less or equal to current day stocks.
// here we are finding closest left greater element.
vector <int> calculateSpan(int price[], int n)
{
    vector<int> res;
    stack<int> s;
    s.push(0);
    res.push_back(1);
    for(int i = 1; i < n; i++){
        while(!s.empty() and price[i] >= price[s.top()]) s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        s.push(i);
        res.push_back(span);
    }
    return res;
}
int main(){
    
    return 0;
}