#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        child[0] = NULL, child[1] = NULL;
    }
};
// returns true if new row inserted or if already exists it return false
bool insert(TrieNode* root, int row, vector<vector<bool>>& matrix){
    TrieNode *curr = root;
    bool flag = false;
    for(int j = 0; j < matrix[0].size(); j++){
        int index = matrix[row][j];
        if(curr->child[index]==NULL){
            flag = true;
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    return flag;
}
// time complexity -> O(mn), space complexity -> O(mn)
int countDist(){
    TrieNode* root = new TrieNode();
    vector<vector<bool>> matrix(3, vector<bool>(3));
    int res = 0;
    for(int row = 0; row < 3; row++){
        if(insert(root, row, matrix)){
            res++;
        }
    }
    return res;
}
int main(){

    return 0;  
}