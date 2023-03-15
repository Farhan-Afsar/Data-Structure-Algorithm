#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
        int data;
        Node* pre;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }

};

void display(Node * &head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
int32_t main(){
    Faster;
    
    Node * a = new Node(10);
    Node * b = new Node(20);
    Node * c = new Node(30);

    a->next = b;
    b->next = c;

    display(a);
    
}