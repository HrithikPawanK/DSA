#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
int main(){
    // used to store key value pairs
    // uses hasing
    // no order
    // all operations are O(1) on average
    unordered_map<string,int> m;
    m["gfg"] = 20;
    m["ide"] = 30;
    m.insert({"courses",15});
    // it can be in any order
    for(auto x:m){
        cout << x.first << " " << x.second << endl;
    }
    if(m.find("ide") != m.end()){
        cout << "found\n"; 
    }else{
        cout << "not found\n";
    }
    auto it = m.find("ide");
    if(it!=m.end()){
        cout << (it->second) << endl;
    }
    for(auto it = m.begin(); it!=m.end(); it++){
        cout << (it->first) << " " << (it->second) << endl;
    }
    // if we want to traverse in reverse order use rbegin(),rend() but not use in unordered map
    if(m.count("ide") > 0){
        cout << "found" << endl;
    }
    // size return number of key value pairs
    cout << m.size() << endl;
    // erase removes by key or iterator
    m.erase("ide");
    m.erase(m.begin(),m.end());
    return 0;
}