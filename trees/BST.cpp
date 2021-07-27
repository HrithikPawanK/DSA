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
// time complexity --> O(h + k)
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
// check for BST

// method -1
// Efficient Algo
// pass a range for every node
// for root range is -INF to +INF
// for left child of a node, in range, we change upper bound as the nodes value.
// for right child of a node, in range, we change lower bound as the nodes value.
// time complexity --> O(n) same as traversal.
// pass min as INT_MIN, max as INT_MAX

bool isBST(Node *root, int min, int max){
    if(!root) return true;
    return (root->val > min and root->val < max) and isBST(root->left, min, root->val) and isBST(root->right, root->val, max);
}
// method -2
// inorder traversal of a BST is in sorted order.
// so just check whether it is sorted or not.
// we can do it using vector.
// we can also use prev variable instead of storing all the values.
// inorder traversal
// int prev = INT_MIN;
bool isBST(Node *root, int& prev){
    if(!root) return true;
    if(!isBST(root->left, prev)) return false;
    if(root->val <= prev) return false;
    prev = root->val;
    return isBST(root->right, prev);
}
// fix the BST with two nodes swapped.
// there will be two cases
// if in inorder traversal there is only one voilation then we can swap them.
// if there are two voilations then we need to swap first from first voilation and second from second voilation.
// here we are just finding two nodes to be swapped.
void fixBST(Node *root, Node *prev = NULL, Node *first = NULL, Node *second = NULL){
    if(root==NULL) return;
    fixBST(root->left);
    if(prev!=NULL and root->val < prev->val){
        if(first == NULL){
            first = prev;
        }
        second = root;
    }
    prev = root;
    fixBST(root->right);
}
// pair with given sum
// method - 1
// do inorder traversal and store values vector
// use two pointer approach to find if vector as pair with given sum

// method - 2
// using hasing and inorder traveral(any traveral can be used)
// time complexity -> O(n)
bool isPairSum(Node *root, int sum, unordered_set<int>& s){
    if(!root) return root;
    if(isPairSum(root->left, sum, s) == true){
        return true;
    }
    if(s.find(sum - root->val)!=s.end()){
        return true;
    }else{
        s.insert(root->val);
    }
    return isPairSum(root->right, sum, s);

}

// vertical sum in a binary tree
// horizontal distance from node
// node at 0 hd left -ve right +ve
// for each hd print vertical sum

// we use map to store the values because it is ordered
// we can use any traversal.
// time complexity --> O(nloghd + hd) where hd is no. of total horizontal distances.
void vsumR(Node *root, int hd, map<int,int> &m){
    if(root!=NULL){
        vsumR(root->left, hd - 1, m);
        m[hd] += root->val;
        vsumR(root->right, hd + 1, m);
    }
}
void vSum(Node *root){
    map<int, int> m;
    vsumR(root, 0, m);
    for(auto sum : m){
        cout << sum.second << " ";
    }
    cout << endl;
}

// vertical Traversal for a binary tree
// print each node in vertical line at each hd such that it should be in same order as we traverse from top to bottom
// trick use queue(level order traversal)
void vTraversal(Node *root){
    map<int, vector<int>> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->val);
        if(curr->left){
            q.push({curr->left, hd - 1});
        }
        if(curr->right){
            q.push({curr->right, hd + 1});
        }
    }
    // print mp contents line by line
}
// print the top view of binary tree
// same as previous but add only one node for each hd. :)
void TopView(Node *root){
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* curr = p.first;
        int hd = p.second;
        if(mp.find(hd)==mp.end()){
            mp[hd] = curr->val;
        }
        if(curr->left){
            q.push({curr->left, hd - 1});
        }
        if(curr->right){
            q.push({curr->right, hd + 1});
        }
    }
}
// bottom view
// same as previous but update every time we get a val for hd.
void bottomView(Node *root){
     map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* curr = p.first;
        int hd = p.second;
        mp[hd] = curr->val;
        if(curr->left){
            q.push({curr->left, hd - 1});
        }
        if(curr->right){
            q.push({curr->right, hd + 1});
        }
    }
}
int main(){
    int count;
    int prev = NULL;
    return 0;
}