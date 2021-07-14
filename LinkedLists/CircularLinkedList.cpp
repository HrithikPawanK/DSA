#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int x){
        val = x;
        next = NULL;
    }
};
void printList(Node *head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        cout << head->val << endl;
        return;
    }
    Node *curr = head;
    do{
        cout << curr->val << " ";
        curr = curr->next;
    }while(curr!=head);
    
}
Node *insertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }
    Node *curr = head;
    while(curr->next!=head){
        curr = curr->next;
    }
    temp->next = head;
    curr->next = temp;
    return temp;
}
// O(1) solution
// insert new node at second position and swap the data of 1 and 2 nodes
Node *insertAtBeginO1(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int var = head->val;
    head->val = temp->val;
    temp->val = var;
    return head;
}
// similar to previous
Node *insertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int var = head->val;
    head->val = temp->val;
    temp->val = var;
    // just change head to 2nd position
    return temp;
}
// copying values of 1 and 2 then deleting 2
Node *deleteHead(Node *head){
    if(head==NULL){
        return NULL;
    } 
    if(head->next == head){
        delete head;
        return NULL;
    }
    head->val = head->next->val;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}
// assuming k <= no. of nodes
Node *deleteKthNode(Node *head, int k){
    if(k==1){
        return deleteHead(head);
    }
    Node *curr = head;
    for(int i = 1; i < k-1; i++){
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
int main(){
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    head = insertAtBegin(head, 2);
    head = insertAtEnd(head,100);
    head = deleteHead(head);
    head = deleteHead(head);
    head = deleteKthNode(head,3);
    printList(head);
    return 0;
}