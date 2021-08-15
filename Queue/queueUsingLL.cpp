#include<bits/stdc++.h>
using namespace std;
struct LLNode{
    int val;
    LLNode* next;
    LLNode(int x){
        val = x;
        next = NULL;
    }
};
class Queue{
    public:
    LLNode *front, *rear;
    Queue(){
        front = rear = NULL;
    }
    void enqueue(int x){
        LLNode* node = new LLNode(x);
        if(front == NULL){
            front = rear = node;
        }else{
            rear->next = node;
            rear = node;
        }
    }
    int dequeue(){
        if(isEmpty()) return INT_MAX;
        int res = front->val;
        if(front == rear){
            rear = front = NULL;
        }
        else{
            LLNode* temp = front;
            front = front->next;
            delete temp;
        }
        return res;
    }
    bool isEmpty(){
        return (front == NULL);
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}