#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Queue{
    public:
    Node * head ;
    Node * tail ;
    int size;

    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int data){
        Node * newNode = new Node (data);
        size++;
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }

    void dequeue(){
        if(size == 0){
            cout << "Empty";
            return;
        }
        if(size == 1){
            delete head;
            head = NULL;
            tail = NULL;
            size--;
            return;
        }
        Node * temp = head;
        head = head -> next;
        delete temp;
        size--;
    }

    int front(){
        if(size == 0){
            cout << "Empty";
            return -1;
        }
        return head -> data;
    }

    int Size(){
        return size;
    }

};
int main(){
    Queue a;
    a.enqueue(5);
    a.enqueue(10);
    a.enqueue(15);

    cout << a.front() << endl;

    a.dequeue();
    cout<< a.front() << endl;
    
}