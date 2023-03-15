#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define Faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
        int data;
        Node * prev;
        Node * next;

        Node(int data){
            this -> data = data;
            prev = NULL;
            next = NULL;
        }
};

class Stack{
        Node * head;
        Node * top;
        int size = 0;

    public:
        Stack(){
            head = NULL;
            top = NULL;
        }
    void push(int data){
        size++;
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            top = newNode;
            return;
        }
        top -> next = newNode;
        newNode -> prev = top;
        top = newNode;
    }

    void POP(){
        Node * delNode = top;
        if(head == top){
            head = top = NULL;
        }
        else{
            top = delNode -> prev;
            top -> next = NULL;

        }
        delete delNode;
        size--;
    }

    int TOP(){
        return top -> data;
    }

    bool empty(){
          if(size == 0)  return true;

          return false; 
    }

    int get_size(){
        return size;
    }
};

int32_t main(){
    Faster;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // cout << s.TOP() << endl;
    // s.POP();
    // cout << s.TOP();

    while(s.empty() == false){
        cout << s.TOP() << " ";
        s.POP();
    }
}