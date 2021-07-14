#include<bits/stdc++.h>
using namespace std;

// Naive --> O(n^2)
int nonRep(const string &s){
    int res = -1;
    for(int i = 0; i < s.length(); i++){
        bool flag = false;
        for(int j = 0; j < s.length(); j++){
            if(i!=j and s[i]==s[j]){
                flag = true;
                break;
            }
        }
        if(flag==false){
            return i;
        }
    }
    return -1;
}

const int CHAR = 256;

// Efficient (two Traversal)
int nonRepE(const string &s){
    int count[CHAR] = {0};
    for(int i = 0; i < s.length(); i++){
        count[s[i]]++;
    }
    for(int i = 0; i < s.length(); i++){
        if(count[s[i]]==1){
            return i;
        }
    }
    return -1;
}

// Efficient (one Traversal)
// logic maintain first index array with initial values as -1;
// traverse the string first index of char = -1 change to i if repeated change it to -2 so that it wont 
// be counted for result.
// then find the minimum of the first index 
// its easy because only distinct elements index values will be >= 0 remaining will be -1 or -2

int nonRepE2(const string &s){
    int findex[CHAR];
    fill(findex, findex + CHAR, -1);
    for(int i = 0; i < s.length(); i++){
        if(findex[s[i]] == -1){
            findex[s[i]] = i;
        }else{
            findex[s[i]] = -2;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < 256; i++){
        if(findex[i]>=0){
            ans = min(ans, findex[i]);
        }
    }
    return (ans==INT_MAX)? -1 : ans;
}
int main(){
    string s;
    cin >> s;
    cout << nonRepE2(s) << endl;
    return 0;
}