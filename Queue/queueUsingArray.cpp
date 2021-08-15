#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    int *arr, front, rear, size, cap;
    Queue(int c){
        cap = c;
        arr = new int[cap];
        front = rear = -1;
        size = 0;
    }
    void enqueue(int x){
        if(isFull()) return;
        if(front == -1){
            front = rear = 0;
            arr[rear] = x; 
        }else{
            rear = (rear + 1)%cap;
            arr[rear] = x;
        }
        size++;
    }
    int dequeue(){
        if(isEmpty()) return -1;
        int res;
        res = arr[front];
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1)%cap;
        }
        size--;
        return res;
    }
    bool isFull(){
        return (cap == size);
    }
    bool isEmpty(){
        return (size == 0);
    }
    int getFront(){
        if(isEmpty()) return -1;
        else return arr[front];
    }
    int getRear(){
        if(isEmpty()) return -1;
        else return arr[rear];
    }
};
int main(){
    Queue q(10);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(18);
    q.enqueue(10);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(18);
    q.enqueue(10);
    q.enqueue(11);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}