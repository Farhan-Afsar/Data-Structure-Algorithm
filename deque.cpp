#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node * prev;
    Node * next;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Deque{
        public:
        Node * head;
        Node * tail;
        int size;

        Deque(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void PUSH_BACK(int data){
            Node * NewNode = new Node(data);

            if(size == 0){
                head = NewNode;
                tail = NewNode;
                size++;
                return;
            }
            tail ->next = NewNode;
            NewNode -> prev = tail;
            tail = NewNode;
            size++;
        }
        int get_size(){
        return size;
        }

       void pop_back(){
            if(size == 0){
                cout << "Empty";
        }
            if(size ==1){
                Node * temp = head;
                head = NULL;
                tail = NULL;
                delete temp;
                size--;
                return;
        }
    }
};
int32_t main(){
    

    Deque dq;
    dq.PUSH_BACK(12);
    dq.PUSH_BACK(22);

    cout << dq.get_size() << endl;

}