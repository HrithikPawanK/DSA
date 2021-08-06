#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};
class MyStack{
    public:
    Node *head;
    int sz;
    MyStack(){
        head = NULL;
        sz = 0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop(){
        if(!head) return INT_MAX;
        int res = head->val;
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int peak(){
        if(head==NULL) return INT_MAX;
        return head->val;
    }
};
int main(){
    
    return 0;
}