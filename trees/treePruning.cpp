#include<bits/stdc++.h>
using namespace std;
// Given a binary tree root, prune the tree so that subtrees containing all 0s are removed.
class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};
Tree* solve(Tree* root) {
    if(!root) return root;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if(!root->left and !root->right and root->val == 0){
        delete root;
        return NULL;
    }
    return root;
}