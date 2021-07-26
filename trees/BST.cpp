#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left, *right;
    Node(int k){
        val = k;
        left = right = NULL;
    }
};
// time complexity : O(h)
// Auxilary space: O(h)
bool Search(Node *root, int k){
    if(!root) return false;
    else if(root->val == k) return true;
    else if(root->val > k) return Search(root->left, k);
    else return Search(root->right, k);
}
Node *Insert(Node *root, int k){
    if(!root) return new Node(k);
    else if(root->val > k){
        root->left = Insert(root->left, k);
    }
    else if(root->val < k){
        root->right = Insert(root->right, k);
    }
    return root;
}
/*
    There are there cases in deletion.
    1) if its a leaf then no issue simply delete.
    2) if one of its leaf is empty then delete the node and add its child to parent.
    3) if both are not empty then find the closest larger value or smaller value(Inorder successor)
      and copy that val to deleting node then delete the Inorder successor value.
    here we are considering closest larger value.
*/
// considering closet larger element.
// note that it works fine only when right child is not empty.
Node *getInorderSuccessor(Node *root){
    Node *curr = root->right;
    // returning left most child of (right child of deleting node). 
    while(curr!=NULL and curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}
// time complexity - O(h)
Node *Delete(Node *root, int k){
    if(!root) return root;
    else if(root->val > k) root->left = Delete(root->left, k);
    else if(root->val < k) root->right = Delete(root->right, k);
    else{
        if(root->left == NULL){
            // delete node and add its right to parent as child.
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            // delete node and add its left to parent as child.
            Node *temp = root->left;
            delete root;
            return temp;
        }else{
            // find inorder successor and copy its val to the deleting node.
            Node *succ = getInorderSuccessor(root);
            root->val = succ->val;
            // now call the Delete fun to delete the succ node.
            root->right = Delete(root->right, succ->val);
        }
    }
}
// closest smaller value than given.
// if given value present then return that value.
Node* FloorInBST(Node *root, int k){
    Node *res = NULL;
    while(root!=NULL){
        if(root->val == k) return root;
        else if(root->val > k){
            root = root->left;
        }
        else{
            res = root;
            root = root->right;
        }
    }
    return res;
}
// closet value greater than or equal to given value.
Node *Ceil(Node *root, int k){
    Node *res = NULL;
    while(root!=NULL){
        if(root->val == k) return root;
        else if(root->val < k){
            root = root->right;
        }
        else{
            res = root;
            root = root->left;
        }
    }
    return res;
}
/*  
    Applications of BST
    1. to maintain sorted stream of data(or sorted set of data). we can use to maintain data sorted
       if it involves insertion, deletions.
    2. to implement doubly ended priority queue.
    3. to solve problems like:
        a) count smaller/ greater in a stream
        b) Floor/ ceil/ greater/ smaller in a stream.
*/

// find kth smallest element
// kth smallest can be found easily if we do inorder traversal for k steps.
// as inorder traversal prints elements in sorted order in BST

void printKth(Node *root, int k, int& count){
    if(root){
        printKth(root->left, k, count);
        count++;
        if(count == k){
            cout << root->val << endl;
            return;
        }
        printKth(root->right, k, count);
    }
}

int main(){
    return 0;
}