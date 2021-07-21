#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void preorder(struct Node *root){
    if(root!=NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int height(struct Node *root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
}
void distk(struct Node *root,int k){
    if(root == NULL){
        return;
    }else if(k==0){
        cout << root->key << " ";
    }else{
        distk(root->left,k-1);
        distk(root->right,k-1);
    }
}
void levelOrder(struct Node *root){
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        Node *cur = q.front();
        q.pop();
        cout << cur->key << " ";
        if(cur->left != NULL){
            q.push(cur->left);
        }
        if(cur->right != NULL){
            q.push(cur->right);
        }
    }
}
void levelOrderLineByLine(struct Node *root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node *cur = q.front();
        q.pop();
        if(cur==NULL){
            cout << endl;
            q.push(NULL);
        }else{
            cout << cur->key << " ";
            if(cur->left != NULL){
                q.push(cur->left);
            }
            if(cur->right!=NULL){
                q.push(cur->right);
            }
        }
    }
}
void levelOrderLineByLine2(Node *root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i = 0; i < count; i++){
            Node *cur = q.front();
            q.pop();
            cout << cur->key << " ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout << endl;
    }
}
int treeSize(Node *root){
    if(root==NULL) return 0;
    return 1 + treeSize(root->left) + treeSize(root->right);
}
int maxValue(Node *root){
    if(root==NULL) return INT_MIN;
    return max(root->key,max(maxValue(root->left),maxValue(root->right)));
}

// printing leftview of tree
// preorder traversal will print left most node of each level first
// so we use preorder technique
// we use maxLevel as global and for each level we print first node using maxLevel and level variable.
// recursive 
int maxLevel = 0;
void printLeft(Node *root, int level){
    if(root==NULL){
        return;
    }
    if(maxLevel < level){
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level+1);
    printLeft(root->right, level+1);
}
void printLeftView(Node *root){
    printLeft(root, 1);
}
// iterative
// similar to printing level by level
void printLeftViewIterative(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root) ;
    while(q.empty()!=true){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node *node = q.front();
            q.pop();
            if(i==0){ // only printing first element of each level
                cout << node->key << " ";
            }
            if(root->left){
                q.push(node->left);
            }
            if(root->right){
                q.push(node->right);
            }
        }
    }   
}
// child sum means left child + right child = root val 
// if there's only one child then consider only one
// if there's no child i.e leaf then consider it as true
bool isChildrenSum(Node *root){
    if(root==NULL){
        return true;
    }
    if(root->left == NULL and root->right == NULL){
        return true;
    }
    int sum = 0;
    if(root->left != NULL){
        sum += root->left->key;
    }
    if(root->right != NULL){
        sum += root->right->key;
    }
    return (sum == root->key and isChildrenSum(root->left) and isChildrenSum(root->right));
}

// check for balanced tree
// balanced tree means differences of left subtree height and right subtree height should be atmost 1.
// first check left if satisfies then check right
// if it does not satisfy return -1 else return height
int isBalanced(Node *root){
    if(root == NULL) return 0;
    int lh = isBalanced(root->left);
    if(lh==-1) return -1;
    int rh = isBalanced(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1){
        return -1;
    }
    return max(lh,rh) + 1;
}

// maxwidth means maximum number of elements present in some level.
// using level order traversal we can do.
int maxWidth(Node *root){
    if(root==NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int maxwidth = INT_MIN;
    while(q.empty()!=true){
        int size = q.size();
        maxwidth = max(maxwidth, size);
        for(int i = 0; i < size; i++){
            Node *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(root->right);
            }
        }
    }
    return maxwidth;
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
    if(root->key == n){
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
    if(root->key == n1 or root->key == n2){
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
int main(){
    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(45);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    Node *lcs = lCA(root, 50, 60);
    cout << lcs->key << endl;
    return 0;
}