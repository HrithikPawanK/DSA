#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
int main(){
    // it does not maintain any order
    // all operations are O(1) on average
    unordered_set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // find return s.end() if not found. if found returns iterator of that element
    if(s.find(15)==s.end()){
        cout << "Not found" << endl;
    }else{
        cout << "found" << " " << *(s.find(15)) << endl;
    }
    // count return 1 if found else 0
    if(s.count(15)==1){
        cout << "Found" << endl;
    }else{
        cout << "not found" << endl;
    }
    // erase can be done using element or iterator
    s.erase(15);
    auto it = s.find(10);
    s.erase(it);
    // we can pass range to erase
    s.erase(s.begin(), s.end()); // s.end() is not included
    cout << s.size() << endl;
    // clear clears the entire set
    s.clear();
    cout << s.size() << endl;
    return 0;
}