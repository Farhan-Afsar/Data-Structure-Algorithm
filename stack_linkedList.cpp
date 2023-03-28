#include<bits/stdc++.h>
using namespace std;

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
class doubly_linked_list{
    public:
        Node* head;
        int size;
    doubly_linked_list(){
        head = NULL;
        size = 0;
    }
    void insertAnyIndex(int data,int index){
        Node * newNode = new Node(data);
        if(index < 0 || index > size)
            return;
        size++;
        if(head == NULL){
            head = newNode;
            return;
        }
        Node * temp = head;
        int cur_indx = 0;
        while(cur_indx != index -1){
            cur_indx++;
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        newNode -> pre = temp;
        Node * temp2 = temp -> next;
        temp2 -> pre = newNode;
        temp -> next = newNode;

    }
    void DeleteAtHead()
    {
        if(head== NULL)
        {
            return;
        }
        Node *a = head;
        Node *b = head->next;
        delete a;
        if(b!= NULL)
        {
            b->pre = NULL;
        }
        head= b;
        size--;
    }
    void insertHead(int data){
        Node * newNode = new Node(data);
        size++;
        if(head == NULL){
            head = newNode;
            return;
        }
        head -> pre = newNode ;
        newNode -> next = head ;
        head = newNode;

    }
    void traverse(){
        cout << endl;
        Node * temp = head;
        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
     void deleteIndex(int index){
        Node * temp = head;
        int cur_indx = 0;

        while(cur_indx != index ){
            cur_indx++;
            temp = temp -> next;
        }
        Node * temp1 = temp -> pre;
        Node * temp2 = temp -> next;
        if(temp1 != NULL){
            temp1 -> next = temp2;
        }
        if(temp2 != NULL){
             temp2 -> pre = temp1;
        }

        delete temp;
        if(index == 0){
            head = temp2;
        }
        size--;
    }
    void reverse(){
        Node * temp = head;
        Node * temp2 = head;
        int cur_indx = 0;
        if(head == NULL)
            return;
        while(cur_indx != size - 1){
            temp = temp -> next;
            cur_indx++;
        }
        while(temp2 != NULL){
            swap(temp2 -> next, temp2 -> pre);
            temp2 = temp2 -> pre;
        }
        head = temp;
    }
   
};

class Stack{
    public:
    doubly_linked_list dl;
    Stack(){

    }
    int top(){
        if(dl.getSize() == 0){
            return -1;
        }
        return dl.head -> data;
    }

    void push(int data){
        dl.insertHead(data);
    }
    void pop(){
        if(dl.getSize() == 0){
            return;
        }
        dl.DeleteAtHead();
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    
}