#include<bits/stdc++.h>
using namespace std;
struct Test{
    int x;
    bool operator < (const Test& t) const{
        return (this->x > t.x);
    }
};
int main(){
     // set<int> s;
    set<int, greater<int>> s;
    s.insert(10);
    s.insert(20);
    s.insert(2);
    s.insert(11);
    for(int x : s){
        cout << x << " ";
    }
    cout << endl;
    for(auto it = s.begin(); it != s.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
    // reverse traversing
    for(auto it = s.rbegin(); it != s.rend(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
    auto it = s.find(11); // it returns iterator of given element. if not found it return s.end();
    if(it == s.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    while(it!=s.end()){
        cout << (*it) << endl;
        it++;
    }
    // s.clear(); removes all elements.
    cout << s.size() << endl; // return size
    // count return count of an elements. it can be used to check elements in set.
    // s.erase(10);
    //auto it = s.find(10);
    //s.erase(it);  we can pass iterator
    s.erase(it, s.end()); // we can erase range of elements
    // lower_bound, upper_bound are member functions for set.

    // if element not present the it return iterator to next greater value. if greater than last element it return s.end()
    //auto it = s.lower_bound(9); // if element present then it returns that element iterator
    // similarly s.upper_bound(9); 
    // erase(it) --> O(1)
    // insert, count, upper_bound , lower_bound, earse(x), find --> O(logn)
    // size, rbegin(), rend(), begin(), end() --> O(1)

    // custom data type
    set<Test> s1;
    s1.insert({2});
    s1.insert({3});
    s1.insert({4});
    for(Test t : s1) cout << t.x << " ";
    cout << endl;
    return 0;
}