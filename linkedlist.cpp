#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

void print(Node* &head){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next;
        }
}

void insert_head(Node* head,int data){
        Node * newNode = new Node(data);

        newNode->next = head;
        head = newNode;

}

void insert_tail(Node* &head, int data){
        Node* newNode = new Node(data);
        Node * temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
}
int32_t main(){
    Faster;
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    
    a->next = b;
    b->next = c;

    // cout << a->value << " " << a->next->value << " "<< a->next->next->value << endl;
    insert_head(a,50);
    insert_tail(a,100);
    print(a);
}
