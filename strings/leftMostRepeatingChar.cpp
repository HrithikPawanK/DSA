#include<bits/stdc++.h>
using namespace std;

// abbcac -> a it means the one which is left most having frequency greater than 1.

// better solution (two traversals)
const int CHAR = 256;
int leftMost(const string &s){
    int count[CHAR] = {0};
    for(int i = 0; i < s.length(); i++){
        count[s[i]]++;
    }
    for(int i = 0; i < s.length(); i++){
        if(count[s[i]] > 1){
            return i;
        }
    }
    return -1;
}

// Efficient Approach-1 (one traversal)

// using firstindex array initially set to -1 
// while travering if firstindex[char] is -1 then change to i else take the res as min of res and firstindex of that char.

int leftMostE(const string &s){
    int findex[CHAR];
    fill(findex, findex + CHAR, -1);
    int res = INT_MAX;
    for(int i = 0; i < s.length(); i++){
        int fi = findex[s[i]];
        if(fi==-1){
            findex[s[i]] = i;
        }else{
            res = min(res, fi);
        }
    }
    return (res==INT_MAX)? -1 : res;
}

// Efficient Approach-2

// traversing from right to left and maintaining a visited array if the char is visited then update the
// result which stores the index of most recent already visited char.

int leftMostE2(const string &s){
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);
    int res = -1;
    for(int i = s.length()-1; i >= 0; i--){
        if(visited[s[i]]){
            res = i;
        }
        else{
            visited[s[i]] = true;
        }
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    cout << leftMostE2(s) << endl;
    return 0;
}