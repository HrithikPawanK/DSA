#include<bits/stdc++.h>
using namespace std;
// Binary Heap Data Structure uses
// 1. used in heap sort
// 2. used to implement priority queues.
//    two types
//    1. min heap (highest priority item is assigned low value);
//    2. max heap (highest priority item is assigned high value);

// binary heap is complete binary tree
// complete binary tree --> all level as completely filled except possibly last level
// and in last level nodes should be filled from left to right.
// because : while representing binary heap array if tree is complete then there won't be gaps in between.(no extra space)
// advantage: random access, cache friendly, height will we min possible.

// generally heap is implemented as arrays but the actual logic is binary tree.

// left(i) = 2i + 1, right(i) = 2i + 2, parent(i) = floor((i-1)/2)

// Min Heap
// -->complete binary tree. -->Every node has value smaller than its descendants.

class MinHeap{
    public:
    int *arr;
    int capacity;
    int size;
    MinHeap(int c){
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int x){
        size++;
        arr[size-1] = x;
        for(int i = size - 1; i != 0 && arr[parent(i)] > arr[i];){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    // we are given the index where heap is voilating.
    // logic : we compary the min of left, right, root value if min is root no change if not swap
    // root with min value if left is min then call recursively for left 
    // if right is min then swap and call recursively for right
    // time complexity -->O(h) == O(log(size));
    void minHeapify(int i){
        int smallest = i;
        int lt = left(i);
        int rt = right(i);
        if(lt < size and arr[lt] < arr[smallest]){
            smallest = lt;
        }
        if(rt < size and arr[rt] < arr[smallest]){
            smallest = rt;
        }
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    // time complexity --> O(1)
    int getMin(){
        return arr[0];
    }
    // swap root with last element and delete last element i.e swap(arr[0], arr[size-1]), size--;
    // then do heapify on root; i.e minheapify(0);
    int ExtractMin(){
        if(size==0) return INT_MAX;
        if(size==1){
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    // change the key at given index and heapify.
    // same like insertion check for parent if parent greater then swap untill root.
    // time--> O(logn)
    void decreaseKey(int i, int x){
        arr[i] = x;
        while(i!=0 and arr[parent(i)] > arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    // delete a node and heapify
    // algo --> use decrease key fun by passing index ans value as -INF
    // now -INF reaches root
    // now call extract min

    // Build heap
    // we are given an array we need to build heap
    // algo: do heapify for all internal nodes from bottom to up till root;

    // time complexity --> O(n)
    void bulidHeap(){
        // size - 1 --> last element
        // (size - 1)/2 parent of last element;
        for(int i = (size - 1)/ 2; i >= 0; i--){
            minHeapify(i);
        }
    }
    // maximum nodes at height h = ceil(n/(2^h  +  1));
    // where leaf h = 0 
    
};

int main(){
    
    return 0;
}