#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define ln "\n" 
using namespace std;

// idea of linking two non-contiguous memory locations(nodes)
// unlimited size

class Node{     // user defined datatype
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{  // user defined data structure
 
    public:
    int size;
    Node* head;
    Node* tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertAtEnd(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=temp;
            tail=temp;
        }
        else {
            tail->next=temp;
            tail=tail->next;
            temp->next=NULL;
        }
        size++;
    }
    void insertAtBegin(int val){
        Node* temp=new Node(val);
        if(size==0){
         head=temp;
         tail=temp;
         tail->next=NULL;
        }
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertAtPos(int pos,int val){
        if(pos==0) insertAtBegin(val);            
        if(pos==size) insertAtEnd(val);       
       Node* newnode=new Node(val);
       Node* temp=head;
       while(pos>1){
          temp=temp->next; pos--;
       }
       newnode->next=temp->next;
       temp->next=newnode;
       size++;
    }
    
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<ln;
    }
};





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // -> pointer object; . use for normal object  *(ptr).name==ptr->name
       
    // Node* a= new Node(10);
    // Node* b=new Node(20);           
    // Node* c =new Node(30);
    // a->next=b;
    // b->next=c;
    // display(a);
    // cout<<ln;           

    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtEnd(40);
    ll.display();
    ll.insertAtBegin(5);
    ll.display();
    ll.insertAtBegin(2);
    ll.display();
    ll.insertAtBegin(1);
    ll.display();
    ll.insertAtPos(2,8);
    ll.display();
    cout<<ll.size<<ln;
       



    
    return 0;
}

