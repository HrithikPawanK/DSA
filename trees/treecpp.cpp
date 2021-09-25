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
void inorder(Node *root){
    if(root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}
void preorder(Node *root){
    if(root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << endl;
    }
}
// considering height as number of nodes from root to leaf.
int height(Node *root){
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
// print k + 1 th level, k = 0 --> root
void printAtK(Node *root, int k){
    if(!root) return;
    if(k==0){
        cout << root->val << " ";
    }else{
        printAtK(root->left, k-1);
        printAtK(root->right, k-1);
    }
}
// auxilary space = O(width)
void levelOrder(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
void levelOrderLineByLine(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            Node *node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
}
int sizeOfTree(Node *root){
    if(!root) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}
int maximum(Node *root){
    if(!root) return INT_MIN;
    return max(root->val, max(maximum(root->left), maximum(root->right)));
}
// in preorder traversal we visit leftmost node of each level first.
int maxlevel = 0;
// method -1
void printLeft(Node *root, int level){
    if(!root) return;
    if(maxlevel < level){
        cout << root->val << " ";
        maxlevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}
// method -2
void printLeftIterative(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            Node *node = q.front();
            q.pop();
            if(i == 0) cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}
/*  
    child sum :- if both child are present then left + right should be equal to root;
    if only one child present then root should be equal to that child.
    if no child then its true.
*/
bool childSum(Node *root){
    if(!root) return true;
    if(!root->left and !root->right) return true; // leaf
    int sum = 0;
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    return (sum == root->val and childSum(root->left) and childSum(root->right));
}
// height balanced :- the difference b/w height of left and right is atmost 1.
int isbalanced(Node *root){
    if(!root) return 0;
    int left = isbalanced(root->left);
    if(left == -1) return -1;
    int right = isbalanced(root->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}
// max nodes present in any of the levels.
int maxWidth(Node *root){
    queue<Node *> q;
    q.push(root);
    int maxw = 0;
    while(!q.empty()){
        int s = q.size();
        maxw = max(maxw, s);
        for(int i = 0; i < s; i++){
            Node *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return maxw;
}
// covert binary tree to double linked list
// inorder to double linked list
/*
Node *prev = NULL;
Node *BTToDLL(Node *root){
    if(!root) return root;
    Node *head = BTToDLL(root->left);
    if(prev = NULL){
        head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}
*/
// construction tree from inorder and preorder
// time complexity: O(n^2)
// if we use hashing to find index for inorder then time complexity: O(n)
int preIndex = 0;
Node *constructTree(int in[], int pre[], int is, int ie){
    if(is > ie) return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for(int i = is; i <= ie; i++){
        if(in[i]==root->val){
            inIndex = i;
            break;
        }
    }
    root->left = constructTree(in, pre, is, inIndex - 1);
    root->right = constructTree(in, pre, inIndex + 1, ie);
    return root;
}
// traverse spiral
void printSpiral(Node *root){
    queue<Node*> q;
    stack<Node*> st;
    q.push(root);
    bool reverse = false;
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i < s; i++){
            Node* node = q.front();
            q.pop();
            if(reverse) st.push(node);
            else cout << node->val << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(reverse){
            while(!st.empty()){
                cout << st.top()->val << " ";
                st.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}
// method -2 using two stacks
void printSpiralEff(Node *root){
    stack<Node *> s1, s2;
    s1.push(root);
    while(!s1.empty() or !s2.empty()){
        while(!s1.empty()){
            Node *node = s1.top();
            s1.pop();
            cout << node->val << " ";
            if(node->left){
                s2.push(node->left);
            }
            if(node->right){
                s2.push(node->right);
            }
        }
        cout << endl;
        while(!s2.empty()){
            Node *node = s2.top();
            s2.pop();
            cout << node->val << " ";
            // push in reverse order
            if(node->right){
                s1.push(node->right);
            }
            if(node->left){
                s1.push(node->left);
            }
        }
        cout << endl;
    }
}
// Diameter: Longest path b/w any two leafs
int diameter(Node *root, int &d){
    if(!root) return 0;
    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);
    d = max(d, 1 + lh + rh);
    return 1 + max(lh, rh);
}
// lowest common ancestor
// naive 
// find two paths then find common last common element in two paths
// given root, n1, n2;

bool findPath(Node *root, vector<Node*> &p, int n){
    if(root==NULL){
        return false;
    }
    p.push_back(root);
    if(root->val == n){
        return true;
    }
    if(findPath(root->left, p, n) || findPath(root->right, p, n)){
        return true;
    }
    p.pop_back();
    return false;
}
Node *lCA(Node *root, int n1, int n2){
    vector<Node*> p1, p2;
    if(findPath(root, p1, n1) == false or findPath(root, p2, n2) == false){
        return NULL;
    }
    for(int i = 0; i < p1.size() and i < p2.size(); i++){
        if(p1[i+1]!=p2[i+1]){
            return p1[i];
        }
    }
    return NULL;
}

// lcs efficient solution one traversal
// assuming both n1 and n2 are present
Node *LCAeff(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->val == n1 or root->val == n2){
        return root;
    }
    Node *lcs1 = LCAeff(root->left, n1, n2);
    Node *lcs2 = LCAeff(root->right, n1, n2);
    if(lcs1 != NULL and lcs2 != NULL){
        return root;
    }
    if(lcs1!=NULL){
        return lcs1;
    }else{
        return lcs2;
    }
}
// just find the farthest node from given leaf.
int BurnFromLeaf(Node *leaf){

}

// iterative preorder
// logic : we use stack and insert right first then left.
void preorderIter(Node *root){
    if(!root) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        cout << node->val << " ";
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}
// logic : if node is not null, insert in stack and check for left, if left is null then pop from stack and print then check right.
void inorderIter(Node* root){
    if(!root) return;
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout << node->val << " ";
            node = node->right;
        }
    }
}

// using two stacks
// logic : for every node pop and insert to stack2, insert its left and right to stack1
// finally pop stack2 to get the result.
void postOrderIter(Node* root){
    if(root == NULL) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right); 
    }
    while(!s2.empty()){
        Node* node = s2.top();
        s2.pop();
        cout << node->val << " ";
    }
    cout << endl;
}

// postorder using one stack
void postOrderIterEff(Node* root){
    if(root == NULL) return;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    inorderIter(root);
    cout << endl;
    printAtK(root, 1);
    cout << endl;
    levelOrder(root);
    cout << endl;
    levelOrderLineByLine(root);
    cout << sizeOfTree(root) << endl;
    cout << maximum(root) << endl;
    printLeft(root, 1);
    cout << endl;
    printLeftIterative(root);
    cout << endl;
    if(isbalanced(root) != -1) cout << "balanced" << endl;
    else cout << "not balanced" << endl;
    cout << maxWidth(root) << endl;
    printSpiral(root);
    printSpiralEff(root);
    int d = 0;
    diameter(root, d);
    cout << d << endl;
    return 0;
}