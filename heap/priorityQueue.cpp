#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    int age;
    float ht;
    Person(int a, float h){
        age = a;
        ht = h;
    }
};
struct myCmp{
    bool operator() (Person const &p1, Person const &p2){
        return p1.ht < p2.ht;
    }
};
int main(){
    // by default priority queue is max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(50);
    pq.push(13);
    cout << pq.top() << endl; // top() to get the root element(Max).
    cout << pq.size() << endl;
    cout << pq.empty() << endl;
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop(); // for poping elements
    }

    // for min heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    // or make every element as negative and simply use max heap.
    pq1.push(10);
    pq1.push(50);
    pq1.push(13);
    while(!pq1.empty()){
        cout << pq1.top() << endl;
        pq1.pop(); // for poping elements
    }
    // we can implement priority queue from given arr or vector.
    int arr[3] = {1, 2, 3};
    vector<int> v(3);
    priority_queue<int> pq2(arr, arr + 3); // O(n) --> efficient way.
    while(!pq2.empty()){
        cout << pq2.top() << endl;
        pq2.pop(); // for poping elements
    }
    // ** pop, push are O(logn) remaining all O(1).
    

    // for pair of element default priority is given to first element

    // for custom datatype
    priority_queue<Person, vector<Person>, myCmp> pq3;
    Person p1(18, 170);
    Person p2(10, 153);
    Person p3(12, 190);
    pq3.push(p1);
    pq3.push(p2);
    pq3.push(p3);
    while(!pq3.empty()){
        cout << pq3.top().ht << endl;
        pq3.pop();
    }
    return 0;
}   