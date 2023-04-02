#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * pre;
    Node * nxt;

    Node(int data){
        this -> data = data;
        this -> nxt = NULL;
        this -> nxt = NULL;
    }
};

class Deque{
    public:
    int size;
    Node * head;
    Node * tail;

    Deque(){
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void push_back(int data){
        Node * newNode = new Node(data);
        if(size == 0){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail -> nxt = newNode;
        newNode -> pre = tail;
        tail = newNode;
        size++;
    }

    void push_front(int data){
        Node * newNode = new Node(data);
        if(size == 0){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        head -> pre = newNode;
        newNode -> nxt = head;
        head = newNode;
        size++;
    }
    void print(){
        Node * temp = head;

        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> nxt;
        }
        cout << endl;
    }
    void pop_back(){
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
        Node * temp = tail;
        tail = tail -> pre;
        delete temp;
        tail -> nxt = NULL;
        size--;
    }
    void pop_front(){
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
        head = head -> nxt;
        delete temp;
        head -> pre = NULL;
        size--;
    }
    int front(){
        if(size == 0){
            return -1;
        }
        return head -> data;
    }
    int back(){
        if(size == 0){
            return -1;
        }
        return tail -> data;
    }
    int getSize(){
        return size;
    }
};

int main(){
    Deque d;
    d.push_back(5);
    d.push_back(10);
    d.push_front(12);
    d.push_front(14);
    d.print();
    d.pop_back();
    d.print();
    d.pop_front();
    d.print();
    
}