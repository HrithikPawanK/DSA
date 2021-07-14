#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node *head){
    // we can use head directly because when we pass a pointer to fun new pointer will be created
    // so there will be no change in main head.
    Node *curr = head;
    while(curr!=NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
}
void printListRec(Node *head){
    if(head==NULL){
        return;
    }
    cout << head->data << " ";
    printListRec(head->next);
}
Node* InsertAtBeginning(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}
Node* InsertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        return temp;
    }
    Node *curr = head;  
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
Node *DeleteFirstNode(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;
}
Node *delTail(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
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
Node *InsertPos(Node *head, int pos, int data){
    //considering position starting with 1 not 0
    // logic go to pos-1 for curr 
    Node *temp = new Node(data);
    if(pos==1){
        temp->next = head;
        return temp;
    } 
    Node *curr = head;
    for(int i = 1; i <= pos-2 && curr!=NULL; i++){
        curr = curr->next;
    }
    if(curr==NULL){
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int Search(Node *head, int key){
    int idx = 1;
    while(head!=NULL){
        if(head->data==key){
            return idx;
        }
        idx++;
        head = head->next;
    }
    return -1;
}
int SearchRec(Node *head, int key){
    if(head==NULL){
        return -1;
    }
    if(head->data == key){
        return 1;
    }
    int res = SearchRec(head->next, key);
    if(res==-1){
        return -1;
    }else{
        return res + 1;
    }
}
// we are give linked list in ascending order we need to insert new node in its correct position
Node *sortedInsert(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL){
        return temp;
    }
    if(x < head->data){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    while(curr->next and curr->next->data < temp->data){
        curr = curr->next;
    }
    if(curr->next==NULL){
        curr->next = temp;
    }else{
        temp->next = curr->next;
        curr->next = temp;
    }
    return head;
}

void printMiddleElement(Node *head){
    if(head==NULL) return;
    Node *fast, *slow;
    fast = slow = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

// print nth node from end of linked list
void printNthFromEnd(Node *head, int n){
    int c = 0;
    Node *curr = head;
    while(curr!=NULL){
        curr = curr->next;
        c++;
    }
    int f = c - n + 1;
    if(f <= 0){
        return;
    }
    else{
        curr = head;
        for(int i = 1; i < f; i++){
            curr = curr->next;
        }
        cout << curr->data << endl;
    }
}
//method 2
// using two pointers first and second
// move first n positions then start second from head and move both each step untill fast reaches null
// then print the second pointer value
void printNthFromEndTwoPointer(Node *head, int n){
    if(head==NULL) return;
    Node *first, *second;
    first = second = head;
    for(int i = 0; i < n; i++){
        if(first==NULL){
            return;
        }
        first = first->next;
    }
    while(first!=NULL){
        first = first->next;
        second = second->next;
    }
    cout << second->data << endl;
}
Node *Reverse(Node *head){
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    Node *prev, *curr;
    curr = head;
    prev = NULL;
    Node *next;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//method 1
Node* ReverseRec(Node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node *rest_head = ReverseRec(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}
// remove duplicates in sorted linked list
void removeDupSortList(Node *head){
    if(head==NULL or head->next==NULL){
        return;
    }
    Node *prev = head;
    Node *curr = head->next;
    while(curr!=NULL){
        if(curr->data==prev->data){
            Node *next = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}
//Reverse each group of size k
Node *RevInKGroups(Node *head, int k){
    Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;
    while(curr!=NULL){
        int count = 0;
        Node *first = curr, *prev = NULL;
        while(curr!=NULL and count < k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass){
            head = prev;
            isFirstPass = false;
        }
        else{
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}
//recursive
Node *reverseKRecur(Node *head,int k){
    Node *curr=head,*next=NULL,*prev=NULL;
    int count=0;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        Node *rest_head=reverseKRecur(next,k);
        head->next=rest_head;
    }
    return prev;
}
bool DetectLoopHashing(Node *head){
    unordered_set<Node *> s;
    Node *curr = head;
    while(curr!=NULL){
        if(s.find(curr)==s.end()){
            s.insert(curr);
        }else{
            return true;
        }
    }
    return false;
}
// floyd's cycle detection
// using slow and fast pointer
/* let the distance between slow and fast be k when slow enters loop then for each step distance increases distance between them increase by 1
   i.e k = k + 1 there will be a situation when k becomes length of loop which implies they point to same node */
/* time complexity = O(m + n) where m is lenght of before loop and n is loop length */
// finally time complexity = O(n) where n is lenth of linked list
bool isLoop(Node *head){
    Node *slow = head, *fast = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
/*
    1. detect cycle using floyd cycle detection algorithm.
    2. move slow pointer to begining and keep fast pointer at meeting position which is found using step1.
    3. now move slow and fast one step each at a time and the point at which they collide is the start of cycle.
*/
void detectAndRemoveLoop(Node *head){
    Node *fast = head, *slow = head;
    while(fast!=NULL and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
    if(fast!=slow){
        return;
    }
    slow = head;
    // actuall fast and slow meet at starting of loop using fast->next and slow->next we will have the past pointer
    // so fast stops at last node.
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}
// delete node when only pointer to that node is given
// trick just copy the data of next and delete the next node
void deleteGivenNode(Node *node){
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete(temp);
}
// segregate even and odd keeping even first then odd preserving the relative order
Node *segregate(Node *head){
    Node *eS, *eE, *oS, *oE; // evenStart, evenEnd, oddStart, oddEnd
    eS = eE = oS = oE = NULL;
    for(Node *curr = head; curr!=NULL; curr = curr->next){
        int x = curr->data;
        if(x%2==0){
            if(eS==NULL){
                eS = curr;
                eE = eS;
            }
            else{
                eE->next = curr;
                eE = eE->next;
            }
        }else{
            if(oS==NULL){
                oS = curr;
                oE = oS;
            }else{
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if(oS == NULL or eS == NULL){
        return head;    
    }
    eE->next = oS;
    oE->next = NULL;
    return eS;
}
// intersection point of two nodes
// trick traverse both the lists and count each list lengths
// then traverse the higher length list from its head by d(which is difference between lengths)
// then for another list start from and for the previous list continue from that point
// traverse one by one step for both and check if they collide.
int getIntersection(Node *h1, Node *h2){
    int c1 = 0, c2 = 0;
    Node *curr = h1;
    while(curr!=NULL){
        c1++;
        curr = curr->next;
    }
    curr = h2;
    while(curr!=NULL){
        c2++;
        curr = curr->next;
    }
    int d = abs(c1-c2);
    Node *curr1 = h1, *curr2 = h2;
    if(c1 > c2){
        while(d){
            curr1 = curr1->next;
            d--;
        }
    }else{
        while(d){
            curr2 = curr2->next;
            d--;
        }
    }
    while(curr1!=NULL and curr2!=NULL){
        if(curr1 == curr2){
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
}
void pairwiseSwap(Node *head){
    Node *curr = head;
    while(curr!=NULL and curr->next!=NULL){
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}
int main(){
    Node *head=new Node(17);
	head->next=new Node(15);
	head->next->next=new Node(8);
	head->next->next->next=new Node(12);
	head->next->next->next->next=new Node(10);
	head->next->next->next->next->next=new Node(5);
	head->next->next->next->next->next->next=new Node(4);
    head->next->next->next->next->next->next->next = NULL;
    printList(head);
    cout << endl;
    pairwiseSwap(head);
    printList(head);
    return 0;
}