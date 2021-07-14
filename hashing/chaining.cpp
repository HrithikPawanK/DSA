#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
struct MyHash{
    int BUCKET;
    list<int> *table;
    MyHash(int b){
        BUCKET = b;
        table = new list<int>[b];
    }
    void insert(int key){
        int i = key%BUCKET;
        table[i].push_back(key);
    }
    void remove(int key){
        int i = key%BUCKET;
        table[i].remove(key);
    }
    bool search(int key){
        int i = key%BUCKET;
        for(auto x:table[i]){
            if(x==key){
                return true;
            }
        }
        return false;
    }
};
int main(){
    MyHash h = MyHash(7);
    h.insert(10);
    h.insert(11);
    h.insert(12);
    h.insert(3);
    cout << h.search(10) << endl;
    h.remove(10);
    cout << h.search(10) << endl;
    return 0;
}