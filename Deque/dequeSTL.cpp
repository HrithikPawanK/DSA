#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq = {10, 20, 30};
    dq.push_front(5);
    dq.push_back(50);
    for(auto x : dq){
        cout << x << " ";
    }
    cout << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    auto it = dq.begin();
    it++;
    dq.insert(it, 20);
    dq.pop_front();
    dq.pop_back();
    cout << dq.size() << endl;
    return 0;
}