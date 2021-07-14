#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node *prev;
    Node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};
Node *insertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    temp->next = head;
    return temp;
}
void printlist(Node *head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        cout << head->val << endl;
        return;
    }
    Node *curr = head;
    do{
        cout << curr->val << endl;
        curr = curr->next;
    }while(curr!=head);
}
int main(){
    Node *head = NULL;
    head = insertAtBegin(head,10);
    head = insertAtBegin(head,20);
    head = insertAtBegin(head,30);
    printlist(head);
    return 0;
}