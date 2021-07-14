#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*----------------------------------------------------------------------------------------------------*/
struct MyHash{
    int *arr;
    int cap, size = 0;
    MyHash(int c){
        cap = c;
        for(int i = 0; i < cap; i++){
            arr[i] = -1;
        }
    }
    int hash(int key){
        return key%cap;
    }
    bool search(int key){
        int h = hash(key);
        int i = h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                return true;
            }
            i = (i+1)%cap;
            if(i==h){
                return false;
            }
        }
        return false;
    }
    bool insert(int key){
        if(size==cap){
            return false;
        }
        int h = hash(key);
        int i = h;
        while(arr[i]!=-1 and arr[i]!=-2 and arr[i]!=key){
            i = (i+1)%cap;
        }
        if(arr[i]==key){
            return false;
        }else{
            arr[i] = key;
            size++;
            return true;
        }
        return false;
    }
    bool erase(int key){
        int h = hash(key);
        int i = h;
        while(arr[i]!=-1){
            if(arr[i]==key){
                arr[i] = -2;
                return true;
            }
            i = (i+1)%cap;
            if(i==h){
                return false;
            }
        }
        return false;
    }
};
int main(){
    MyHash myhash = MyHash(3);
    cout << myhash.insert(10) << endl;
    cout << myhash.insert(11) << endl;
    cout << myhash.erase(10) << endl;
    cout << myhash.search(10) << endl;
    return 0;
}