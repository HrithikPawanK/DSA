#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};
TrieNode *root;
bool Search(string &key){
    TrieNode *curr = root;
    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if(curr->child[index]==NULL){
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isEnd;
}
void Insert(string &key){
    TrieNode *curr = root;
    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if(curr->child[index] == NULL){
            curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}
bool isEmpty(TrieNode *root){
    for(int i = 0; i < 26; i++){
        if(root->child[i]!=NULL){
            return false;
        }
    }
    return true;
}
TrieNode* delkey(TrieNode *root, string &key, int i){
    if(root==NULL) return NULL;
    if(i == key.length()){
        root->isEnd = false;
        if(isEmpty(root)){
            delete root;
            root = NULL;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = delkey(root, key, i+1);
    if(isEmpty(root) && root->isEnd==false){
        delete root;
        root = NULL;
    }
    return root;
}

int main(){   
    return 0;
}