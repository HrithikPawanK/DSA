#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
void printList(Node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *insertAtBegin(Node *head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    if(head!=NULL){
        head->prev = temp;
    }
    return temp;
}  
Node *insertAtEnd(Node *head, int data){
    Node *temp = new Node(data);
    if(head==NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}
Node* reverse(Node *head){
    if(head==NULL or head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
Node* deleteHead(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}
Node *deleteTail(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}
int main(){
    Node * head = new Node(10);
    Node * temp1 = new Node(20);
    Node * temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = reverse(head);
    head = insertAtBegin(head,2);
    printList(head);
    return 0;
}