#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
        int data;
        Node * next; 
    
    Node(int data){
        this -> data = data;
        this-> next = NULL;
    }
};

class linked_list{
    public:
    Node * head;

    linked_list(){
        head = NULL;
    }

    void insetHead(int data){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode -> next = head;
        head = newNode;
    }

    void traverse(){
        Node * temp = head;

        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }

    int searchDistinctValue(int data){
        Node * temp = head;
        int index = 0;

        while(temp != NULL){
            if(temp -> data == data){
                    return index;
            }
            temp = temp -> next;
            index++;
        }
        return -1;
    }
};
int32_t main(){
    Faster;
    linked_list l;

    l.insetHead(10);
    l.insetHead(20);
    l.insetHead(30);
    l.insetHead(40);
    l.insetHead(59);

    l.traverse();
    cout << endl;
    cout << l.searchDistinctValue(10);
}