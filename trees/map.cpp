#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> m;
    // keys are sorted in ascending order
    m.insert({3 , 4});
    m[5] = 100;
    for(auto &x : m){
        cout << x.first << " " << x.second << endl;
    }   
    // if we use m[x] then x will be inserted even if we access without assigning
    // its default val will be 0 for int
    // m.at(10) = 300;  same as square brackets. but here if key not present then it returns exception.
    // m.size()
    // m.find()
    // m.count() --> return 1 if found, 0 if not found.
    // m.lower_bound()
    // m.upper_bound() // it sorted in decreasing if we search for x we get lesser value t i.e t < x
    // m.earse()
    for(auto it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}